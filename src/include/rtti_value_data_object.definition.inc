TValueDataObject = class(TInterfacedObject, IValueData)
private
  // Fields.
  FAnsiString: AnsiString;
  FInterface: IInterface;
  FShortString: ShortString;
  FTypeKind: TTypeKind;
  FUnicodeString: UnicodeString;
  FWideString: WideString;
public
  // Constructors and destructors.
  constructor Create;

  // Methods.
  function GetAnsiString: AnsiString;
  function GetDataSize: Integer;
  function GetInterface: IInterface;
  function GetReferenceToRawData: Pointer;
  function GetShortString: ShortString;
  function GetTypeKind: TTypeKind;
  function GetUnicodeString: UnicodeString;
  function GetWideString: WideString;

  procedure Reset;

  procedure SetAnsiString(const AValue: AnsiString);
  procedure SetInterface(const AValue: IInterface);
  procedure SetShortString(const AValue: ShortString);
  procedure SetUnicodeString(const AValue: UnicodeString);
  procedure SetWideString(const AValue: WideString);
end;
