/// <summary> Specifies the maximum value allowed for values of the reflected
/// ordinal type </summary>
function TRttiOrdinalType.GetMaxValue: Integer;
begin
  Result := FTypeData^.MaxValue;
end;

/// <summary> Specifies the minimum value allowed for values of the reflected
/// ordinal type </summary>
function TRttiOrdinalType.GetMinValue: Integer;
begin
  Result := FTypeData^.MinValue;
end;

/// <summary> Specifies the actual ordinal type </summary>
function TRttiOrdinalType.GetOrdType: TOrdType;
begin
  Result := FTypeData^.OrdType;
end;
