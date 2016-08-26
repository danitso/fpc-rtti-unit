/// <summary> Specifies the maximum value allowed for variables of the
/// reflected type </summary>
function TRttiInt64Type.GetMaxValue: Int64;
begin
  case GetTypeKind of
    tkInt64 : Result := FTypeData^.MaxInt64Value;
    tkQWord : Result := FTypeData^.MinInt64Value;
  else
    raise ENotImplemented.Create('Unsupported integer type');
  end;
end;

/// <summary> Specifies the minimum value allowed for variables of the
/// reflected type </summary>
function TRttiInt64Type.GetMinValue: Int64;
begin
  case GetTypeKind of
    tkInt64 : Result := Int64(FTypeData^.MaxQWordValue);
    tkQWord : Result := Int64(FTypeData^.MinQWordValue);
  else
    raise ENotImplemented.Create('Unsupported integer type');
  end;
end;
