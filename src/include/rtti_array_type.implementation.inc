/// <summary> Specifies the length of a dimension in the static array </summary>
function TRttiArrayType.GetDimension(Index: Integer): TRttiType;
begin
  Result := TRttiPool.GetInstance.GetType(FTypeData^.ArrayData.Dims[Index]);
end;

/// <summary> Specifies the number of dimensions defined for the static
/// array </summary>
function TRttiArrayType.GetDimensionCount: Integer;
begin
  Result := FTypeData^.ArrayData.DimCount;
end;

/// <summary> Specifies the RTTI object reflecting the type of array
/// elements </summary>
function TRttiArrayType.GetElementType: TRttiType;
begin
  Result := TRttiPool.GetInstance.GetType(FTypeData^.ArrayData.ElType);
end;

/// <summary> Specifies the total number of elements the array can store
/// </summary>
function TRttiArrayType.GetTotalElementCount: Integer;
begin
  Result := FTypeData^.ArrayData.ElCount;
end;
