/// <summary> Specifies the type of the elements in the set </summary>
function TRttiSetType.GetElementType: TRttiType;
begin
  Result := TRttiContext.Create.GetType(FTypeData^.CompType);
end;
