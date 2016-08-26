/// <summary> Creates a new instance of the class </summary>
constructor TRttiMethodType.Create(const ATypeInfo: PTypeInfo;
  const AParent: TRttiObject = Nil);
var
  Flags     : array of TParamFlags;
  I         : Integer;
  Names     : array of ShortString;
  P         : Pointer;
  ParamData : PParamData;
  TypeData  : PTypeData;
begin
  // Invoke the parent constructor.
  inherited;

  // Retrieve the type data.
  TypeData := GetTypeData(ATypeInfo);

  // Initialize the temporary arrays once instead of resizing them later on.
  SetLength(Flags, TypeData^.ParamCount);
  SetLength(Names, TypeData^.ParamCount);

  // Retrieve the parameter flags and names.
  P := @TypeData^.ParamList;

  for I := 0 to TypeData^.ParamCount - 1 do
  begin
    ParamData := PParamData(P);

    Flags[I] := ParamData^.Flags;
    Names[I] := ParamData^.ParamName;

    P := Pointer(@ParamData^.ParamName) + Length(ParamData^.ParamName) + 1;
    P := P + Length(PShortString(P)^) + 1;
  end;

  // Retrieve the return type if the method is a function.
  if (TypeData^.MethodKind = mkClassFunction) or
     (TypeData^.MethodKind = mkFunction) then
  begin
    P := P + Length(PShortString(P)^) + 1;
    FReturnType := TRttiContext.GetType(PTypeInfo(P^));
    P := P + SizeOf(PPTypeInfo);
  end;

  // Retrieve the calling convention.
  FCallingConvention := TCallConv(P);
  P := P + SizeOf(TCallConv);

  // Create the parameter instances based on the previously retrieved data.
  SetLength(FParameters, TypeData^.ParamCount);

  for I := 0 to TypeData^.ParamCount - 1 do
  begin
    FParameters[I] := TRttiParameter.Create(Self, String(Names[I]), Flags[I],
      PTypeInfo(P^));
    P := P + SizeOf(PPTypeInfo);
  end;
end;

/// <summary> Specifies the method kind </summary>
function TRttiMethodType.GetMethodKind: TMethodKind;
begin
  Result := FTypeData^.MethodKind;
end;

/// <summary> Invokes the method </summary>
function TRttiMethodType.Invoke(const Callable: TValue;
  const Args: array of TValue): TValue;
var
  CodeAddress   : Pointer;
  IsConstructor : Boolean;
  IsStatic      : Boolean;
  ResultType    : PTypeInfo;
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

  // Determine if the method is a constructor and/or is static.
  IsConstructor := (FTypeData^.MethodKind = mkClassConstructor) or
                   (FTypeData^.MethodKind = mkConstructor);

  IsStatic      := (FTypeData^.MethodKind = mkClassConstructor) or
                   (FTypeData^.MethodKind = mkClassDestructor) or
                   (FTypeData^.MethodKind = mkClassFunction) or
                   (FTypeData^.MethodKind = mkClassProcedure);

  // Invoke the method with the global invoke function.
  Result := RTTI.Invoke(CodeAddress, ArrayOfTValueToTValueArray(Args),
              FCallingConvention, ResultType, IsStatic, IsConstructor);
end;

/// <summary> Not documented </summary>
function TRttiMethodType.ToString: AnsiString;
begin
  Result := AnsiString(GetQualifiedName);
end;
