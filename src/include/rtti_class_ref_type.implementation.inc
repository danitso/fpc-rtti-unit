/// <summary> Specifies the class type for the metaclass </summary>
function TRttiClassRefType.GetInstanceType: TRttiInstanceType;
begin
  Result := (TRttiPool.GetInstance.GetType(FTypeData^.InstanceType) as
    TRttiInstanceType);
end;

/// <summary> Specifies the actual class reference </summary>
function TRttiClassRefType.GetMetaclassType: TClass;
begin
  Result := GetTypeData(FTypeData^.InstanceType)^.ClassType;
end;
