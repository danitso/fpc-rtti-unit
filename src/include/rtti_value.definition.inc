TValue = record
private
  // Variables
  FData: TValueData;

  // Methods.
  function GetDataSize: Integer;
  class function GetEmpty: TValue; static;
  function GetIsEmpty: Boolean;
  function GetTypeInfo: PTypeInfo;
  function GetTypeKind: TTypeKind;
  function GetTypeDataProp: PTypeData;
public
  // Constructors and destructors.
  constructor Create(ATypeInfo: PTypeInfo);

  // Methods.
  function AsBoolean: Boolean;
  function AsClass: TClass;
  function AsCurrency: Currency;
  function AsExtended: Extended;
  function AsInt64: Int64;
  function AsInteger: Integer;
  function AsInterface: IInterface;
  function AsObject: TObject;
  function AsOrdinal: Int64;
  function AsString: string;
  function AsUInt64: UInt64;
  function AsVarRec: TVarRec;
  function AsVariant: Variant;

  function Cast(ATypeInfo: PTypeInfo): TValue; overload;
  function Cast(ATypeInfo: PTypeInfo; const AValue: Extended): TValue; overload;
  function Cast(ATypeInfo: PTypeInfo; const AValue: IInterface): TValue;
    overload;
  function Cast(ATypeInfo: PTypeInfo; const AValue: Int64): TValue; overload;
  function Cast(ATypeInfo: PTypeInfo; const AValue: Pointer): TValue; overload;
  function Cast(ATypeInfo: PTypeInfo; const AValue: String): TValue; overload;

  procedure ExtractRawData(ABuffer: Pointer);
  procedure ExtractRawDataNoCopy(ABuffer: Pointer);

  class function FromArray(ATypeInfo: PTypeInfo; const AValues:
    array of TValue): TValue; static;
  class function FromOrdinal(ATypeInfo: PTypeInfo;
    AValue: Int64): TValue; static;
  class function FromVarRec(const AVarRec: TVarRec): TValue; static;
  class function FromVariant(const AValue: Variant): TValue; static;

  function GetArrayLength: Integer;
  function GetArrayElement(AIndex: Integer): TValue;
  function GetReferenceToRawData: Pointer;
  function GetReferenceToRawArrayElement(AIndex: Integer): Pointer;

  function IsArray: Boolean;
  function IsClass: Boolean;
  function IsInstanceOf(AClass: TClass): Boolean;
  function IsObject: Boolean;
  function IsOrdinal: Boolean;
  function IsType(ATypeInfo: PTypeInfo): Boolean; overload;

  class procedure Make(ABuffer: Pointer; ATypeInfo: PTypeInfo;
    out AResult: TValue); overload; static;
  class procedure Make(AValue: NativeInt; ATypeInfo: PTypeInfo;
    out AResult: TValue); overload; static;
  class procedure MakeWithoutCopy(ABuffer: Pointer; ATypeInfo: PTypeInfo;
    out AResult: TValue); overload; static;

  procedure SetArrayElement(AIndex: Integer; const AValue: TValue);

  function ToString: string;

  function TryAsOrdinal(out AResult: Int64): Boolean;
  function TryCast(ATypeInfo: PTypeInfo; out AResult: TValue): Boolean;

  // Operators.
  class operator Implicit(const AValue: AnsiString): TValue;
  class operator Implicit(const AValue: Boolean): TValue;
  class operator Implicit(const AValue: Currency): TValue;
  class operator Implicit(const AValue: Double): TValue;
  class operator Implicit(const AValue: Int64): TValue;
  class operator Implicit(const AValue: Integer): TValue;
  class operator Implicit(const AValue: QWord): TValue;
  class operator Implicit(const AValue: Single): TValue;
  class operator Implicit(const AValue: TClass): TValue;
  class operator Implicit(const AValue: TObject): TValue;
  class operator Implicit(const AValue: TVarRec): TValue; inline;
  class operator Implicit(const AValue: UnicodeString): TValue;

  // Properties.
  property DataSize: Integer read GetDataSize;
  class property Empty: TValue read GetEmpty;
  property IsEmpty: Boolean read GetIsEmpty;
  property Kind: TTypeKind read GetTypeKind;
  property TypeData: PTypeData read GetTypeDataProp;
  property TypeInfo: PTypeInfo read GetTypeInfo;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TValueArray = array of TValue;
