/// <summary> Constructs a new TRttiManagedField instance </summary>
constructor TRttiManagedField.Create(const AParent: TRttiObject;
  const AField: PManagedField);
begin
  // Invoke the parent constructor.
  inherited Create;

  // Initialize the fields.
  FHandle := AField;
  FParent := AParent;
  FRttiDataSize := SizeOf(TManagedField);
end;

/// <summary> Not documented </summary>
function TRttiManagedField.GetAttributes: TCustomAttributeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the offset of the field in the instance </summary>
function TRttiManagedField.GetFieldOffset: Integer;
begin
  Result := PManagedField(FHandle)^.FldOffset;
end;

/// <summary> Specifies the managed field's type </summary>
function TRttiManagedField.GetFieldType: TRttiType;
begin
  Result := TRttiContext.Create.GetType(PManagedField(FHandle)^.TypeRef);
end;
