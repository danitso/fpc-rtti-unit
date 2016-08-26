/// <summary> Converts an array of const (array of TVarRec) into a dynamic array
/// of TValue instances </summary>
function ArrayOfConstToTValueArray(
  const Params: array of const): TValueArray;
var
  I: Integer;
begin
  SetLength(Result, Length(Params));

  for I := 0 to High(Params) do
  begin
    Result[I] := TValue.FromVarRec(Params[I]);
  end;
end;

/// <summary> Converts an array of const (array of TValue) into a dynamic array
/// of TValue instances </summary>
function ArrayOfTValueToTValueArray(
  const Params: array of TValue): TValueArray;
var
  I: Integer;
begin
  SetLength(Result, Length(Params));

  for I := 0 to High(Params) do
  begin
    Result[I] := Params[I];
  end;
end;

/// <summary> Finalizes the result based on values from registers </summary>
procedure FinalizeResult(var Result: TValue; const I1: NativeUInt;
  const I2: NativeUInt; const FP1: Extended);
begin
  // Convert the values in the registers to the expected value.
  case Result.GetTypeKind of
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar:
    begin
      case Result.GetTypeDataProp^.OrdType of
        otSByte : Result.FData.FAsSByte := ShortInt(I1);
        otSLong : Result.FData.FAsSLong := LongInt(I1);
        otSWord : Result.FData.FAsSWord := SmallInt(I1);
        otUByte : Result.FData.FAsSByte := Byte(I1);
        otULong : Result.FData.FAsSLong := LongWord(I1);
        otUWord : Result.FData.FAsSWord := Word(I1);
      end;
    end;

    tkInt64:
      Result.FData.FAsSInt64 := Int64(I1);

    tkQWord:
      Result.FData.FAsUInt64 := I1;

    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case Result.GetTypeDataProp^.FloatType of
        ftComp     : Result.FData.FAsComp := I1;
        ftCurr     : Result.FData.FAsCurr := Currency(FP1);
        ftDouble   : Result.FData.FAsDouble := FP1;
        ftExtended : Result.FData.FAsExtended := FP1;
        ftSingle   : Result.FData.FAsSingle := FP1;
      end;
    end;
    {$ENDIF}

    tkClass,
    tkObject:
      Result.FData.FAsObject := Pointer(I1);

    tkClassRef,
    tkPointer:
      Result.FData.FAsPointer := Pointer(I1);

    tkAString,
    tkSString,
    tkUString,
    tkWString:;
  else
    raise ENotImplemented.Create(
      'Unsupported result type for dynamic invocation');
  end;
end;

/// <summary> Dynamically invokes a method </summary>
function Invoke(ACodeAddress: Pointer; const AArgs: array of TValue;
  ACallingConvention: TCallConv; AResultType: PTypeInfo; AIsStatic: Boolean;
  AIsConstructor: Boolean): TValue;
begin
  Result := Invoke(ACodeAddress, ArrayOfTValueToTValueArray(AArgs),
    ACallingConvention, AResultType, AIsStatic, AIsConstructor);
end;

{$IFDEF CPUI386}
  {$ASMMODE INTEL}
  {$I rtti_invoke_x86.inc}
{$ELSE}
  {$IFDEF CPUX86_64}
    {$ASMMODE INTEL}
    {$IFDEF MSWINDOWS}
      {$I rtti_invoke_x64_microsoft.inc}
    {$ELSE}
      {$I rtti_invoke_x64_system_v.inc}
    {$ENDIF}
  {$ELSE}
    {$FATAL The RTTI unit does not support this CPU architecture}
  {$ENDIF}
{$ENDIF}

/// <summary> Checks whether a type is managed </summary>
function IsManaged(TypeInfo: PTypeInfo): Boolean;
begin
  case TypeInfo^.Kind of
    tkAString,
    tkDynArray,
    tkInterface,
    tkInterfaceRaw,
    tkUString,
    tkVariant      : Result := True;
    tkRecord       : Result := (GetTypeData(TypeInfo)^.ManagedFldCount > 0);
  else
    Result := False;
  end;
end;

/// <summary> Converts a dynamic array of TValue instances to a dynamic array of
/// TVarRec instances </summary>
function TValueArrayToArrayOfConst(
  const Params: array of TValue): TVarRecArray;
var
  I: Integer;
begin
  SetLength(Result, Length(Params));

  for I := 0 to High(Params) do
  begin
    Result[I] := Params[I].AsVarRec;
  end;
end;
