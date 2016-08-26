TRttiArrayType = class(TRttiType)
protected
  // Methods
  function GetDimension(Index: Integer): TRttiType; virtual;
  function GetDimensionCount: Integer; virtual;
  function GetElementType: TRttiType; virtual;
  function GetTotalElementCount: Integer; virtual;
public
  // Properties
  property DimensionCount: Integer read GetDimensionCount;
  property Dimensions[Index: Integer]: TRttiType read GetDimension;
  property ElementType: TRttiType read GetElementType;
  property TotalElementCount: Integer read GetTotalElementCount;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiArrayTypeArray = array of TRttiArrayType;
