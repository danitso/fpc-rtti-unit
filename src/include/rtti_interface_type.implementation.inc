/// <summary> Specifies the ancestor interface </summary>
function TRttiInterfaceType.GetBaseTyped: TRttiInterfaceType;
begin
  Result := (TRttiPool.GetInstance.GetType(FTypeData^.IntfParent) as
    TRttiInterfaceType);
end;

/// <summary> Returns a list of all the methods declared in the reflected
/// interface type </summary>
function TRttiInterfaceType.GetDeclaredMethods: TArray<TRttiMethod>;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the name of the unit in which the interface type is
/// declared </summary>
function TRttiInterfaceType.GetDeclaringUnitName: string;
begin
  Result := String(FTypeData^.IntfUnit);
end;

/// <summary> Specifies the GUID of the interface type </summary>
function TRttiInterfaceType.GetGUID: TGUID;
begin
  Result := FTypeData^.GUID;
end;

/// <summary> Specifies the interface flags </summary>
function TRttiInterfaceType.GetIntfFlags: TIntfFlags;
begin
  Result := FTypeData^.IntfFlags;
end;
