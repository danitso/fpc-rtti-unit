/// <summary> Destroys the class instance </summary>
destructor TRttiInvokableType.Destroy;
var
  I: Integer;
begin
  // Clean up.
  for I := 0 to High(FParameters) do
  begin
    FParameters[I].Free;
  end;

  SetLength(FParameters, 0);

  // Invoke the parent destructor.
  inherited;
end;

/// <summary> Specifies the calling convention </summary>
function TRttiInvokableType.GetCallingConvention: TCallConv;
begin
  Result := FCallingConvention;
end;

/// <summary> Specifies the parameters </summary>
function TRttiInvokableType.GetParameters: TRttiParameterArray;
begin
  Result := Copy(FParameters);
end;

/// <summary> Specifies the return type </summary>
function TRttiInvokableType.GetReturnType: TRttiType;
begin
  Result := FReturnType;
end;

/// <summary> Not yet documented </summary>
function TRttiInvokableType.ToString: AnsiString;
begin
  Result := AnsiString(GetQualifiedName);
end;
