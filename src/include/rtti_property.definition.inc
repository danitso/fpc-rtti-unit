TRttiProperty = class(TRttiMember)
protected
  // Methods
  function GetIsReadable: Boolean; virtual;
  function GetIsWritable: Boolean; virtual;
  function GetPropertyType: TRttiType; virtual;
public
  // Constructors and destructors
  constructor Create(const AParent: TRttiObject; const APropInfo: PPropInfo);

  // Methods
  function GetAttributes: TCustomAttributeArray; override;
  function GetName: string; override;
  function GetValue(Instance: Pointer): TValue;

  procedure SetValue(Instance: Pointer; const AValue: TValue);

  // Properties
  property IsReadable: Boolean read GetIsReadable;
  property IsWritable: Boolean read GetIsWritable;
  property PropertyType: TRttiType read GetPropertyType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiPropertyArray = array of TRttiProperty;
