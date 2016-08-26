/// <summary> Specifies the field's type </summary>
function TRttiField.GetFieldType: TRttiType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the offset of the field in the instance </summary>
function TRttiField.GetOffset: Integer;
begin
  Result := 0;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiField.GetValue(Instance: Pointer): TValue;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
procedure TRttiField.SetValue(Instance: Pointer; const AValue: TValue);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiField.ToString: AnsiString;
begin
  Result := '';
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
