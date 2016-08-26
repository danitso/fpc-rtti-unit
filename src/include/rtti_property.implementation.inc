/// <summary> Creates a new TRttiProperty instance </summary>
constructor TRttiProperty.Create(const AParent: TRttiObject;
  const APropInfo: PPropInfo);
begin
  // Invoke the parent constructor.
  inherited Create;

  // Initialize the properties.
  FHandle := APropInfo;
  FParent := AParent;
  FRttiDataSize := SizeOf(TPropInfo);
end;

/// <summary> Not documented </summary>
function TRttiProperty.GetAttributes: TCustomAttributeArray;
begin
  SetLength(Result, 0);
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies whether the reflected property is readable </summary>
function TRttiProperty.GetIsReadable: Boolean;
begin
  Result := (PPropInfo(FHandle)^.GetProc <> Nil);
end;

/// <summary> Specifies whether the reflected property is writable </summary>
function TRttiProperty.GetIsWritable: Boolean;
begin
  Result := (PPropInfo(FHandle)^.SetProc <> Nil);
end;

/// <summary> Specifies the property name </summary>
function TRttiProperty.GetName: string;
begin
  Result := String(PPropInfo(FHandle)^.Name);
end;

/// <summary> Specifies the type of the property </summary>
function TRttiProperty.GetPropertyType: TRttiType;
begin
  {$IFDEF RTTI_ENABLE_SYSTEM_TYPES_WORKAROUND}
    if (FParent is TRttiInstanceType) and
       (TRttiInstanceType(FParent).MetaclassType = TRttiSystemTypes) then
    begin
      Result := TRttiPool.GetInstance.GetType(PPropInfo(FHandle)^.PropType,
        FParent);
      Exit;
    end;
  {$ENDIF}

  Result := TRttiPool.GetInstance.GetType(PPropInfo(FHandle)^.PropType);
end;

/// <summary> Returns the value of the property in a given instance </summary>
function TRttiProperty.GetValue(Instance: Pointer): TValue;
begin
  Result := TValue.FromVariant(GetPropValue(TObject(Instance),
    PPropInfo(FHandle)^.Name));
end;

/// <summary> Sets the value of the field in a given instance </summary>
procedure TRttiProperty.SetValue(Instance: Pointer; const AValue: TValue);
begin
  SetPropValue(TObject(Instance), PPropInfo(FHandle)^.Name, AValue.AsVariant);
end;
