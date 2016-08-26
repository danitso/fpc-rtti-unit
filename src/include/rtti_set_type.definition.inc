TRttiSetType = class(TRttiType)
protected
  // Methods
  function GetElementType: TRttiType; virtual;
public
  // Properties
  property ElementType: TRttiType read GetElementType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiSetTypeArray = array of TRttiSetType;
