/// <summary> Converts the value to Boolean </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsBoolean: Boolean;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar        :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte    : Result := (FData.FAsSByte <> 0);
        otSLong    : Result := (FData.FAsSLong <> 0);
        otSWord    : Result := (FData.FAsSWord <> 0);
        otUByte    : Result := (FData.FAsUByte <> 0);
        otULong    : Result := (FData.FAsULong <> 0);
        otUWord    : Result := (FData.FAsUWord <> 0);
      end;
    end;

    tkInt64        : Result := (FData.FAsSInt64 <> 0);
    tkQWord        : Result := (FData.FAsUInt64 <> 0);

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := (FData.FAsComp <> 0);
        ftCurr     : Result := (FData.FAsCurr <> 0);
        ftDouble   : Result := (FData.FAsDouble <> 0);
        ftExtended : Result := (FData.FAsExtended <> 0);
        ftSingle   : Result := (FData.FAsSingle <> 0);
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString      : Result := StrToBool(AnsiString(
                       FData.FValueData.GetAnsiString));
    tkSString      : Result := StrToBool(AnsiString(
                       FData.FValueData.GetShortString));
    tkUString      : Result := StrToBool(AnsiString(
                       FData.FValueData.GetUnicodeString));
    tkWString      : Result := StrToBool(AnsiString(
                       FData.FValueData.GetWideString));

    // Other types.
    tkClass,
    tkClassRef     : Result := (FData.FAsClass <> Nil);
    tkMethod       : Result := (FData.FAsMethod.Code <> Nil);
    tkObject       : Result := (FData.FAsObject <> Nil);
    tkInterface,
    tkInterfaceRaw,
    tkPointer,
    tkProcedure    : Result := (FData.FAsPointer <> Nil);
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to TClass </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsClass: TClass;
begin
  case GetTypeKind of
    // Other types.
    tkClass,
    tkClassRef : Result := FData.FAsClass;
    tkObject   : Result := TObject(FData.FAsObject).ClassType;
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to Currency </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsCurrency: Currency;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar        :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte    : Result := FData.FAsSByte;
        otSLong    : Result := FData.FAsSLong;
        otSWord    : Result := FData.FAsSWord;
        otUByte    : Result := FData.FAsUByte;
        otULong    : Result := FData.FAsULong;
        otUWord    : Result := FData.FAsUWord;
      end;
    end;

    tkInt64        : Result := FData.FAsSInt64;
    tkQWord        : Result := FData.FAsUInt64;

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := FloatToCurr(FData.FAsComp);
        ftCurr     : Result := FData.FAsCurr;
        ftDouble   : Result := FloatToCurr(FData.FAsDouble);
        ftExtended : Result := FloatToCurr(FData.FAsExtended);
        ftSingle   : Result := FloatToCurr(FData.FAsSingle);
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString      : Result := StrToCurr(AnsiString(
                       FData.FValueData.GetAnsiString));
    tkSString      : Result := StrToCurr(AnsiString(
                       FData.FValueData.GetShortString));
    tkUString      : Result := StrToCurr(AnsiString(
                       FData.FValueData.GetUnicodeString));
    tkWString      : Result := StrToCurr(AnsiString(
                       FData.FValueData.GetWideString));
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to Extended </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsExtended: Extended;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar        :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte    : Result := FData.FAsSByte;
        otSLong    : Result := FData.FAsSLong;
        otSWord    : Result := FData.FAsSWord;
        otUByte    : Result := FData.FAsUByte;
        otULong    : Result := FData.FAsULong;
        otUWord    : Result := FData.FAsUWord;
      end;
    end;

    tkInt64        : Result := FData.FAsSInt64;
    tkQWord        : Result := FData.FAsUInt64;

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := FData.FAsComp;
        ftCurr     : Result := FData.FAsCurr;
        ftDouble   : Result := FData.FAsDouble;
        ftExtended : Result := FData.FAsExtended;
        ftSingle   : Result := FData.FAsSingle;
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString      : Result := StrToFloat(AnsiString(
                       FData.FValueData.GetAnsiString));
    tkSString      : Result := StrToFloat(AnsiString(
                       FData.FValueData.GetShortString));
    tkUString      : Result := StrToFloat(AnsiString(
                       FData.FValueData.GetUnicodeString));
    tkWString      : Result := StrToFloat(AnsiString(
                       FData.FValueData.GetWideString));

    // Other types.
    {$HINTS OFF}
    tkObject       : Result := Extended(NativeUInt(FData.FAsObject));
    tkPointer      : Result := Extended(NativeUInt(FData.FAsPointer));
    {$HINTS ON}
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to Int64 </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsInt64: Int64;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar        :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte    : Result := FData.FAsSByte;
        otSLong    : Result := FData.FAsSLong;
        otSWord    : Result := FData.FAsSWord;
        otUByte    : Result := FData.FAsUByte;
        otULong    : Result := FData.FAsULong;
        otUWord    : Result := FData.FAsUWord;
      end;
    end;

    tkInt64        : Result := FData.FAsSInt64;
    tkQWord        : Result := FData.FAsUInt64;

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := Trunc(FData.FAsComp);
        ftCurr     : Result := Trunc(FData.FAsCurr);
        ftDouble   : Result := Trunc(FData.FAsDouble);
        ftExtended : Result := Trunc(FData.FAsExtended);
        ftSingle   : Result := Trunc(FData.FAsSingle);
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString      : Result := StrToInt64(AnsiString(
                       FData.FValueData.GetAnsiString));
    tkSString      : Result := StrToInt64(AnsiString(
                       FData.FValueData.GetShortString));
    tkUString      : Result := StrToInt64(AnsiString(
                       FData.FValueData.GetUnicodeString));
    tkWString      : Result := StrToInt64(AnsiString(
                       FData.FValueData.GetWideString));

    // Other types.
    {$HINTS OFF}
    tkObject       : Result := Int64(NativeInt(FData.FAsObject));
    tkPointer      : Result := Int64(NativeInt(FData.FAsPointer));
    {$HINTS ON}
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to Integer </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsInteger: Integer;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar        :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte    : Result := FData.FAsSByte;
        otSLong    : Result := FData.FAsSLong;
        otSWord    : Result := FData.FAsSWord;
        otUByte    : Result := FData.FAsUByte;
        otULong    : Result := FData.FAsULong;
        otUWord    : Result := FData.FAsUWord;
      end;
    end;

    tkInt64        : Result := FData.FAsSInt64;
    tkQWord        : Result := FData.FAsUInt64;

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := Trunc(FData.FAsComp);
        ftCurr     : Result := Trunc(FData.FAsCurr);
        ftDouble   : Result := Trunc(FData.FAsDouble);
        ftExtended : Result := Trunc(FData.FAsExtended);
        ftSingle   : Result := Trunc(FData.FAsSingle);
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString      : Result := StrToInt64(AnsiString(
                       FData.FValueData.GetAnsiString));
    tkSString      : Result := StrToInt64(AnsiString(
                       FData.FValueData.GetShortString));
    tkUString      : Result := StrToInt64(AnsiString(
                       FData.FValueData.GetUnicodeString));
    tkWString      : Result := StrToInt64(AnsiString(
                       FData.FValueData.GetWideString));

    // Other types.
    {$IFDEF CPU32}
    tkObject       : Result := Integer(FData.FAsObject);
    tkPointer      : Result := Integer(FData.FAsPointer);
    {$ENDIF}
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to IInterface </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsInterface: IInterface;
begin
  case GetTypeKind of
    tkInterface,
    tkInterfaceRaw : Result := FData.FValueData.GetInterface;
    tkObject       : Result := TInterfacedObject(TObject(FData.FAsObject));
    tkPointer      : Result := IInterface(FData.FAsPointer);
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to TObject </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsObject: TObject;
begin
  case GetTypeKind of
    tkObject  : Result := TObject(FData.FAsObject);
    tkPointer : Result := TObject(FData.FAsPointer);
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to Int64 </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsOrdinal: Int64;
begin
  Result := AsInt64;
