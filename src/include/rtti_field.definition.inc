TRttiField = class(TRttiMember)
protected
  // Methods
  function GetFieldType: TRttiType; virtual;
  function GetOffset: Integer; virtual;
public
  // Methods
  function GetValue(Instance: Pointer): TValue; virtual;
  procedure SetValue(Instance: Pointer; const AValue: TValue); virtual;
  function ToString: AnsiString; override;

  // Properties
  property FieldType: TRttiType read GetFieldType;
  property Offset: Integer read GetOffset;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiFieldArray = array of TRttiField;
