TRttiManagedField = class(TRttiObject)
protected
  // Methods
  function GetFieldOffset: Integer; virtual;
  function GetFieldType: TRttiType; virtual;
public
  // Constructors and destructors
  constructor Create(const AParent: TRttiObject; const AField: PManagedField);

  // Methods
  function GetAttributes: TCustomAttributeArray; override;

  // Properties
  property FieldOffset: Integer read GetFieldOffset;
  property FieldType: TRttiType read GetFieldType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiManagedFieldArray = array of TRttiManagedField;