end;

/// <summary> Converts the value to String </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsString: string;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar        :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte    : Result := String(IntToStr(FData.FAsSByte));
        otSLong    : Result := String(IntToStr(FData.FAsSLong));
        otSWord    : Result := String(IntToStr(FData.FAsSWord));
        otUByte    : Result := String(IntToStr(FData.FAsUByte));
        otULong    : Result := String(IntToStr(FData.FAsULong));
        otUWord    : Result := String(IntToStr(FData.FAsUWord));
      end;
    end;

    tkInt64        : Result := String(IntToStr(FData.FAsSInt64));
    tkQWord        : Result := String(IntToStr(FData.FAsUInt64));

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := String(IntToStr(Trunc(FData.FAsComp)));
        ftCurr     : Result := String(IntToStr(Trunc(FData.FAsCurr)));
        ftDouble   : Result := String(IntToStr(Trunc(FData.FAsDouble)));
        ftExtended : Result := String(IntToStr(Trunc(FData.FAsExtended)));
        ftSingle   : Result := String(IntToStr(Trunc(FData.FAsSingle)));
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString      : Result := String(FData.FValueData.GetAnsiString);
    tkSString      : Result := String(FData.FValueData.GetShortString);
    tkUString      : Result := String(FData.FValueData.GetUnicodeString);
    tkWString      : Result := String(FData.FValueData.GetWideString);

    // Other types.
    {$HINTS OFF}
    tkObject       : Result := String(IntToStr(NativeInt(FData.FAsObject)));
    tkPointer      : Result := String(IntToStr(NativeInt(FData.FAsPointer)));
    {$HINTS ON}
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to UInt64 </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsUInt64: UInt64;
begin
  Result := UInt64(AsInt64);
end;

