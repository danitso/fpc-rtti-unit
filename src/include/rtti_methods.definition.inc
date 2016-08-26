function ArrayOfConstToTValueArray(
  const Params: array of const): TValueArray;
function ArrayOfTValueToTValueArray(
  const Params: array of TValue): TValueArray;

function Invoke(ACodeAddress: Pointer; const AArgs: array of TValue;
  ACallingConvention: TCallConv; AResultType: PTypeInfo; AIsStatic: Boolean;
  AIsConstructor: Boolean): TValue; overload;
function Invoke(ACodeAddress: Pointer; const AArgs: TValueArray;
  ACallingConvention: TCallConv; AResultType: PTypeInfo; AIsStatic: Boolean;
  AIsConstructor: Boolean): TValue; overload;

function IsManaged(TypeInfo: PTypeInfo): Boolean;
function TValueArrayToArrayOfConst(
  const Params: array of TValue): TVarRecArray;
