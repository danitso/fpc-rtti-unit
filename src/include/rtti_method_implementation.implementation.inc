/// <summary> Throws an EInvalidOpException </summary>
constructor TMethodImplementation.Create;
begin
  raise EInvalidOpException.Create('Invalid operation');
end;

/// <summary> Not yet documented </summary>
constructor TMethodImplementation.Create(AUserData: Pointer;
  AInvokeInfo: TInvokeInfo; const ACallback: TMethodImplementationCallback);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Gets an untyped pointer to the executable code of the method
/// </summary>
function TMethodImplementation.GetCodeAddress: Pointer;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