/// <summary> Converts the value to TVarRec </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsVarRec: TVarRec;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool:
    begin
      Result.VType := vtBoolean;

      case GetTypeDataProp^.OrdType of
        otSByte : Result.VBoolean := (FData.FAsSByte <> 0);
        otSLong : Result.VBoolean := (FData.FAsSLong <> 0);
        otSWord : Result.VBoolean := (FData.FAsSWord <> 0);
        otUByte : Result.VBoolean := (FData.FAsUByte <> 0);
        otULong : Result.VBoolean := (FData.FAsULong <> 0);
        otUWord : Result.VBoolean := (FData.FAsUWord <> 0);
      end;
    end;

    tkChar:
    begin
      Result.VType := vtChar;

      case GetTypeDataProp^.OrdType of
        otSByte : Result.VChar := Chr(Byte(FData.FAsUByte));
        otSLong : Result.VChar := Chr(Byte(FData.FAsULong));
        otSWord : Result.VChar := Chr(Byte(FData.FAsUWord));
        otUByte : Result.VChar := Chr(FData.FAsUByte);
        otULong : Result.VChar := Chr(Byte(FData.FAsULong));
        otUWord : Result.VChar := Chr(Byte(FData.FAsUWord));
      end;
    end;

    tkEnumeration,
    tkInteger,
    tkSet:
    begin
      Result.VType := vtInteger;

      case GetTypeDataProp^.OrdType of
        otSByte : Result.VInteger := FData.FAsSByte;
        otSLong : Result.VInteger := FData.FAsSLong;
        otSWord : Result.VInteger := FData.FAsSWord;
        otUByte : Result.VInteger := FData.FAsUByte;
        otULong : Result.VInteger := FData.FAsULong;
        otUWord : Result.VInteger := FData.FAsUWord;
      end;
    end;

    tkUChar,
    tkWChar:
    begin
      Result.VType := vtWideChar;

      case GetTypeDataProp^.OrdType of
        otSByte : Result.VWideChar := WideChar(FData.FAsSByte);
        otSLong : Result.VWideChar := WideChar(FData.FAsSLong);
        otSWord : Result.VWideChar := WideChar(FData.FAsSWord);
        otUByte : Result.VWideChar := WideChar(FData.FAsUByte);
        otULong : Result.VWideChar := WideChar(FData.FAsULong);
        otUWord : Result.VWideChar := WideChar(FData.FAsUWord);
      end;
    end;

    tkInt64:
    begin
      Result.VType := vtInt64;
      Result.VInt64 := @FData.FAsSInt64;
    end;

    tkQWord:
    begin
      Result.VType := vtQWord;
      Result.VInt64 := @FData.FAsUInt64;
    end;

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat:
    begin
      case GetTypeDataProp^.FloatType of
        ftComp:
        begin
          Result.VType := vtInt64;
          Result.VInt64 := @FData.FAsComp;
        end;

        ftCurr:
        begin
          Result.VType := vtCurrency;
          Result.VCurrency := @FData.FAsCurr;
        end;

        ftDouble:
        begin
          Result.VType := vtExtended;
          Result.VExtended := @FData.FAsDouble;
        end;

        ftExtended:
        begin
          Result.VType := vtExtended;
          Result.VExtended := @FData.FAsExtended;
        end;

        ftSingle:
        begin
          Result.VType := vtExtended;
          Result.VExtended := @FData.FAsSingle;
        end;
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString:
    begin
      Result.VType := vtAnsiString;
      Result.VAnsiString := Pointer(FData.FValueData.GetAnsiString);
    end;

    tkUString:
    begin
      Result.VType := vtUnicodeString;
      Result.VAnsiString := Pointer(FData.FValueData.GetUnicodeString);
    end;

    tkWString:
    begin
      Result.VType := vtWideString;
      Result.VAnsiString := Pointer(FData.FValueData.GetWideString);
    end;
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Converts the value to Variant </summary>
/// <returns> Returns the converted value </returns>
function TValue.AsVariant: Variant;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar        :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte    : Result := FData.FAsSByte;
        otSLong    : Result := FData.FAsSLong;
        otSWord    : Result := FData.FAsSWord;
        otUByte    : Result := FData.FAsUByte;
        otULong    : Result := FData.FAsULong;
        otUWord    : Result := FData.FAsUWord;
      end;
    end;

    tkInt64        : Result := FData.FAsSInt64;
    tkQWord        : Result := FData.FAsUInt64;

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := FData.FAsComp;
        ftCurr     : Result := FData.FAsCurr;
        ftDouble   : Result := FData.FAsDouble;
        ftExtended : Result := FData.FAsExtended;
        ftSingle   : Result := FData.FAsSingle;
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString      : Result := FData.FValueData.GetAnsiString;
    tkSString      : Result := FData.FValueData.GetShortString;
    tkUString      : Result := FData.FValueData.GetUnicodeString;
    tkWString      : Result := FData.FValueData.GetWideString;

    // Other types.
    tkInterface    : Result := FData.FValueData.GetInterface;
    tkObject       : Result := FData.FAsObject;
    tkPointer      : Result := FData.FAsPointer;
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;
end;

/// <summary> Casts the value to specific type </summary>
/// <param name="ATypeInfo"> A pointer to a TTypeInfo record </param>
/// <returns> Returns a TValue </returns>
function TValue.Cast(ATypeInfo: PTypeInfo): TValue;
var
  FInt64: Int64;
begin
  case GetTypeKind of
    // From ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      // Retrieve the current value.
      case GetTypeDataProp^.OrdType of
        otSByte : FInt64 := FData.FAsSByte;
        otSLong : FInt64 := FData.FAsSLong;
        otSWord : FInt64 := FData.FAsSWord;
        otUByte : FInt64 := FData.FAsUByte;
        otULong : FInt64 := FData.FAsULong;
        otUWord : FInt64 := FData.FAsUWord;
      end;

      // Cast the value.
      Result := Cast(ATypeInfo, FInt64);
    end;

    tkInt64 : Result := Cast(ATypeInfo, FData.FAsSInt64);
    tkQWord : Result := Cast(ATypeInfo, Int64(FData.FAsUInt64));

    // From floating point types.
    {$IFNDEF FPUNONE}
    tkFloat         :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := Cast(ATypeInfo, FData.FAsComp);
        ftCurr     : Result := Cast(ATypeInfo, FData.FAsCurr);
        ftDouble   : Result := Cast(ATypeInfo, FData.FAsDouble);
        ftExtended : Result := Cast(ATypeInfo, FData.FAsExtended);
        ftSingle   : Result := Cast(ATypeInfo, FData.FAsSingle);
      end;
    end;
    {$ENDIF}

    // From string types.
    tkAString       : Result := Cast(ATypeInfo, String(
                        FData.FValueData.GetAnsiString));
    tkSString       : Result := Cast(ATypeInfo, String(
                        FData.FValueData.GetShortString));
    tkUString       : Result := Cast(ATypeInfo,
                        FData.FValueData.GetUnicodeString);
    tkWString       : Result := Cast(ATypeInfo, FData.FValueData.GetWideString);

    // From other types.
    tkInterface     : Result := Cast(ATypeInfo, FData.FValueData.GetInterface);
    tkObject        : Result := Cast(ATypeInfo, FData.FAsObject);
    tkPointer       : Result := Cast(ATypeInfo, FData.FAsPointer);
  else
    raise EConvertError.Create('Cannot convert data of this type');
  end;

  // Finalize the result.
  Result.Create(ATypeInfo);
