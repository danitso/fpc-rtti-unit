TRttiPointerType = class(TRttiType)
protected
  // Methods
  function GetReferredType: TRttiType; virtual;
public
  // Methods
  function GetAttributes: TCustomAttributeArray; override;

  // Properties
  property ReferredType: TRttiType read GetReferredType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiPointerTypeArray = array of TRttiPointerType;
