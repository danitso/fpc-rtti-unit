/// <summary> Creates an instance of TMethodImplementation </summary>
function TRttiMethod.CreateImplementation(AUserData: Pointer;
  const ACallback: TMethodImplementationCallback): TMethodImplementation;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the method's calling convention </summary>
function TRttiMethod.GetCallingConvention: TCallConv;
begin
  Result := ccReg;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the address to the actual code </summary>
function TRttiMethod.GetCodeAddress: Pointer;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the method's dispatch kind </summary>
function TRttiMethod.GetDispatchKind: TDispatchKind;
begin
  Result := dkVtable;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies whether the method provides extended information
/// </summary>
function TRttiMethod.GetHasExtendedInfo: Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies whether the method is a class method </summary>
function TRttiMethod.GetIsClassMethod: Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies whether the method is a constructor </summary>
function TRttiMethod.GetIsConstructor: Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies whether the method is a destructor </summary>
function TRttiMethod.GetIsDestructor: Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies whether the method is a static method </summary>
function TRttiMethod.GetIsStatic: Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the method kind </summary>
function TRttiMethod.GetMethodKind: TMethodKind;
begin
  Result := mkFunction;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the return type of the method </summary>
function TRttiMethod.GetReturnType: TRttiType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the virtual index of the method </summary>
function TRttiMethod.GetVirtualIndex: SmallInt;
begin
  Result := 0;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Invokes the method </summary>
function TRttiMethod.Invoke(Instance: TObject;
  const Args: array of TValue): TValue;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Invokes the method </summary>
function TRttiMethod.Invoke(Instance: TClass;
  const Args: array of TValue): TValue;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Invokes the method </summary>
function TRttiMethod.Invoke(Instance: TValue;
  const Args: array of TValue): TValue;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns the string representation of the RTTI method object
/// </summary>
function TRttiMethod.ToString: AnsiString;
begin
  Result := '';
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
