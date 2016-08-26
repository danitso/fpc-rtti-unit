/// <summary> Specifies the property's default value </summary>
function TRttiInstanceProperty.GetDefault: Integer;
begin
  Result := PPropInfo(FHandle)^.Default;
end;

/// <summary> Specifies the property's default index </summary>
function TRttiInstanceProperty.GetIndex: Integer;
begin
  Result := PPropInfo(FHandle)^.Index;
end;

/// <summary> Specifies the index of the property name in the object's name list
/// </summary>
function TRttiInstanceProperty.GetNameIndex: SmallInt;
begin
  Result := PPropInfo(FHandle)^.NameIndex;
end;

/// <summary> Points to the property's raw RTTI information </summary>
function TRttiInstanceProperty.GetPropInfo: PPropInfo;
begin
  Result := PPropInfo(FHandle);
end;

/// <summary> Returns the string representation of the RTTI property object
/// </summary>
function TRttiInstanceProperty.ToString: AnsiString;
begin
  Result := '';
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
