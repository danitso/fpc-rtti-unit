TRttiMethod = class(TRttiMember)
protected
  // Methods
  function GetCallingConvention: TCallConv; virtual;
  function GetCodeAddress: Pointer; virtual;
  function GetDispatchKind: TDispatchKind; virtual;
  function GetHasExtendedInfo: Boolean; virtual;
  function GetIsClassMethod: Boolean; virtual;
  function GetIsConstructor: Boolean; virtual;
  function GetIsDestructor: Boolean; virtual;
  function GetIsStatic: Boolean; virtual;
  function GetMethodKind: TMethodKind; virtual;
  function GetReturnType: TRttiType; virtual;
  function GetVirtualIndex: SmallInt; virtual;
public
  // Methods
  function CreateImplementation(AUserData: Pointer;
    const ACallback: TMethodImplementationCallback): TMethodImplementation;

  function GetParameters: TRttiParameterArray; virtual; abstract;

  function Invoke(Instance: TObject; const Args: array of TValue): TValue;
    overload;
  function Invoke(Instance: TClass; const Args: array of TValue): TValue;
    overload;
  function Invoke(Instance: TValue; const Args: array of TValue): TValue;
    overload;

  function ToString: AnsiString; override;

  // Properties
  property CallingConvention: TCallConv read GetCallingConvention;
  property CodeAddress: Pointer read GetCodeAddress;
  property DispatchKind: TDispatchKind read GetDispatchKind;
  property HasExtendedInfo: Boolean read GetHasExtendedInfo;
  property IsClassMethod: Boolean read GetIsClassMethod;
  property IsConstructor: Boolean read GetIsConstructor;
  property IsDestructor: Boolean read GetIsDestructor;
  property IsStatic: Boolean read GetIsStatic;
  property MethodKind: TMethodKind read GetMethodKind;
  property ReturnType: TRttiType read GetReturnType;
  property VirtualIndex: SmallInt read GetVirtualIndex;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiMethodArray = array of TRttiMethod;
