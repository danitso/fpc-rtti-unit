TRttiOrdinalType = class(TRttiType)
protected
  // Methods
  function GetMaxValue: Integer; virtual;
  function GetMinValue: Integer; virtual;
  function GetOrdType: TOrdType; virtual;
public
  // Properties
  property MaxValue: Integer read GetMaxValue;
  property MinValue: Integer read GetMinValue;
  property OrdType: TOrdType read GetOrdType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiOrdinalTypeArray = array of TRttiOrdinalType;
