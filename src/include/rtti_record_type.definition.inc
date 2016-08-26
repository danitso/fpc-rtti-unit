TRttiRecordType = class(TRttiStructuredType)
protected
  // Fields
  FManagedFields: TRttiManagedFieldArray;

  // Methods
  function GetManagedFields: TArray<TRttiManagedField>; virtual;
public
  // Constructors and destructors
  constructor Create(const ATypeInfo: PTypeInfo;
    const AParent: TRttiObject = Nil); override;
  destructor Destroy; override;

  // Methods
  function GetAttributes: TArray<TCustomAttribute>; override;
  function GetDeclaredFields: TArray<TRttiField>; override;
  function GetDeclaredMethods: TArray<TRttiMethod>; override;

  // Properties
  property ManagedFields: TArray<TRttiManagedField> read GetManagedFields;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiRecordTypeArray = array of TRttiRecordType;
