/// <summary> Creates a new TRttiPool instance </summary>
constructor TRttiPool.Create;
{$IFDEF RTTI_ENABLE_SYSTEM_TYPES_WORKAROUND}
var
  I: Integer;
  InstanceType: TRttiInstanceType;
  Properties: TRttiPropertyArray;
{$ENDIF}
begin
  // Invoke the parent constructor.
  inherited;

  // Store a reference to this instance as we only want to create one at a time.
  FInstance := Self;

  // Load the system types using a workaround if necessary.
  {$IFDEF RTTI_ENABLE_SYSTEM_TYPES_WORKAROUND}
  InstanceType := (GetType(TRttiSystemTypes) as TRttiInstanceType);
  Properties := InstanceType.GetDeclaredProperties;

  for I := 0 to High(Properties) do
  begin
    Properties[I].GetPropertyType;
  end;
  {$ENDIF}
end;

/// <summary> Destroys the TRttiPool instance </summary>
destructor TRttiPool.Destroy;
var
  I: Integer;
begin
  // Clean up if the context count has reached zero as there is no longer any
  // reason to keep the RTTI objects in memory.
  for I := 0 to High(FPackages) do
  begin
    FPackages[I].Free;
  end;

  for I := 0 to High(FTypes) do
  begin
    FTypes[I].Free;
  end;

  SetLength(FPackages, 0);
  SetLength(FTypes, 0);

  FInstance := Nil;

  // Invoke the parent destructor.
  inherited;
end;

/// <summary> Returns a TRttiType instance for the queried type name </summary>
/// <param name="AQualifiedName"> The fully qualified type name </param>
/// <returns> Returns a TRttiType instance for the queried type name </returns>
function TRttiPool.FindType(const AQualifiedName: string): TRttiType;
var
  Cls: TClass;
  I: Integer;
  Name: string;
begin
  // Initialize the result to avoid any errors.
  Result := Nil;

  // Determine if the type has already been found and processed in which case
  // its instance should be returned.
  for I := 0 to High(FTypes) do
  begin
    if (UnicodeCompareText(FTypes[I].QualifiedName, AQualifiedName) = 0) then
    begin
      Result := FTypes[I];
      Break;
    end;
  end;

  // Determine if the type is a class which has been registered using the
  // RegisterClass method from the Classes unit.
  I := Pos('.', AQualifiedName);

  if (I <> 0) then
  begin
    Name := Copy(AQualifiedName, I + 1, Length(AQualifiedName));

    try
      Cls := FindClass(AnsiString(Name));
    except
      on Exception do
      begin
        Exit;
      end;
    end;

    // Create and return a new TRttiType instance if the qualified name matches
    // the argument.
    Name := String(Cls.UnitName) + '.' + Name;

    if (UnicodeCompareText(AQualifiedName, Name) = 0) then
    begin
      Result := LoadType(Cls.ClassInfo);
    end;
  end;
end;

/// <summary> Returns a TRttiPool instance </summary>
class function TRttiPool.GetInstance: IRttiPool;
begin
  if not Assigned(FInstance) then
  begin
    TRttiPool.Create;
  end;

  Result := FInstance;
end;

/// <summary> Returns a list of TRttiPackage describing all loaded packages
/// </summary>
function TRttiPool.GetPackages: TRttiPackageArray;
begin
  Result := Copy(FPackages);
end;

/// <summary> Returns a TRttiType instance for the given type </summary>
/// <param name="ATypeInfo"> The type information </param>
/// <returns> Returns a TRttiType instance for the given type </returns>
function TRttiPool.GetType(const ATypeInfo: Pointer;
  const AParent: TRttiObject = Nil): TRttiType;
var
  I: Integer;
begin
  // Determine if a type with that handle (type information pointer) has already
  // been added to the array in which case it should be returned.
  for I := 0 to High(FTypes) do
  begin
    if (FTypes[I].Handle = ATypeInfo) then
    begin
      Result := FTypes[I];
      Exit;
    end;
  end;

  // No type with that handle was found so try to load and parse the type
  // information.
  Result := LoadType(ATypeInfo, AParent);
end;

/// <summary> Returns a TRttiType instance for the given type </summary>
/// <param name="AClass"> A class reference </param>
function TRttiPool.GetType(const AClass: TClass;
  const AParent: TRttiObject = Nil): TRttiType;
begin
  Result := GetType(AClass.ClassInfo, AParent);
end;

