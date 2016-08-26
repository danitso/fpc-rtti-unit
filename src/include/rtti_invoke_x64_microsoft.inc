/// <summary> Dynamically invokes a method </summary>
function Invoke(ACodeAddress: Pointer; const AArgs: TValueArray;
  ACallingConvention: TCallConv; AResultType: PTypeInfo; AIsStatic: Boolean;
  AIsConstructor: Boolean): TValue;
const
  SHADOW_SPACE = 32;
var
  // Default
  Addr          : Pointer;
  ChunkCount    : Integer;
  I             : Integer;
  MaxIndex      : Integer;
  RegisterIndex : Integer;
  ResultType    : PTypeInfo;
  Stack         : TBytes;
  StackIndex    : Integer;

  // Registers
  RRAX          : NativeUInt;
  RRCX          : NativeUInt;
  RRDX          : NativeUInt;
  RR8           : NativeUInt;
  RR9           : NativeUInt;
  RXMM0         : Extended;
  RXMM1         : Extended;
  RXMM2         : Extended;
  RXMM3         : Extended;

/// <summary> Pushes a value into a register or onto the stack </summary>
procedure Push(var AValue: TValue); inline;
var
  ChunkIndex: Integer;
begin
  // Determine what type of register to place the value in.
  case AValue.TypeInfo^.Kind of
    tkFloat:
    begin
      // Place the value in the next available floating point register.
      if (RegisterIndex < 4) then
      begin
        case RegisterIndex of
          0: Move(AValue.GetReferenceToRawData^, RXMM0, AValue.DataSize);
          1: Move(AValue.GetReferenceToRawData^, RXMM1, AValue.DataSize);
          2: Move(AValue.GetReferenceToRawData^, RXMM2, AValue.DataSize);
          3: Move(AValue.GetReferenceToRawData^, RXMM3, AValue.DataSize);
        end;

        Inc(RegisterIndex);
        Exit;
      end;
    end;
  else
    // Place the value in the next available integer register.
    if (RegisterIndex < 4) then
    begin
      case RegisterIndex of
        0: Move(AValue.GetReferenceToRawData^, RRCX, AValue.DataSize);
        1: Move(AValue.GetReferenceToRawData^, RRDX, AValue.DataSize);
        2: Move(AValue.GetReferenceToRawData^, RR8, AValue.DataSize);
        3: Move(AValue.GetReferenceToRawData^, RR9, AValue.DataSize);
      end;

      Inc(RegisterIndex);
      Exit;
    end;
  end;

  // Push the value onto the stack in case we have run out of registers.
  ChunkCount := (AValue.DataSize + (AValue.DataSize mod 8)) div 8;

  for ChunkIndex := 0 to ChunkCount - 1 do
  begin
    Move(Pointer(AValue.GetReferenceToRawData + (SizeOf(RRCX) * ChunkIndex))^,
      Stack[StackIndex], AValue.DataSize - (SizeOf(RRCX) * ChunkIndex));
    Inc(StackIndex, SizeOf(RRCX));
  end;
end;
begin
  // Copy the arguments to local variables as we are going to modify the
  // registers they are stored in.
  Addr := ACodeAddress;
  ResultType := AResultType;

  // Initialize the local variables as we may forget to do this later.
  ChunkCount := 0;
  RegisterIndex := 0;
  StackIndex := 0;

  RRAX  := 0;
  RRCX  := 0;
  RRDX  := 0;
  RR8   := 0;
  RR9   := 0;

  RXMM0 := 0;
  RXMM1 := 0;
  RXMM2 := 0;
  RXMM3 := 0;

  // Initialize the stack.
  for I := 4 to High(AArgs) do
  begin
    Inc(ChunkCount, (AArgs[I].DataSize + (AArgs[I].DataSize mod 8)) div 8);
  end;

  if (ChunkCount mod 2 <> 0) then
  begin
    Inc(ChunkCount);
    Inc(StackIndex, SizeOf(RRCX));
  end;

  SetLength(Stack, (SizeOf(RRCX) * ChunkCount));

  // Place as many values in registers as possible.
  if (Length(AArgs) < 4) then
  begin
    MaxIndex := High(AArgs);
  end
  else
  begin
    MaxIndex := 3;
  end;

  for I := 0 to MaxIndex do
  begin
    Push(AArgs[I]);
  end;

  // Place the remaining values on the stack.
  for I := High(AArgs) downto 4 do
  begin
    Push(AArgs[I]);
  end;

  // Initialize the result in case one is expected.
  if Assigned(ResultType) then
  begin
    Result.Create(ResultType);

    if IsManaged(ResultType) then
    begin
      Push(Result);
    end;
  end;

  // Push the contents of the stack array onto the real stack. This cannot be
  // done directly in the Push() method as FPC does not support asm blocks in
  // inline methods.
  for I := 0 to (Length(Stack) div SizeOf(RRAX)) - 1 do
  begin
    Move(Stack[I * SizeOf(RRAX)], RRAX, SizeOf(RRAX));

    asm
      PUSH       RRAX
    end;
  end;

  // Change the registers, invoke the code and retrieve the result.
  asm
    MOV          rcx, RRCX
    MOV          rdx, RRDX
    MOV          r8, RR8
    MOV          r9, RR9

    MOVLPD       xmm0, RXMM0
    MOVLPD       xmm1, RXMM1
    MOVLPD       xmm2, RXMM2
    MOVLPD       xmm3, RXMM3

    SUB          rsp, SHADOW_SPACE
    CALL         Addr
    ADD          rsp, SHADOW_SPACE

    MOV          RRAX, rax
    MOVLPD       RXMM0, xmm0
  end;

  // Finalize the result in case the code is expected to return something.
  if Assigned(ResultType) then
  begin
    FinalizeResult(Result, RRAX, RRDX, RXMM0);
  end;
end;
