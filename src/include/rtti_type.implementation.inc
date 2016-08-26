/// <summary> Constructs a new instance of the class </summary>
constructor TRttiType.Create(const ATypeInfo: PTypeInfo;
  const AParent: TRttiObject = Nil);
begin
  // Invoke the parent constructor.
  inherited Create;

  // Initialize the fields.
  FHandle := ATypeInfo;
  FParent := AParent;
  FRttiDataSize := SizeOf(TTypeInfo);
  FTypeData := GetTypeData(ATypeInfo);
end;

/// <summary> Casts the TRttiType instance to a TRttiInstanceType instance
/// </summary>
function TRttiType.GetAsInstance: TRttiInstanceType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Casts the TRttiType instance to a TRttiOrdinalType instance
/// </summary>
function TRttiType.GetAsOrdinal: TRttiOrdinalType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Cast the TRttiType instance to a TRttiRecordType instance
/// </summary>
function TRttiType.GetAsRecord: TRttiRecordType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Casts the TRttiType instance to a TRttiSetType instance </summary>
function TRttiType.GetAsSet: TRttiSetType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetAttributes: TCustomAttributeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the base type </summary>
function TRttiType.GetBaseType: TRttiType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns a list of all the fields declared in the reflected type
/// </summary>
function TRttiType.GetDeclaredFields: TRttiFieldArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Gets the indexed properties declared in the type reflected by the
/// current TRttiType instance (as an array) </summary>
function TRttiType.GetDeclaredIndexedProperties: TRttiIndexedPropertyArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns a list of all the methods declared in the reflected type
/// </summary>
function TRttiType.GetDeclaredMethods: TRttiMethodArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns a list of all the properties declared in the reflected
/// type </summary>
function TRttiType.GetDeclaredProperties: TRttiPropertyArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetField(const AName: string): TRttiField;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetFields: TRttiFieldArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies a pointer to a TTypeInfo structure </summary>
function TRttiType.GetHandle: PTypeInfo;
begin
  Result := PTypeInfo(FHandle);
end;

/// <summary> For internal use only </summary>
function TRttiType.GetHFAElementCount: Integer;
begin
  Result := 0;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> For internal use only </summary>
function TRttiType.GetHFAElementType: TRttiFloatType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetIndexedProperties: TRttiIndexedPropertyArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetIndexedProperty(
  const AName: string): TRttiIndexedProperty;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> For internal use only </summary>
function TRttiType.GetIsHFA: Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Checks whether the TRttiType instance is actually a
/// TRttiInstanceType instance </summary>
function TRttiType.GetIsInstance: Boolean;
begin
  Result := (GetTypeKind = tkObject);
end;

/// <summary> Specifies whether the reflected type is managed </summary>
function TRttiType.GetIsManaged: Boolean;
begin
  case GetTypeKind of
    tkAString,
    tkDynArray,
    tkUString,
    tkInterface,
    tkInterfaceRaw: Result := True;
  else
    Result := False;
  end;
end;

/// <summary> Checks whether the TRttiType instance is actually a
/// TRttiOrdinalType instance </summary>
function TRttiType.GetIsOrdinal: Boolean;
begin
  case GetTypeKind of
    tkBool,
    tkChar,
    tkEnumeration,
    tkInt64,
    tkInteger,
    tkQWord,
    tkSet,
    tkUChar,
    tkWChar: Result := True;
  else
    Result := False;
  end;
end;

/// <summary> Checks whether the TRttiType instance reflects a public type
/// </summary>
function TRttiType.GetIsPublicType: Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Checks whether the TRttiType instance is actually a
/// TRttiRecordType instance </summary>
function TRttiType.GetIsRecord: Boolean;
begin
  Result := (GetTypeKind = tkRecord);
end;

/// <summary> Checks whether the TRttiType instance is actually a TRttiSetType
/// instance </summary>
function TRttiType.GetIsSet: Boolean;
begin
  Result := (GetTypeKind = tkSet);
end;

/// <summary> Not documented </summary>
function TRttiType.GetMethod(const AName: string): TRttiMethod;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetMethods: TRttiMethodArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetMethods(const AName: string): TRttiMethodArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetName: string;
begin
  Result := String(GetHandle^.Name);
end;

/// <summary> Not documented </summary>
function TRttiType.GetProperties: TRttiPropertyArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiType.GetProperty(const AName: string): TRttiProperty;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the qualified name of the reflected type </summary>
function TRttiType.GetQualifiedName: string;
begin
  // Initialize the result.
  Result := '';

  // Determine the name of the unit the type is declared in.
  case GetTypeKind of
    tkClass        : Result := String(FTypeData^.UnitName);
    tkDynArray     : Result := String(FTypeData^.DynUnitName);
    tkInterface    : Result := String(FTypeData^.IntfUnit);
    tkInterfaceRaw : Result := String(FTypeData^.RawIntfUnit);
  else
    {$IFDEF RTTI_ENABLE_SYSTEM_TYPES_WORKAROUND}
      if (FParent is TRttiInstanceType) and
         (TRttiInstanceType(FParent).MetaclassType = TRttiSystemTypes) then
      begin
        Result := 'System';
      end;
    {$ENDIF}
  end;

  if (Result <> '') then
  begin
    Result := Result + '.';
  end;

  // Append the type name in order for it to become a fully qualified name.
  Result := Result + String(GetHandle^.Name);
end;

/// <summary> Specifies the reflected type's kind </summary>
function TRttiType.GetTypeKind: TTypeKind;
begin
  Result := GetHandle^.Kind;
end;

/// <summary> Specifies the size of the reflected type </summary>
function TRttiType.GetTypeSize: Integer;
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
      case FTypeData^.OrdType of
        otSByte,
        otUByte    : Result := SizeOf(Byte);
        otSLong,
        otULong    : Result := SizeOf(LongWord);
        otSWord,
        otUWord    : Result := SizeOf(Word);
      end;
    end;

    tkInt64,
    tkQWord        : Result := SizeOf(QWord);

    // Floating point types.
    {$IFNDEF FPUNONE}
    tkFloat        :
    begin
      case FTypeData^.FloatType of
        ftComp     : Result := SizeOf(Comp);
        ftCurr     : Result := SizeOf(Currency);
        ftDouble   : Result := SizeOf(Double);
        ftExtended : Result := SizeOf(Extended);
        ftSingle   : Result := SizeOf(Single);
      end;
    end;
    {$ENDIF}

    // String types.
    tkAString      : Result := SizeOf(AnsiString);
    tkSString      : Result := SizeOf(ShortString);
    tkUString      : Result := SizeOf(UnicodeString);
    tkWString      : Result := SizeOf(WideString);

    // Other types.
    tkClass,
    tkClassRef     : Result := SizeOf(TClass);
    tkMethod       : Result := SizeOf(TMethod);
    tkObject,
    tkInterface,
    tkInterfaceRaw,
    tkPointer,
    tkProcedure    : Result := SizeOf(Pointer);
  else
    raise ENotImplemented.Create(
      'Cannot determine the size of an unknown type');
  end;
end;

/// <summary> Not yet documented </summary>
function TRttiType.ToString: AnsiString;
begin
  Result := AnsiString(GetQualifiedName);
end;
