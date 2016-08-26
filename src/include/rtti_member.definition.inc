TRttiMember = class(TRttiNamedObject)
protected
  // Methods
  function GetParent: TRttiType; virtual;
  function GetVisibility: TMemberVisibility; virtual;
public
  // Properties
  property Parent: TRttiType read GetParent;
  property Visibility: TMemberVisibility read GetVisibility;
end;
