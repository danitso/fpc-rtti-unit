/// <summary> Not documented </summary>
class operator TTypeInfoFieldAccessor.Equal(
  const Left, Right: TTypeInfoFieldAccessor): Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
procedure TTypeInfoFieldAccessor.SetData(const Data: PByte);
begin
  FData := Data;
end;

/// <summary> Not documented </summary>
function TTypeInfoFieldAccessor.Tail: PByte;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TTypeInfoFieldAccessor.ToByteArray: TBytes;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

{$IFNDEF NEXTGEN}
/// <summary> Not documented </summary>
function TTypeInfoFieldAccessor.ToShortUTF8String: ShortString;
begin
  Result := '';
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
{$ENDIF !NEXTGEN}

/// <summary> Not documented </summary>
function TTypeInfoFieldAccessor.ToString: string;
begin
  Result := '';
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TTypeInfoFieldAccessor.UTF8Length: Integer;
begin
  Result := 0;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
