constructor TValueDataObject.Create;
begin
  // Invoke the parent constructor.
  inherited;

  // Initialize the properties.
  FTypeKind := tkUnknown;
end;

/// <summary> Returns an AnsiString </summary>
/// <returns> Returns an AnsiString </returns>
function TValueDataObject.GetAnsiString: AnsiString;
begin
  Result := FAnsiString;
end;

/// <summary> Returns the data size </summary>
/// <returns> Returns the data size </returns>
function TValueDataObject.GetDataSize: Integer;
begin
  case FTypeKind of
    // String types.
    tkAString : Result := SizeOf(FAnsiString);
    tkSString : Result := SizeOf(FShortString);
    tkUString : Result := SizeOf(FUnicodeString);
    tkWString : Result := SizeOf(FWideString);

    // Other types.
    tkInterface : Result := SizeOf(FInterface);
  else
    raise ENotImplemented.Create('Cannot determine the size of this type');
  end;
end;

/// <summary> Returns an IInterface </summary>
/// <returns> Returns an IInterface </returns>
function TValueDataObject.GetInterface: IInterface;
begin
  Result := FInterface;
end;

/// <summary> Returns a reference to the raw data </summary>
/// <returns> Returns a pointer <returns>
function TValueDataObject.GetReferenceToRawData: Pointer;
begin
  case FTypeKind of
    // String types.
    tkAString : Result := @FAnsiString;
    tkSString : Result := @FShortString;
    tkUString : Result := @FUnicodeString;
    tkWString : Result := @FWideString;

    // Other types.
    tkInterface : Result := @FInterface;
  else
    raise ENotImplemented.Create('Cannot retrieve a reference to the data');
  end;
end;

/// <summary> Returns a ShortString </summary>
/// <returns> Returns a ShortString </returns>
function TValueDataObject.GetShortString: ShortString;
begin
  Result := FShortString;
end;

/// <summary> Returns the type kind </summary>
/// <returns> Returns a TTypeKind value </returns>
function TValueDataObject.GetTypeKind: TTypeKind;
begin
  Result := FTypeKind;
end;

/// <summary> Returns a UnicodeString </summary>
/// <returns> Returns a UnicodeString </returns>
function TValueDataObject.GetUnicodeString: UnicodeString;
begin
  Result := FUnicodeString;
end;

/// <summary> Returns a WideString </summary>
/// <returns> Returns a WideString </returns>
function TValueDataObject.GetWideString: WideString;
begin
  Result := FWideString;
end;

/// <summary> Resets the object </summary>
procedure TValueDataObject.Reset;
begin
  FAnsiString := '';
  FInterface := Nil;
  FShortString := '';
  FTypeKind := tkUnknown;
  FUnicodeString := '';
  FWideString := '';
end;

/// <summary> Sets the AnsiString value </summary>
/// <param name="AValue"> The value </param>
procedure TValueDataObject.SetAnsiString(const AValue: AnsiString);
begin
  // Reset the object.
  Reset;

  // Store the value and change the type kind.
  FAnsiString := AValue;
  FTypeKind := tkAString;
end;

/// <summary> Sets the IInterface value </summary>
/// <param name="AValue"> The value </param>
procedure TValueDataObject.SetInterface(const AValue: IInterface);
begin
  // Reset the object.
  Reset;

  // Store the value and change the type kind.
  FInterface := AValue;
  FTypeKind := tkInterface;
end;

/// <summary> Sets the ShortString value </summary>
/// <param name="AValue"> The value </param>
procedure TValueDataObject.SetShortString(const AValue: ShortString);
begin
  // Reset the object.
  Reset;

  // Store the value and change the type kind.
  FShortString := AValue;
  FTypeKind := tkSString;
end;

/// <summary> Sets the UnicodeString value </summary>
/// <param name="AValue"> The value </param>
procedure TValueDataObject.SetUnicodeString(const AValue: UnicodeString);
begin
  // Reset the object.
  Reset;

  // Store the value and change the type kind.
  FUnicodeString := AValue;
  FTypeKind := tkUString;
end;

/// <summary> Sets the WideString value </summary>
/// <param name="AValue"> The value </param>
procedure TValueDataObject.SetWideString(const AValue: WideString);
begin
  // Reset the object.
  Reset;

  // Store the value and change the type kind.
  FWideString := AValue;
  FTypeKind := tkWString;
end;
