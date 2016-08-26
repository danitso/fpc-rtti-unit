/// <summary> Creates a new TRttiRecordType instance </summary>
constructor TRttiRecordType.Create(const ATypeInfo: PTypeInfo;
  const AParent: TRttiObject = Nil);
var
  Field: PManagedField;
  I: Integer;
begin
  // Invoke the parent constructor.
  inherited;

  // Load the managed fields.
  SetLength(FManagedFields, FTypeData^.ManagedFldCount);

  Field := PManagedField(PInteger(@FTypeData^.ManagedFldCount) + SizeOf(
    Integer));

  for I := 0 to FTypeData^.ManagedFldCount - 1 do
  begin
    FManagedFields[I] := TRttiManagedField.Create(Self, Field);
    Field := Field + SizeOf(TManagedField);
  end;
end;

/// <summary> Destroys the TRttiRecordType instance </summary>
destructor TRttiRecordType.Destroy;
var
  I: Integer;
begin
  // Clean up.
  for I := 0 to High(FManagedFields) do
  begin
    FManagedFields[I].Free;
  end;

  SetLength(FManagedFields, 0);

  // Invoke the parent destructor.
  inherited;
end;

/// <summary> Not documented </summary>
function TRttiRecordType.GetAttributes: TArray<TCustomAttribute>;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiRecordType.GetDeclaredFields: TArray<TRttiField>;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Not documented </summary>
function TRttiRecordType.GetDeclaredMethods: TArray<TRttiMethod>;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns a list of all the managed fields that are part of the
/// reflected record type </summary>
function TRttiRecordType.GetManagedFields: TArray<TRttiManagedField>;
begin
  Result := Copy(FManagedFields);
end;
