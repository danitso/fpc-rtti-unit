TRttiInstanceProperty = class(TRttiProperty)
protected
  // Methods
  function GetDefault: Integer; virtual;
  function GetIndex: Integer; virtual;
  function GetNameIndex: SmallInt; virtual;
  function GetPropInfo: PPropInfo; virtual;
public
  // Methods
  function ToString: AnsiString; override;

  // Properties
  property Default: Integer read GetDefault;
  property Index: Integer read GetIndex;
  property NameIndex: SmallInt read GetNameIndex;
  property PropertyType: TRttiType read GetPropertyType;
  property PropInfo: PPropInfo read GetPropInfo;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiInstancePropertyArray = array of TRttiInstanceProperty;