end;

/// <summary> Casts an extended value </summary>
/// <param name="ATypeInfo"> A pointer to a TTypeInfo record </param>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
function TValue.Cast(ATypeInfo: PTypeInfo; const AValue: Extended): TValue;
begin
  case ATypeInfo^.Kind of
    // To ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte : Result.FData.FAsSByte := ShortInt(Trunc(AValue) and $FF);
        otSLong : Result.FData.FAsSLong := LongInt(Trunc(AValue) and $FFFFFFFF);
        otSWord : Result.FData.FAsSWord := SmallInt(Trunc(AValue) and $FFFF);
        otUByte : Result.FData.FAsUByte := Byte(Trunc(AValue) and $FF);
        otULong : Result.FData.FAsSLong := LongWord(Trunc(AValue) and
                    $FFFFFFFF);
        otUWord : Result.FData.FAsUWord := Word(Trunc(AValue) and $FFFF);
      end;
    end;

    tkInt64 : Result.FData.FAsSInt64 := Trunc(AValue);
    tkQWord : Result.FData.FAsUInt64 := Trunc(AValue);

    // To floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result.FData.FAsComp := Trunc(AValue);
        ftCurr     : Result.FData.FAsCurr := AValue;
        ftDouble   : Result.FData.FAsDouble := Double(AValue);
        ftExtended : Result.FData.FAsExtended := Extended(AValue);
        ftSingle   : Result.FData.FAsSingle := AValue;
      end;
    end;
    {$ENDIF}

    // To string types.
    tkAString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetAnsiString(FloatToStr(AValue));
    end;

    tkSString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetShortString(FloatToStr(AValue));
    end;

    tkUString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetUnicodeString(String(FloatToStr(AValue)));
    end;

    tkWString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetWideString(String(FloatToStr(AValue)));
    end;
  else
    raise EConvertError.Create('Cannot cast the value');
  end;

  // Finalize the result.
  Result.Create(ATypeInfo);
end;

/// <summary> Casts an interface </summary>
/// <param name="ATypeInfo"> A pointer to a TTypeInfo record </param>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
function TValue.Cast(ATypeInfo: PTypeInfo; const AValue: IInterface): TValue;
begin
  case ATypeInfo^.Kind of
    tkInterface :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetInterface(AValue);
    end;
  else
    raise EConvertError.Create('Cannot cast the value');
  end;

  // Finalize the result.
  Result.Create(ATypeInfo);
end;

/// <summary> Casts an ordinal value </summary>
/// <param name="ATypeInfo"> A pointer to a TTypeInfo record </param>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
function TValue.Cast(ATypeInfo: PTypeInfo; const AValue: Int64): TValue;
begin
  case ATypeInfo^.Kind of
    // To ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte : Result.FData.FAsSByte := ShortInt(AValue and $FF);
        otSLong : Result.FData.FAsSLong := LongInt(AValue and $FFFFFFFF);
        otSWord : Result.FData.FAsSWord := SmallInt(AValue and $FFFF);
        otUByte : Result.FData.FAsUByte := Byte(AValue and $FF);
        otULong : Result.FData.FAsSLong := LongWord(AValue and $FFFFFFFF);
        otUWord : Result.FData.FAsUWord := Word(AValue and $FFFF);
      end;
    end;

    tkInt64 : Result.FData.FAsSInt64 := AValue;
    tkQWord : Result.FData.FAsUInt64 := QWord(AValue);

    // To floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result.FData.FAsComp := Comp(AValue);
        ftCurr     : Result.FData.FAsCurr := Currency(AValue);
        ftDouble   : Result.FData.FAsDouble := Double(AValue);
        ftExtended : Result.FData.FAsExtended := Extended(AValue);
        ftSingle   : Result.FData.FAsSingle := AValue;
      end;
    end;
    {$ENDIF}

    // To string types.
    tkAString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetAnsiString(IntToStr(AValue));
    end;

    tkSString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetShortString(IntToStr(AValue));
    end;

    tkUString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetUnicodeString(String(IntToStr(AValue)));
    end;

    tkWString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetWideString(String(IntToStr(AValue)));
    end;
  else
    raise EConvertError.Create('Cannot cast the value');
  end;

  // Finalize the result.
  Result.Create(ATypeInfo);
end;

/// <summary> Casts a pointer </summary>
/// <param name="ATypeInfo"> A pointer to a TTypeInfo record </param>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
function TValue.Cast(ATypeInfo: PTypeInfo; const AValue: Pointer): TValue;
begin
  case ATypeInfo^.Kind of
    // To ordinal types.
    {$IFDEF CPU32}
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      case GetTypeDataProp^.OrdType of
        otSLong : Result.FData.FAsSLong := LongInt(AValue);
        otULong : Result.FData.FAsSLong := LongWord(AValue);
      end;
    else
      raise EConvertError.Create('Cannot cast the value');
    end;
    {$ENDIF}

    {$HINTS OFF}
    tkInt64     : Result.FData.FAsSInt64 := Int64(AValue);
    tkQWord     : Result.FData.FAsSInt64 := QWord(AValue);
    {$HINTS ON}

    // Other types.
    tkClassRef  : Result.FData.FAsClass := TObject(AValue).ClassType;
    tkInterface : Result.FData.FAsPointer := AValue;
    tkObject    : Result.FData.FAsObject := AValue;
    tkPointer   : Result.FData.FAsPointer := AValue;
  else
    raise EConvertError.Create('Cannot cast the value');
  end;

  // Finalize the result.
  Result.Create(ATypeInfo);
