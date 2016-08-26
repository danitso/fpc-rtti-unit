/// <summary> Creates a new TRttiProperty instance </summary>
constructor TRttiIndexedProperty.Create(const AParent: TRttiObject;
  const APropInfo: PPropInfo);
begin
  // Invoke the parent constructor.
  inherited Create;

  // Initialize the properties.
  FHandle := APropInfo;
  FParent := AParent;
  FRttiDataSize := SizeOf(TPropInfo);
end;

/// <summary> Not documented </summary>
function TRttiIndexedProperty.GetAttributes: TCustomAttributeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create('Not implemented');
end;

/// <summary> For internal use </summary>
function TRttiIndexedProperty.GetHandle: PArrayPropInfo;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Indicates whether the indexed property is default </summary>
function TRttiIndexedProperty.GetIsDefault: Boolean;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Indicates whether the property is readable </summary>
function TRttiIndexedProperty.GetIsReadable: Boolean;
begin
  Result := (PPropInfo(FHandle)^.GetProc <> Nil);
end;

/// <summary> Indicates whether the property is writable </summary>
function TRttiIndexedProperty.GetIsWritable: Boolean;
begin
  Result := (PPropInfo(FHandle)^.SetProc <> Nil);
end;

/// <summary> Specifies the property name </summary>
function TRttiIndexedProperty.GetName: string;
begin
  Result := String(PPropInfo(FHandle)^.Name);
end;

/// <summary> Represents the data type for the indexed property </summary>
function TRttiIndexedProperty.GetPropertyType: TRttiType;
begin
  Result := TRttiPool.GetInstance.GetType(PPropInfo(FHandle)^.PropType);
end;

/// <summary> Represents the method used to read the property </summary>
function TRttiIndexedProperty.GetReadMethod: TRttiMethod;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns the value of a specific element from the collection
/// represented by this TRttiIndexedProperty instance </summary>
function TRttiIndexedProperty.GetValue(Instance: Pointer;
  const Args: array of TValue): TValue;
begin
  Result := False;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Represents the method used to write the property </summary>
function TRttiIndexedProperty.GetWriteMethod: TRttiMethod;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Sets the value of a specific element from the collection
/// represented by this TRttiIndexedProperty instance </summary>
procedure TRttiIndexedProperty.SetValue(Instance: Pointer;
  const Args: array of TValue; const Value: TValue);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns the string representation of this TRttiIndexedProperty
/// instance </summary>
function TRttiIndexedProperty.ToString: AnsiString;
begin
  Result := '';
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
