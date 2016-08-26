/// <summary> Constructs a new TRttiInstanceType instance </summary>
constructor TRttiInstanceType.Create(const ATypeInfo: PTypeInfo;
  const AParent: TRttiObject = Nil);
begin
  // Invoke the parent constructor.
  inherited;

  // Load the properties.
  LoadProperties;
end;

/// <summary> Destroys the TRttiInstanceType instance </summary>
destructor TRttiInstanceType.Destroy;
var
  I: Integer;
begin
  // Clean up.
  for I := 0 to High(FDeclaredIndexedProperties) do
  begin
    FDeclaredIndexedProperties[I].Free;
  end;

  for I := 0 to High(FDeclaredProperties) do
  begin
    FDeclaredProperties[I].Free;
  end;

  SetLength(FDeclaredIndexedProperties, 0);
  SetLength(FDeclaredProperties, 0);

  // Invoke the parent destructor.
  inherited;
end;

/// <summary> Returns a list of attributes associated with the class type
/// </summary>
function TRttiInstanceType.GetAttributes: TCustomAttributeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the ancestor class </summary>
function TRttiInstanceType.GetBaseTyped: TRttiInstanceType;
begin
  Result := (TRttiPool.GetInstance.GetType(FTypeData^.ParentInfo) as
    TRttiInstanceType);
end;

/// <summary> Returns a list of all the fields declared in the reflected class
/// type </summary>
function TRttiInstanceType.GetDeclaredFields: TRttiFieldArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Gets the interfaces implemented by the type reflected with the
/// current TRttiInstanceType instance (as an array) </summary>
function TRttiInstanceType.GetDeclaredImplementedInterfaces: TRttiInterfaceTypeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Gets the indexed properties declared in the type reflected by the
/// current TRttiInstanceType instance (as an array) </summary>
function TRttiInstanceType.GetDeclaredIndexedProperties: TRttiIndexedPropertyArray;
begin
  Result := Copy(FDeclaredIndexedProperties);
end;

/// <summary> Returns a list of all the methods declared in the reflected class
/// type </summary>
function TRttiInstanceType.GetDeclaredMethods: TRttiMethodArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns a list of all the properties declared in the reflected
/// class type </summary>
function TRttiInstanceType.GetDeclaredProperties: TRttiPropertyArray;
begin
  Result := Copy(FDeclaredProperties);
end;

/// <summary> Specifies the name of the unit in which the class type is declared
/// </summary>
function TRttiInstanceType.GetDeclaringUnitName: string;
begin
  Result := String(FTypeData^.UnitName);
end;

/// <summary> Gets the interfaces implemented by the type reflected with the
/// current TRttiInstanceType instance or its ancestors (as an array) </summary>
function TRttiInstanceType.GetImplementedInterfaces: TRttiInterfaceTypeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the reflected class reference </summary>
function TRttiInstanceType.GetMetaclassType: TClass;
begin
  Result := FTypeData^.ClassType;
end;

/// <summary> Not documented </summary>
function TRttiInstanceType.GetVmtSize: Integer;
begin
  Result := 0;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Loads the properties </summary>
procedure TRttiInstanceType.LoadProperties;
var
  I         : Integer;
  Index     : Integer;
  PropList  : PPropList;
  PropCount : LongInt;
begin
  // Invoke the parent constructor.
  inherited;

  // Load the properties.
  PropCount := GetPropList(GetHandle, PropList);

  for I := 0 to PropCount - 1 do
  begin
    if (PropList^[I]^.PropProcs and 64 = 0) then
    begin
      Index := Length(FDeclaredProperties);
      SetLength(FDeclaredProperties, Index + 1);
      FDeclaredProperties[Index] := TRttiInstanceProperty.Create(Self,
        PropList^[I]);
    end
    else
    begin
      Index := Length(FDeclaredIndexedProperties);
      SetLength(FDeclaredIndexedProperties, Index + 1);
      FDeclaredIndexedProperties[Index] := TRttiIndexedProperty.Create(Self,
        PropList^[I]);
    end;
  end;

  { Clean up }
  FreeMem(PropList);
end;
