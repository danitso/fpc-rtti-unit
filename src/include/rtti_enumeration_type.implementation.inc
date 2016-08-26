/// <summary> Returns the names of the enumerables </summary>
function TRttiEnumerationType.GetNames: StringArray;
var
  I: Integer;
  NameCount: Integer;
begin
  // Determine the name count.
  NameCount := GetEnumNameCount(GetHandle);

  // Load the names.
  SetLength(Result, NameCount);

  for I := 0 to NameCount - 1 do
  begin
    Result[I] := String(GetEnumName(GetHandle, I));
  end;
end;

/// <summary> Specifies the elements' type in the enumerated type </summary>
function TRttiEnumerationType.GetUnderlyingType: TRttiType;
begin
  Result := TRttiPool.GetInstance.GetType(FTypeData^.BaseType);
end;
