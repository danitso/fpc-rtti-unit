/// <summary> Constructs a new instance of the class </summary>
constructor TRttiParameter.Create(const AParent: TRttiObject;
  const AName: String; const AFlags: TParamFlags; const ATypeInfo: PTypeInfo);
begin
  // Invoke the parent constructor.
  inherited Create;

  // Initialize the properties.
  FFlags := AFlags;
  FHandle := ATypeInfo;
  FName := AName;
  FParent := AParent;
end;

/// <summary> Returns the attributes </summary>
function TRttiParameter.GetAttributes: TArray<TCustomAttribute>;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the parameter invokation flags </summary>
function TRttiParameter.GetFlags: TParamFlags;
begin
  Result := FFlags;
end;

/// <summary> Specifies the parameter name </summary>
function TRttiParameter.GetName: string;
begin
  Result := FName;
end;

/// <summary> Specifies the parameter's type </summary>
function TRttiParameter.GetParamType: TRttiType;
begin
  Result := TRttiContext.Create.GetType(FHandle);
end;

/// <summary> Returns the string representation of the RTTI parameter object
/// </summary>
function TRttiParameter.ToString: AnsiString;
begin
  Result := AnsiString(FName);
end;
