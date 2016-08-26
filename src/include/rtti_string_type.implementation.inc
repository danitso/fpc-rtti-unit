/// <summary> Specifies the actual string type </summary>
function TRttiStringType.GetStringKind: TRttiStringKind;
begin
  case GetTypeKind of
    tkAString : Result := skAnsiString;
    tkSString : Result := skShortString;
    tkUString : Result := skUnicodeString;
    tkWString : Result := skWideString;
  else
    raise ENotImplemented.Create('Unknown string kind');
  end;
end;
