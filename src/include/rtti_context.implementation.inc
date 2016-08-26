/// <summary> Initializes the TRttiContext instance </summary>
class function TRttiContext.Create: TRttiContext;
begin
  Result.FContextToken := TRttiPool.GetInstance;
end;

/// <summary> Not documented </summary>
class procedure TRttiContext.DropContext;
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Returns a TRttiType instance for the queried type name </summary>
function TRttiContext.FindType(const AQualifiedName: string): TRttiType;
begin
  Result := IRttiPool(FContextToken).FindType(AQualifiedName);
end;

/// <summary> Releases the TRttiContext instance </summary>
procedure TRttiContext.Free;
begin
  FContextToken := Nil;
end;

/// <summary> Returns a list of TRttiPackage describing all loaded packages
/// </summary>
function TRttiContext.GetPackages: TRttiPackageArray;
begin
  SetLength(Result, 0);
  raise EInsufficientRtti.Create(RTTI_E_INSUFFICIENT_RTTI);
end;

/// <summary> Returns a TRttiType instance used to reflect the given type
/// </summary>
function TRttiContext.GetType(ATypeInfo: Pointer): TRttiType;
begin
  Result := IRttiPool(FContextToken).GetType(ATypeInfo);
end;

/// <summary> Returns a TRttiType instance used to reflect the given type
/// </summary>
function TRttiContext.GetType(AClass: TClass): TRttiType;
begin
  Result := IRttiPool(FContextToken).GetType(AClass);
end;

/// <summary> Returns a list of TRttiType instances used to reflect all Delphi
/// types that provide type information </summary>
function TRttiContext.GetTypes: TRttiTypeArray;
begin
  Result := IRttiPool(FContextToken).GetTypes;
end;

/// <summary> Not documented </summary>
class procedure TRttiContext.KeepContext;
begin
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
