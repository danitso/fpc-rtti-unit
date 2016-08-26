/// <summary> Specifies the floating-point subtype </summary>
function TRttiFloatType.GetFloatType: TFloatType;
begin
  Result := FTypeData^.FloatType;
end;
