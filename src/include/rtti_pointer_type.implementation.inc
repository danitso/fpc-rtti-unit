/// <summary> Returns a list of attributes associated with the pointer type
/// </summary>
function TRttiPointerType.GetAttributes: TCustomAttributeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the type of the value to which the pointer type points
/// </summary>
function TRttiPointerType.GetReferredType: TRttiType;
begin
  Result := TRttiContext.Create.GetType(FTypeData^.RefType);
end;
