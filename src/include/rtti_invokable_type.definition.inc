TRttiInvokableType = class(TRttiType)
protected
  // Fields
  FCallingConvention: TCallConv;
  FParameters: TRttiParameterArray;
  FReturnType: TRttiType;

  // Methods
  function GetCallingConvention: TCallConv; virtual;
  function GetReturnType: TRttiType; virtual;
public
  // Constructors and destructors
  destructor Destroy; override;

  // Methods
  function GetParameters: TRttiParameterArray;
  function Invoke(const ProcOrMeth: TValue;
    const Args: array of TValue): TValue; virtual; abstract;
  function ToString: AnsiString; override;

  // Properties
  property CallingConvention: TCallConv read GetCallingConvention;
  property ReturnType: TRttiType read GetReturnType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiInvokableTypeArray = array of TRttiInvokableType;
