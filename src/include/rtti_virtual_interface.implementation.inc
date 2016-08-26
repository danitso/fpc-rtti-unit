/// <summary> Creates and initializes a TVirtualInterface instance </summary>
constructor TVirtualInterface.Create(PIID: PTypeInfo);
begin
  // Invoke the parent constructor.
  inherited Create;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Creates and initializes a TVirtualInterface instance </summary>
constructor TVirtualInterface.Create(PIID: PTypeInfo;
  InvokeEvent: TVirtualInterfaceInvokeEvent);
begin
  // Invoke the parent constructor.
  inherited Create;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Destroys a TVirtualInterface instance </summary>
destructor TVirtualInterface.Destroy;
begin
  // Invoke the parent destructor.
  inherited;
end;
