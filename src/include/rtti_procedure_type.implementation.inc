/// <summary> Constructs a new instance of the class </summary>
constructor TRttiProcedureType.Create(const ATypeInfo: PTypeInfo;
  const AParent: TRttiObject = Nil);
var
  I: Integer;
  P: PProcedureParam;
begin
  // Invoke the parent constructor.
  inherited;

  // Initialize the fields.
  FCallingConvention := FTypeData^.ProcSig.CC;

  if Assigned(FTypeData^.ProcSig.ResultType) then
  begin
    FReturnType := TRttiContext.Create.GetType(FTypeData^.ProcSig.ResultType);
  end;

  SetLength(FParameters, FTypeData^.ProcSig.ParamCount);

  for I := 0 to High(FParameters) do
  begin
    P := FTypeData^.ProcSig.GetParam(I);
    FParameters[I] := TRttiParameter.Create(Self, String(P^.Name),
      TParamFlags(P^.Flags), P^.ParamType);
  end;
end;

/// <summary> Returns a list of attributes associated with the procedural type
/// </summary>
function TRttiProcedureType.GetAttributes: TCustomAttributeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Invokes the procedure </summary>
function TRttiProcedureType.Invoke(const Callable: TValue;
  const Args: array of TValue): TValue;
var
  CodeAddress : Pointer;
  ResultType  : PTypeInfo;
begin
  // Retrieve the type information pointer for the return type.
  if Assigned(FReturnType) then
    ResultType := FReturnType.Handle
  else
    ResultType := Nil;

  // Retrieve the code address from the Callable argument.
  {$HINTS OFF}
  {$IFDEF CPU64}
    CodeAddress := Pointer(Callable.AsInt64);
  {$ELSE}
    CodeAddress := Pointer(Callable.AsInteger);
  {$ENDIF}
  {$HINTS ON}

  // Invoke the method with the global invoke function.
  Result := RTTI.Invoke(CodeAddress, ArrayOfTValueToTValueArray(Args),
              FCallingConvention, ResultType, False, False);
end;
