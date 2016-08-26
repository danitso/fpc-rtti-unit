TRttiInstanceType = class(TRttiStructuredType)
protected
  // Fields
  FDeclaredIndexedProperties: TRttiIndexedPropertyArray;
  FDeclaredProperties: TRttiPropertyArray;

  // Methods
  function GetBaseTyped: TRttiInstanceType; virtual;
  function GetDeclaringUnitName: string; virtual;
  function GetMetaclassType: TClass; virtual;
  function GetVmtSize: Integer; virtual;

  procedure LoadProperties;
public
  // Constructors and destructors
  constructor Create(const ATypeInfo: PTypeInfo;
    const AParent: TRttiObject = Nil); override;
  destructor Destroy; override;

  // Methods
  function GetAttributes: TCustomAttributeArray; override;
  function GetDeclaredFields: TRttiFieldArray; override;
  function GetDeclaredImplementedInterfaces: TRttiInterfaceTypeArray;
  function GetDeclaredIndexedProperties: TRttiIndexedPropertyArray; override;
  function GetDeclaredMethods: TRttiMethodArray; override;
  function GetDeclaredProperties: TRttiPropertyArray; override;
  function GetImplementedInterfaces: TRttiInterfaceTypeArray;

  // Properties
  property BaseType: TRttiInstanceType read GetBaseTyped;
  property DeclaringUnitName: string read GetDeclaringUnitName;
  property MetaclassType: TClass read GetMetaclassType;
  property VmtSize: Integer read GetVmtSize;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiInstanceTypeArray = array of TRttiInstanceType;
