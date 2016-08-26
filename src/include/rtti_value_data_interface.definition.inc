IValueData = interface
  ['{B0EDB941-1661-41F5-883B-5CAAE3E28401}']
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