end;

/// <summary> Casts a string </summary>
/// <param name="ATypeInfo"> A pointer to a TTypeInfo record </param>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
function TValue.Cast(ATypeInfo: PTypeInfo; const AValue: String): TValue;
var
  FInt64: Int64;
begin
  case ATypeInfo^.Kind of
    // To ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      FInt64 := StrToInt64(AnsiString(AValue));

      case GetTypeDataProp^.OrdType of
        otSByte : Result.FData.FAsSByte := ShortInt(FInt64 and $FF);
        otSLong : Result.FData.FAsSLong := LongInt(FInt64 and $FFFFFFFF);
        otSWord : Result.FData.FAsSWord := SmallInt(FInt64 and $FFFF);
        otUByte : Result.FData.FAsUByte := Byte(FInt64 and $FF);
        otULong : Result.FData.FAsSLong := LongWord(FInt64 and $FFFFFFFF);
        otUWord : Result.FData.FAsUWord := Word(FInt64 and $FFFF);
      end;
    end;

    tkInt64 : Result.FData.FAsSInt64 := StrToInt64(AnsiString(AValue));
    tkQWord : Result.FData.FAsUInt64 := StrToQWord(AnsiString(AValue));

    // To floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result.FData.FAsComp := StrToInt64(AnsiString(AValue));
        ftCurr     : Result.FData.FAsCurr := StrToCurr(AnsiString(AValue));
        ftDouble   : Result.FData.FAsDouble := StrToFloat(AnsiString(AValue));
        ftExtended : Result.FData.FAsExtended := StrToFloat(AnsiString(AValue));
        ftSingle   : Result.FData.FAsSingle := StrToFloat(AnsiString(AValue));
      end;
    end;
    {$ENDIF}

    // To string types.
    tkAString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetAnsiString(AnsiString(AValue));
    end;

    tkSString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetShortString(ShortString(AValue));
    end;

    tkUString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetUnicodeString(UnicodeString(AValue));
    end;

    tkWString :
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetWideString(WideString(AValue));
    end;
  else
    raise EConvertError.Create('Cannot cast the value');
  end;

  // Finalize the result.
  Result.Create(ATypeInfo);
end;

/// <summary> Constructs a new TValue </summary>
/// <param name="ATypeInfo"> A pointer to a TTypeInfo record </param>
constructor TValue.Create(ATypeInfo: PTypeInfo);
var
  DataObject: TValueDataObject;
begin
  // Store the type information pointer.
  FData.FTypeInfo := ATypeInfo;

  // Initialize the object responsible for managed types.
  case FData.FTypeInfo^.Kind of
    tkAString:
    begin
      DataObject := TValueDataObject.Create;
      DataObject.SetAnsiString('');

      FData.FValueData := DataObject;
    end;

    tkInterface,
    tkInterfaceRaw:
    begin
      FData.FValueData := TValueDataObject.Create;
      FData.FValueData.SetInterface(Nil);
    end;

    tkSString:
    begin
      FData.FValueData := TValueDataObject.Create;
      FData.FValueData.SetShortString('');
    end;

    tkUString:
    begin
      FData.FValueData := TValueDataObject.Create;
      FData.FValueData.SetUnicodeString('');
    end;

    tkWString:
    begin
      FData.FValueData := TValueDataObject.Create;
      FData.FValueData.SetWideString('');
    end;
  end;
end;

/// <summary> Extracts the raw data </summary>
/// <param name="ABuffer"> A pointer to the buffer </param>
procedure TValue.ExtractRawData(ABuffer: Pointer);
var
  RefCount: LongWord;
  RefCountPointer: Pointer;
begin
  case GetTypeKind of
    // String types.
    tkAString,
    tkUString:
    begin
      // Copy the string pointer to the destination.
      Move(FData.FValueData.GetReferenceToRawData^, ABuffer^,
        FData.FValueData.GetDataSize);

      // Retrieve the current reference count and increment it.
      RefCountPointer := Pointer(FData.FValueData.GetReferenceToRawData^) -
        (SizeOf(LongWord) * 2);
      RefCount := PLongWord(RefCountPointer)^ + 1;

      // Save the new reference count.
      Move(RefCount, RefCountPointer^, SizeOf(RefCount));
    end;
  else
    ExtractRawDataNoCopy(ABuffer);
  end;
end;

/// <summary> Extracts the raw data without making a copy of it </summary>
/// <param name="ABuffer"> A pointer to the buffer </param>
procedure TValue.ExtractRawDataNoCopy(ABuffer: Pointer);
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte : Move(FData.FAsSByte, ABuffer^, SizeOf(FData.FAsSByte));
        otSLong : Move(FData.FAsSLong, ABuffer^, SizeOf(FData.FAsSLong));
        otSWord : Move(FData.FAsSWord, ABuffer^, SizeOf(FData.FAsSWord));
        otUByte : Move(FData.FAsUByte, ABuffer^, SizeOf(FData.FAsUByte));
        otULong : Move(FData.FAsULong, ABuffer^, SizeOf(FData.FAsULong));
        otUWord : Move(FData.FAsUWord, ABuffer^, SizeOf(FData.FAsUWord));
      end;
    end;

    tkInt64 : Move(FData.FAsSInt64, ABuffer^, SizeOf(FData.FAsSInt64));
    tkQWord : Move(FData.FAsUInt64, ABuffer^, SizeOf(FData.FAsUInt64));

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Move(FData.FAsComp, ABuffer^, SizeOf(FData.FAsComp));
        ftCurr     : Move(FData.FAsCurr, ABuffer^, SizeOf(FData.FAsCurr));
        ftDouble   : Move(FData.FAsDouble, ABuffer^, SizeOf(FData.FAsDouble));
        ftExtended : Move(FData.FAsExtended, ABuffer^, SizeOf(
                       FData.FAsExtended));
        ftSingle   : Move(FData.FAsSingle, ABuffer^, SizeOf(FData.FAsSingle));
      end;
    end;
    {$ENDIF}

    // Other types.
    tkObject       : Move(FData.FAsObject, ABuffer^, SizeOf(FData.FAsObject));
    tkPointer      : Move(FData.FAsPointer, ABuffer^, SizeOf(FData.FAsPointer));
  else
    if Assigned(FData.FValueData) then
    begin
      Move(FData.FValueData.GetReferenceToRawData^, ABuffer^,
        FData.FValueData.GetDataSize);
    end
    else
    begin
      raise ENotImplemented.Create('Cannot extract the raw data');
    end;
  end;
