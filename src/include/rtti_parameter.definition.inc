TRttiParameter = class(TRttiNamedObject)
protected
  // Fields
  FFlags: TParamFlags;
  FName: String;
  FParamType: TRttiType;

  // Methods
  function GetFlags: TParamFlags; virtual;
  function GetParamType: TRttiType; virtual;
public
  // Constructors and destructors
  constructor Create(const AParent: TRttiObject; const AName: String;
    const AFlags: TParamFlags; const ATypeInfo: PTypeInfo);

  // Methods
  function GetAttributes: TArray<TCustomAttribute>; override;
  function GetName: string; override;
  function ToString: AnsiString; override;

  // Properties
  property Flags: TParamFlags read GetFlags;
  property ParamType: TRttiType read GetParamType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiParameterArray = array of TRttiParameter;
