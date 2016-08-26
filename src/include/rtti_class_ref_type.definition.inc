TRttiClassRefType = class(TRttiType)
protected
  // Methods
  function GetInstanceType: TRttiInstanceType; virtual;
  function GetMetaclassType: TClass; virtual;
public
  // Properties
  property InstanceType: TRttiInstanceType read GetInstanceType;
  property MetaclassType: TClass read GetMetaclassType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiClassRefTypeArray = array of TRttiClassRefType;