/// <summary> Returns a list of TRttiType instances used to reflect all Delphi
/// types that provide type information </summary>
function TRttiPool.GetTypes: TRttiTypeArray;
begin
  Result := Copy(FTypes);
end;

/// <summary> Loads a type based on a pointer to the type information </summary>
/// <param name="ATypeInfo"> A pointer to the type information </param>
/// <returns> Returns a TRttiType instance on success, otherwise Nil </returns>
function TRttiPool.LoadType(const ATypeInfo: Pointer;
  const AParent: TRttiObject = Nil): TRttiType;
begin
  // Create an instance of the class which provides information about this data
  // type.
  case PTypeInfo(ATypeInfo)^.Kind of
    tkAString      : Result := TRttiAnsiStringType.Create(ATypeInfo, AParent);
    tkArray        : Result := TRttiArrayType.Create(ATypeInfo, AParent);
    tkClassRef     : Result := TRttiClassRefType.Create(ATypeInfo, AParent);
    tkDynArray     : Result := TRttiDynamicArrayType.Create(ATypeInfo, AParent);
    tkEnumeration  : Result := TRttiEnumerationType.Create(ATypeInfo, AParent);
    tkFloat        : Result := TRttiFloatType.Create(ATypeInfo, AParent);
    tkMethod       : Result := TRttiMethodType.Create(ATypeInfo, AParent);
    tkPointer      : Result := TRttiPointerType.Create(ATypeInfo, AParent);
    tkProcVar      : Result := TRttiProcedureType.Create(ATypeInfo, AParent);
    tkRecord       : Result := TRttiRecordType.Create(ATypeInfo, AParent);
    tkSet          : Result := TRttiSetType.Create(ATypeInfo, AParent);

    tkBool,
    tkChar,
    tkInteger,
    tkUChar,
    tkWChar        : Result := TRttiOrdinalType.Create(ATypeInfo, AParent);

    tkInt64,
    tkQWord        : Result := TRttiInt64Type.Create(ATypeInfo, AParent);

    tkInterface,
    tkInterfaceRaw : Result := TRttiInterfaceType.Create(ATypeInfo, AParent);

    tkClass,
    tkObject       : Result := TRttiInstanceType.Create(ATypeInfo, AParent);

    tkSString,
    tkUString,
    tkWString      : Result := TRttiStringType.Create(ATypeInfo, AParent);
  else
    raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
  end;

  // Add the instance to the array of types.
  SetLength(FTypes, Length(FTypes) + 1);
  FTypes[High(FTypes)] := Result;
end;

/// <summary> Loads all available types </summary>
class procedure TRttiPool.LoadTypes;
var
  Ctx: TRttiContext;
begin
  Ctx := TRttiContext.Create;

  {$IFDEF RTTI_ENABLE_SYSTEM_TYPES_WORKAROUND}
    RttiTypeInfoAnsiString := Ctx.FindType('System.AnsiString').Handle;
    RttiTypeInfoBoolean := Ctx.FindType('System.Boolean').Handle;
    RttiTypeInfoCurrency := Ctx.FindType('System.Currency').Handle;
    RttiTypeInfoDouble := Ctx.FindType('System.Double').Handle;
    RttiTypeInfoInt64 := Ctx.FindType('System.Int64').Handle;
    RttiTypeInfoInteger := Ctx.FindType('System.LongInt').Handle;
    RttiTypeInfoQWord := Ctx.FindType('System.QWord').Handle;
    RttiTypeInfoSingle := Ctx.FindType('System.Single').Handle;
    RttiTypeInfoUnicodeString := Ctx.FindType('System.UnicodeString').Handle;
  {$ELSE}
    RttiTypeInfoAnsiString := Ctx.GetType(TypeInfo(AnsiString)).Handle;
    RttiTypeInfoBoolean := Ctx.GetType(TypeInfo(Boolean)).Handle;
    RttiTypeInfoCurrency := Ctx.GetType(TypeInfo(Currency)).Handle;
    RttiTypeInfoDouble := Ctx.GetType(TypeInfo(Double)).Handle;
    RttiTypeInfoInt64 := Ctx.GetType(TypeInfo(Int64)).Handle;
    RttiTypeInfoInteger := Ctx.GetType(TypeInfo(Integer)).Handle;
    RttiTypeInfoQWord := Ctx.GetType(TypeInfo(QWord)).Handle;
    RttiTypeInfoSingle := Ctx.GetType(TypeInfo(Single)).Handle;
    RttiTypeInfoUnicodeString := Ctx.GetType(TypeInfo(UnicodeString)).Handle;
  {$ENDIF}
end;
