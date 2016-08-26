/// <summary> Specifies the type from which the member is part of </summary>
function TRttiMember.GetParent: TRttiType;
begin
  Result := Nil;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;

/// <summary> Specifies the member's visibility modifier </summary>
function TRttiMember.GetVisibility: TMemberVisibility;
begin
  Result := mvPublished;
  raise ENotImplemented.Create(RTTI_E_NOT_IMPLEMENTED);
end;
