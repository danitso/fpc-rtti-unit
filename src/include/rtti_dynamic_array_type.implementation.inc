/// <summary> Specifies the name of the unit in which the array type is declared
/// </summary>
function TRttiDynamicArrayType.GetDeclaringUnitName: string;
begin
  Result := String(FTypeData^.DynUnitName);
end;

/// <summary> Specifies the number of bytes occupied by an array element
/// </summary>
function TRttiDynamicArrayType.GetElementSize: Integer;
begin
  Result := FTypeData^.elSize;
end;

/// <summary> Specifies the RTTI object reflecting the type of the array
/// elements </summary>
function TRttiDynamicArrayType.GetElementType: TRttiType;
begin
  Result := TRttiPool.GetInstance.GetType(FTypeData^.elType2);
end;

/// <summary> Specifies the type of the OLE-compatible Variant representing the
/// array elements </summary>
function TRttiDynamicArrayType.GetOleAutoVarType: TVarType;
begin
  Result := TVarType(FTypeData^.varType);
end;