end;

/// <summary> Builds a new TValue record from a given array </summary>
/// <param name="ATypeInfo"> The type information </param>
/// <param name="AValues"> The array elements </param>
/// <returns> Returns a TValue </returns>
class function TValue.FromArray(ATypeInfo: PTypeInfo; const AValues:
  array of TValue): TValue;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Builds a new TValue record from an ordinal value </summary>
/// <param name="ATypeInfo"> The type information </param>
/// <param name="AValue"> The ordinal value </param>
/// <returns> Returns a TValue </returns>
class function TValue.FromOrdinal(ATypeInfo: PTypeInfo;
  AValue: Int64): TValue;
begin
  // Store the value in the proper field.
  case ATypeInfo^.Kind of
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      case GetTypeData(ATypeInfo)^.OrdType of
        otSByte : Result.FData.FAsSByte := ShortInt(AValue);
        otSLong : Result.FData.FAsSLong := LongInt(AValue);
        otSWord : Result.FData.FAsSWord := SmallInt(AValue);
        otUByte : Result.FData.FAsUByte := Byte(AValue);
        otULong : Result.FData.FAsULong := LongWord(AValue);
        otUWord : Result.FData.FAsUWord := Word(AValue);
      end;
    end;

    tkInt64 : Result.FData.FAsSInt64 := AValue;
    tkQWord : Result.FData.FAsUInt64 := QWord(AValue);
  else
    raise EConvertError.Create('The type information is not for an ordinal');
  end;

  // Finalize the result.
  Result.Create(ATypeInfo);
end;

/// <summary> Builds a new TValue record from a TVarRec value </summary>
/// <param name="AValue"> The record </param>
/// <returns> Returns a TValue </returns>
class function TValue.FromVarRec(const AVarRec: TVarRec): TValue;
begin
  // Create the value based on the information in the record.
  case AVarRec.VType of
    vtAnsiString:
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetAnsiString(PAnsiString(AVarRec.VAnsiString)^);
    end;

    vtBoolean:
    begin
      Result.FData.FAsSByte := Ord(AVarRec.VBoolean);
    end;

    vtChar:
    begin
      Result.FData.FAsUByte := Ord(AVarRec.VChar);
    end;

    vtClass:
    begin
      Result.FData.FAsClass := AVarRec.VClass;
    end;

    vtCurrency:
    begin
      Result.FData.FAsCurr := AVarRec.VCurrency^;
    end;

    vtExtended:
    begin
      Result.FData.FAsExtended := AVarRec.VExtended^;
    end;

    vtInt64:
    begin
      Result.FData.FAsSInt64 := AVarRec.VInt64^;
    end;

    vtInteger:
    begin
      Result.FData.FAsSLong := AVarRec.VInteger;
    end;

    vtInterface:
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetInterface(IInterface(AVarRec.VInterface));
    end;

    vtObject:
    begin
      Result.FData.FAsObject := AVarRec.VObject;
    end;

    vtPChar:
    begin
      Result.FData.FAsPointer := AVarRec.VPChar;
    end;

    vtPWideChar:
    begin
      Result.FData.FAsPointer := AVarRec.VPWideChar;
    end;

    vtPointer:
    begin
      Result.FData.FAsPointer := AVarRec.VPointer;
    end;

    vtString:
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetShortString(AVarRec.VString^);
    end;

    vtUnicodeString:
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetUnicodeString(PUnicodeString(
        AVarRec.VUnicodeString)^);
    end;

    vtVariant:
    begin
      Result := FromVariant(AVarRec.VVariant^);
    end;

    vtWideChar:
    begin
      Result.FData.FAsUWord := Ord(AVarRec.VWideChar);
    end;

    vtWideString:
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetWideString(PWideString(AVarRec.VWideString)^);
    end;
  end;
end;

/// <summary> Builds a new TValue record from a Variant value </summary>
/// <param name="AValue"> The variant </param>
/// <returns> Returns a TValue </returns>
class function TValue.FromVariant(const AValue: Variant): TValue;
begin
  case VarType(AValue) of
    varBoolean:
    begin
      Result.FData.FAsSByte := Ord(Boolean(AValue));
    end;

    varByRef:
    begin
      {$HINTS OFF}
      Result.FData.FAsPointer := Pointer(NativeUInt(AValue));
      {$HINTS ON}
    end;

    varByte:
    begin
      Result.FData.FAsUByte := AValue;
    end;

    varDecimal,
    varDouble:
    begin
      Result.FData.FAsDouble := AValue;
    end;

    varLongWord:
    begin
      Result.FData.FAsULong := AValue;
    end;

    varNull:
    begin
      Result.Create(Nil);
    end;

    varQWord:
    begin
      Result.FData.FAsUInt64 := AValue;
    end;

    varRecord:
    begin
      {$HINTS OFF}
      Result.FData.FAsPointer := Pointer(NativeUInt(AValue));
      {$HINTS ON}
    end;

    varShortInt:
    begin
      Result.FData.FAsSByte := AValue;
    end;

    varSingle:
    begin
      Result.FData.FAsSingle := AValue;
    end;

    varSmallInt:
    begin
      Result.FData.FAsSWord := AValue;
    end;

    varString:
    begin

    end;

    varUString:
    begin
      Result.FData.FValueData := TValueDataObject.Create;
      Result.FData.FValueData.SetUnicodeString(AValue);
    end;

    varWord:
    begin
      Result.FData.FAsUWord := AValue;
    end;
  end;
