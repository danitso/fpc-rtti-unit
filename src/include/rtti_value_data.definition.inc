TValueData = record
  FTypeInfo: PTypeInfo;
  FValueData: IValueData;

  case Integer of
    0: (FAsUByte: Byte);
    1: (FAsUWord: Word);
    2: (FAsULong: Cardinal);
    3: (FAsObject: Pointer);
    4: (FAsClass: TClass);
    5: (FAsSByte: ShortInt);
    6: (FAsSWord: SmallInt);
    7: (FAsSLong: Integer);
    8: (FAsSingle: Single);
    9: (FAsDouble: Double);
    10: (FAsExtended: Extended);
    11: (FAsComp: Comp);
    12: (FAsCurr: Currency);
    13: (FAsUInt64: UInt64);
    14: (FAsSInt64: Int64);
    15: (FAsMethod: TMethod);
    16: (FAsPointer: Pointer);
end;
