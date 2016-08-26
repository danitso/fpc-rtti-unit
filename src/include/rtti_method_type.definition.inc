TRttiMethodType = class(TRttiInvokableType)
protected
  // Methods
  function GetMethodKind: TMethodKind; virtual;
public
  // Constructors and destructors
  constructor Create(const ATypeInfo: PTypeInfo;
    const AParent: TRttiObject = Nil); override;

  // Methods
  function Invoke(const Callable: TValue;
    const Args: array of TValue): TValue; override;
  function ToString: AnsiString; override;

  // Properties
  property MethodKind: TMethodKind read GetMethodKind;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiMethodTypeArray = array of TRttiMethodType;
