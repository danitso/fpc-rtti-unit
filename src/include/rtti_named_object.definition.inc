TRttiNamedObject = class(TRttiObject)
private
  // Methods
  function GetName: string; virtual; abstract;
public
  // Properties
  property Name: string read GetName;
end;
