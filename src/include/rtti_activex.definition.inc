PDispIDList = ^TDispIDList;
PVariantArgList = ^TVariantArgList;

TDispID = LongInt;
TDispIDList = array[0..65535] of TDispID;

TDispParams = record
  rgvarg: PVariantArgList;
  rgdispidNamedArgs: PDispIDList;
  cArgs: NativeUInt;
  cNamedArgs: NativeUInt;
End;

TVariantArg = record
  case Integer of
    0: (
      vt: TVarType;
      wReserved1: Word;
      wReserved2: Word;
      wReserved3: Word;
    );
    1: (
      decVal: Currency
    );
end;

TVariantArgList = array[0..65535] of TVariantArg;
