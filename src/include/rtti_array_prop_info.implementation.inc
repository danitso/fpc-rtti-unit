/// <summary> Not yet documented </summary>
function TArrayPropInfo.AttrData: PAttrData;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not yet documented </summary>
function TArrayPropInfo.NameFld: TTypeInfoFieldAccessor;
begin
  Result.SetData(Nil);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
