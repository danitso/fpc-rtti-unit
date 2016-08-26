TRttiEnumerationType = class(TRttiOrdinalType)
protected
  // Methods
  function GetUnderlyingType: TRttiType; virtual;
public
  // Methods
  function GetNames: StringArray; virtual;

  // Properties
  property UnderlyingType: TRttiType read GetUnderlyingType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiEnumerationTypeArray = array of TRttiEnumerationType;
