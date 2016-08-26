/// <summary> Creates a new instance of the class </summary>
constructor TRawVirtualClass.Create(Guids: TGUIDArray;
  VTable: TRawVirtualClass.TVTable);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Destroys the class instance </summary>
destructor TRawVirtualClass.Destroy;
begin
  // Invoke the parent destructor.
  inherited;
end;

/// <summary> Returns the instance of TRawVirtualClass that implements the
/// interface given through its GUID </summary>
class function TRawVirtualClass.GetInstanceFromInterface(
  Intf: Pointer): TRawVirtualClass;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
