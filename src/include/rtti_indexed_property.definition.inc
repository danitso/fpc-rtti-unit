TRttiIndexedProperty = class(TRttiMember)
protected
  // Methods
  function GetHandle: PArrayPropInfo; virtual;
  function GetIsDefault: Boolean; virtual;
  function GetIsReadable: Boolean; virtual;
  function GetIsWritable: Boolean; virtual;
  function GetPropertyType: TRttiType; virtual;
  function GetReadMethod: TRttiMethod; virtual;
  function GetWriteMethod: TRttiMethod; virtual;
public
  // Constructors and destructors
  constructor Create(const AParent: TRttiObject; const APropInfo: PPropInfo);

  // Methods
  function GetAttributes: TCustomAttributeArray; override;
  function GetName: string; override;
  function GetValue(Instance: Pointer; const Args: array of TValue): TValue;

  procedure SetValue(Instance: Pointer; const Args: array of TValue;
    const Value: TValue);

  function ToString: AnsiString; override;

  // Properties
  property Handle: PArrayPropInfo read GetHandle;
  property IsDefault: Boolean read GetIsDefault;
  property IsReadable: Boolean read GetIsReadable;
  property IsWritable: Boolean read GetIsWritable;
  property PropertyType: TRttiType read GetPropertyType;
  property ReadMethod: TRttiMethod read GetReadMethod;
  property WriteMethod: TRttiMethod read GetWriteMethod;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiIndexedPropertyArray = array of TRttiIndexedProperty;
