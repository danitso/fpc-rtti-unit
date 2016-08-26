/// <summary> Specifies the code page of the AnsiString type </summary>
function TRttiAnsiStringType.GetCodePage: Word;
begin
  Result := FTypeData^.CodePage;
end;
