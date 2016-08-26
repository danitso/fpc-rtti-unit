{$M+}
TRttiSystemTypes = class
private
  // Fields
  FAnsiCharType: AnsiChar;
  FAnsiStringType: AnsiString;
  FBooleanType: Boolean;
  FByteType: Byte;
  FCurrencyType: Currency;
  FDoubleType: Double;
  FExtendedType: Extended;
  FInt64Type: Int64;
  FLongIntType: LongInt;
  FLongWordType: LongWord;
  FNativeIntType: NativeInt;
  FNativeUIntType: NativeUInt;
  FQWordType: QWord;
  FShortIntType: ShortInt;
  FSingleType: Single;
  FSmallIntType: SmallInt;
  FUnicodeCharType: UnicodeChar;
  FUnicodeStringType: UnicodeString;
  FWideCharType: WideChar;
  FWideStringType: WideString;
  FWordType: Word;
published
  // Properties
  property AnsiCharType: AnsiChar read FAnsiCharType;
  property AnsiStringType: AnsiString read FAnsiStringType;
  property BooleanType: Boolean read FBooleanType;
  property ByteType: Byte read FByteType;
  property CurrencyType: Currency read FCurrencyType;
  property DoubleType: Double read FDoubleType;
  property ExtendedType: Extended read FExtendedType;
  property Int64Type: Int64 read FInt64Type;
  property LongIntType: LongInt read FLongIntType;
  property LongWordType: LongWord read FLongWordType;
  property NativeIntType: NativeInt read FNativeIntType;
  property NativeUIntType: NativeUInt read FNativeUIntType;
  property QWordType: QWord read FQWordType;
  property ShortIntType: ShortInt read FShortIntType;
  property SingleType: Single read FSingleType;
  property SmallIntType: SmallInt read FSmallIntType;
  property UnicodeCharType: UnicodeChar read FUnicodeCharType;
  property UnicodeStringType: UnicodeString read FUnicodeStringType;
  property WideCharType: WideChar read FWideCharType;
  property WideStringType: WideString read FWideStringType;
  property WordType: Word read FWordType;
end;
{$M-}