end;

/// <summary> Returns an array element </summary>
/// <returns> Returns an array element <returns>
function TValue.GetArrayElement(AIndex: Integer): TValue;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns the array length </summary>
/// <returns> Returns the array length <returns>
function TValue.GetArrayLength: Integer;
begin
  Result := 0;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns the data size </summary>
/// <returns> Returns the data size <returns>
function TValue.GetDataSize: Integer;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte,
        otUByte : Result := SizeOf(Byte);
        otSLong,
        otULong : Result := SizeOf(LongWord);
        otSWord,
        otUWord : Result := SizeOf(Word);
      end;
    end;

    tkInt64,
    tkQWord : Result := 8;

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := SizeOf(Comp);
        ftCurr     : Result := SizeOf(Currency);
        ftDouble   : Result := SizeOf(Double);
        ftExtended : Result := SizeOf(Extended);
        ftSingle   : Result := SizeOf(Single);
      end;
    end;
    {$ENDIF}

    // Other types.
    tkClass,
    tkClassRef,
    tkObject,
    tkPointer      : Result := SizeOf(Pointer);
  else
    if Assigned(FData.FValueData) then
    begin
      Result := FData.FValueData.GetDataSize;
    end
    else
    begin
      raise ENotImplemented.Create('Cannot determine the data size');
    end;
  end;
end;

/// <summary> Returns an empty value </summary>
/// <returns> Returns an empty value <returns>
class function TValue.GetEmpty: TValue;
begin
  Result.Create(Nil);
end;

/// <summary> Returns whether the value is empty </summary>
/// <returns> Returns TRUE if empty, otherwise FALSE <returns>
function TValue.GetIsEmpty: Boolean;
begin
  Result := (GetTypeInfo = Nil);
end;

/// <summary> Returns a reference to the raw data </summary>
/// <returns> Returns a pointer <returns>
function TValue.GetReferenceToRawData: Pointer;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInteger,
    tkSet,
    tkUChar,
    tkWChar :
    begin
      case GetTypeDataProp^.OrdType of
        otSByte : Result := @FData.FAsSByte;
        otSLong : Result := @FData.FAsSLong;
        otSWord : Result := @FData.FAsSWord;
        otUByte : Result := @FData.FAsUByte;
        otULong : Result := @FData.FAsULong;
        otUWord : Result := @FData.FAsUWord;
      end;
    end;

    tkInt64 : Result := @FData.FAsSInt64;
    tkQWord : Result := @FData.FAsUInt64;

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case GetTypeDataProp^.FloatType of
        ftComp     : Result := @FData.FAsComp;
        ftCurr     : Result := @FData.FAsCurr;
        ftDouble   : Result := @FData.FAsDouble;
        ftExtended : Result := @FData.FAsExtended;
        ftSingle   : Result := @FData.FAsSingle;
      end;
    end;
    {$ENDIF}

    // Other types.
    tkClass,
    tkClassRef : Result := @FData.FAsClass;
    tkObject   : Result := @FData.FAsObject;
    tkPointer  : Result := @FData.FAsPointer;
  else
    if Assigned(FData.FValueData) then
    begin
      Result := FData.FValueData.GetReferenceToRawData;
    end
    else
    begin
      raise ENotImplemented.Create('Cannot retrieve a reference to the data');
    end;
  end;
end;

/// <summary> Returns a reference to the raw data for an element </summary>
/// <returns> Returns a pointer <returns>
function TValue.GetReferenceToRawArrayElement(AIndex: Integer): Pointer;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns the type information </summary>
/// <returns> Returns a pointer to a TTypeInfo record </returns>
function TValue.GetTypeInfo: PTypeInfo;
begin
  Result := FData.FTypeInfo;
end;

/// <summary> Returns the type kind </summary>
/// <returns> Returns a TTypeKind value </returns>
function TValue.GetTypeKind: TTypeKind;
begin
  Result := FData.FTypeInfo^.Kind;
end;

/// <summary> Returns the type data </summary>
/// <returns> Returns a pointer to a TTypeData record </returns>
function TValue.GetTypeDataProp: PTypeData;
begin
  Result := TypInfo.GetTypeData(FData.FTypeInfo);
end;

/// <summary> Assigns a value of type ansistring </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: AnsiString): TValue;
begin
  Result.Create(RttiTypeInfoAnsiString);
  Result.FData.FValueData := TValueDataObject.Create;
  Result.FData.FValueData.SetAnsiString(AValue);
end;

/// <summary> Assigns a value of type boolean </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: Boolean): TValue;
begin
  Result.Create(RttiTypeInfoBoolean);
  Result.FData.FAsSByte := Ord(AValue);
end;

/// <summary> Assigns a value of type currency </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: Currency): TValue;
begin
  Result.Create(RttiTypeInfoCurrency);
  Result.FData.FAsCurr := AValue;
end;

/// <summary> Assigns a value of type double </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: Double): TValue;
begin
  Result.Create(RttiTypeInfoDouble);
  Result.FData.FAsDouble := AValue;
end;

/// <summary> Assigns a value of type int64 </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: Int64): TValue;
begin
  Result.Create(RttiTypeInfoInt64);
  Result.FData.FAsSInt64 := AValue;
