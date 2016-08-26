TRttiInt64Type = class(TRttiType)
protected
  // Methods
  function GetMaxValue: Int64; virtual;
  function GetMinValue: Int64; virtual;
public
  // Properties
  property MaxValue: Int64 read GetMaxValue;
  property MinValue: Int64 read GetMinValue;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiInt64TypeArray = array of TRttiInt64Type;
