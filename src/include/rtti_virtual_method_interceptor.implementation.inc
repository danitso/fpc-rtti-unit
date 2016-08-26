/// <summary> Creates a new instance of the TVirtualMethodInterceptor class
/// </summary>
constructor TVirtualMethodInterceptor.Create(AClass: TClass);
begin
  // Invoke the parent constructor.
  inherited Create;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> The destructor of the class </summary>
destructor TVirtualMethodInterceptor.Destroy;
begin
  // Invoke the parent destructor.
  inherited;
end;

/// <summary> Changes the run-time class of the specified class instance
/// </summary>
procedure TVirtualMethodInterceptor.Proxify(AInstance: TObject);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Restores the original run-time class of the instance </summary>
procedure TVirtualMethodInterceptor.Unproxify(AInstance: TObject);
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