end;

/// <summary> Assigns a value of type integer </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: Integer): TValue;
begin
  Result.Create(RttiTypeInfoInteger);
  Result.FData.FAsSLong := AValue;
end;

/// <summary> Assigns a value of type QWord </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: QWord): TValue;
begin
  Result.Create(RttiTypeInfoQWord);
  Result.FData.FAsUInt64 := AValue;
end;

/// <summary> Assigns a value of type single </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: Single): TValue;
begin
  Result.Create(RttiTypeInfoSingle);
  Result.FData.FAsSingle := AValue;
end;

/// <summary> Assigns a value of type class </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: TClass): TValue;
begin
  Result.Create(AValue.ClassInfo);
  Result.FData.FAsClass := AValue;
end;

/// <summary> Assigns a value of type object </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: TObject): TValue;
begin
  Result.Create(AValue.ClassInfo);
  Result.FData.FAsObject := Pointer(AValue);
end;

/// <summary> Assigns a value of type TVarRec </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: TVarRec): TValue;
begin
  Result := FromVarRec(AValue);
end;

/// <summary> Assigns a value of type unicodestring </summary>
/// <param name="AValue"> The value </param>
/// <returns> Returns a TValue </returns>
class operator TValue.Implicit(const AValue: UnicodeString): TValue;
begin
  Result.Create(RttiTypeInfoUnicodeString);
  Result.FData.FValueData := TValueDataObject.Create;
  Result.FData.FValueData.SetUnicodeString(AValue);
end;

/// <summary> Returns whether the value is an array </summary>
/// <returns> Returns whether the value is an array </returns>
function TValue.IsArray: Boolean;
begin
  Result := (GetTypeKind = tkArray) or (GetTypeKind = tkDynArray);
end;

/// <summary> Returns whether the value is a class </summary>
/// <returns> Returns whether the value is a class </returns>
function TValue.IsClass: Boolean;
begin
  Result := (GetTypeKind = tkClass) or (GetTypeKind = tkClassRef);
end;

/// <summary> Returns whether the value is an instance of a class </summary>
/// <param name="AClass"> The class type </param>
/// <returns> Returns whether the value is an instance of the class </returns>
function TValue.IsInstanceOf(AClass: TClass): Boolean;
begin
  Result := (GetTypeKind = tkObject) and
            (TObject(FData.FAsObject).ClassType = AClass);
end;

/// <summary> Returns whether the value is an object </summary>
/// <returns> Returns whether the value is an object </returns>
function TValue.IsObject: Boolean;
begin
  Result := (GetTypeKind = tkObject);
end;

/// <summary> Returns whether the value is am ordinal </summary>
/// <returns> Returns whether the value is an ordinal </returns>
function TValue.IsOrdinal: Boolean;
begin
  case GetTypeKind of
    // Ordinal types.
    tkBool,
    tkChar,
    tkEnumeration,
    tkInt64,
    tkInteger,
    tkQWord,
    tkSet,
    tkUChar,
    tkWChar:
      Result := True;
  else
    Result := False;
  end;
end;

/// <summary> Returns whether the value is of a given type </summary>
/// <param name="ATypeInfo"> The type information </param>
/// <returns> Returns whether the value is of the given type </returns>
function TValue.IsType(ATypeInfo: PTypeInfo): Boolean;
begin
  Result := (GetTypeInfo = ATypeInfo);
end;

/// <summary> Creates a TValue from raw data </summary>
/// <param name="ABuffer"> The pointer to the raw data buffer </param>
/// <param name="ATypeInfo"> The type information </param>
/// <param name="AResult"> The created TValue </param>
class procedure TValue.Make(ABuffer: Pointer; ATypeInfo: PTypeInfo;
  out AResult: TValue);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Creates a TValue from raw data </summary>
/// <param name="AValue"> The pointer (integer) to the raw data buffer </param>
/// <param name="ATypeInfo"> The type information </param>
/// <param name="AResult"> The created TValue </param>
class procedure TValue.Make(AValue: NativeInt; ATypeInfo: PTypeInfo;
  out AResult: TValue);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Creates a TValue from raw data without making a copy </summary>
/// <param name="ABuffer"> The pointer to the raw data buffer </param>
/// <param name="ATypeInfo"> The type information </param>
/// <param name="AResult"> The created TValue </param>
class procedure TValue.MakeWithoutCopy(ABuffer: Pointer; ATypeInfo: PTypeInfo;
  out AResult: TValue);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Sets the value of an array element </summary>
/// <param name="AIndex"> The array index </param>
/// <param name="AValue"> The value </param>
procedure TValue.SetArrayElement(AIndex: Integer; const AValue: TValue);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Converts the value to a string </summary>
/// <returns> Returns a string </returns>
function TValue.ToString: string;
begin
  Result := AsString;
end;

/// <summary> Tries to convert the value to an ordinal </summary>
/// <param name="AResult"> A pointer to a result variable </param>
/// <returns> Returns TRUE on success, otherwise FALSE </returns>
function TValue.TryAsOrdinal(out AResult: Int64): Boolean;
begin
  try
    AResult := AsOrdinal;
    Result := True;
  except
    on Exception do
    begin
      Result := False;
    end;
  end;
end;

/// <summary> Tries to cast the value to a given type </summary>
/// <param name="AResult"> A pointer to a result variable </param>
/// <returns> Returns TRUE on success, otherwise FALSE </returns>
function TValue.TryCast(ATypeInfo: PTypeInfo; out AResult: TValue): Boolean;
begin
  try
    AResult := Cast(ATypeInfo);
    Result := True;
  except
    on Exception do
    begin
      Result := False;
    end;
  end;
end;
