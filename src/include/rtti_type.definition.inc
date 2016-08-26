TRttiType = class(TRttiNamedObject)
protected
  // Fields
  FTypeData: PTypeData;

  // Methods
  function GetAsInstance: TRttiInstanceType; virtual;
  function GetAsOrdinal: TRttiOrdinalType; virtual;
  function GetAsRecord: TRttiRecordType; virtual;
  function GetAsSet: TRttiSetType; virtual;
  function GetBaseType: TRttiType; virtual;
  function GetHandle: PTypeInfo; virtual;
  function GetHFAElementCount: Integer; virtual;
  function GetHFAElementType: TRttiFloatType; virtual;
  function GetIsHFA: Boolean; virtual;
  function GetIsInstance: Boolean; virtual;
  function GetIsManaged: Boolean; virtual;
  function GetIsOrdinal: Boolean; virtual;
  function GetIsPublicType: Boolean; virtual;
  function GetIsRecord: Boolean; virtual;
  function GetIsSet: Boolean; virtual;
  function GetQualifiedName: string; virtual;
  function GetTypeKind: TTypeKind; virtual;
  function GetTypeSize: Integer; virtual;
public
  // Constructors and destructors
  constructor Create(const ATypeInfo: PTypeInfo;
    const AParent: TRttiObject = Nil); virtual;

  // Methods
  function GetAttributes: TCustomAttributeArray; override;
  function GetDeclaredFields: TRttiFieldArray; virtual;
  function GetDeclaredIndexedProperties: TRttiIndexedPropertyArray; virtual;
  function GetDeclaredMethods: TRttiMethodArray; virtual;
  function GetDeclaredProperties: TRttiPropertyArray; virtual;
  function GetField(const AName: string): TRttiField; virtual;
  function GetFields: TRttiFieldArray; virtual;
  function GetIndexedProperties: TRttiIndexedPropertyArray; virtual;
  function GetIndexedProperty(const AName: string): TRttiIndexedProperty;
    virtual;
  function GetMethod(const AName: string): TRttiMethod; virtual;
  function GetMethods: TRttiMethodArray; overload; virtual;
  function GetMethods(const AName: string): TRttiMethodArray; overload;
    virtual;
  function GetName: string; override;
  function GetProperties: TRttiPropertyArray; virtual;
  function GetProperty(const AName: string): TRttiProperty; virtual;

  function ToString: AnsiString; override;

  // Properties
  property AsInstance: TRttiInstanceType read GetAsInstance;
  property AsOrdinal: TRttiOrdinalType read GetAsOrdinal;
  property AsRecord: TRttiRecordType read GetAsRecord;
  property AsSet: TRttiSetType read GetAsSet;
  property BaseType: TRttiType read GetBaseType;
  property Handle: PTypeInfo read GetHandle;
  property HFAElementCount: Integer read GetHFAElementCount;
  property HFAElementType: TRttiFloatType read GetHFAElementType;
  property IsHFA: Boolean read GetIsHFA;
  property IsInstance: Boolean read GetIsInstance;
  property IsManaged: Boolean read GetIsManaged;
  property IsOrdinal: Boolean read GetIsOrdinal;
  property IsPublicType: Boolean read GetIsPublicType;
  property IsRecord: Boolean read GetIsRecord;
  property IsSet: Boolean read GetIsSet;
  property QualifiedName: string read GetQualifiedName;
  property TypeKind: TTypeKind read GetTypeKind;
  property TypeSize: Integer read GetTypeSize;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiTypeArray = array of TRttiType;
