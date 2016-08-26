TRttiInterfaceType = class(TRttiStructuredType)
protected
  // Methods
  function GetBaseTyped: TRttiInterfaceType; virtual;
  function GetDeclaringUnitName: string; virtual;
  function GetGUID: TGUID; virtual;
  function GetIntfFlags: TIntfFlags; virtual;
public
  // Methods
  function GetDeclaredMethods: TArray<TRttiMethod>; override;

  // Properties
  property BaseType: TRttiInterfaceType read GetBaseTyped;
  property DeclaringUnitName: string read GetDeclaringUnitName;
  property GUID: TGUID read GetGUID;
  property IntfFlags: TIntfFlags read GetIntfFlags;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiInterfaceTypeArray = array of TRttiInterfaceType;
