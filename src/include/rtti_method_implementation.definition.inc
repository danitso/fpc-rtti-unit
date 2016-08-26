TMethodImplementation = class
protected
  // Fields
  FInvokeInfo: TInvokeInfo;

  // Methods
  function GetCodeAddress: Pointer; virtual;
public
  // Constructors and destructors
  constructor Create; overload;
  constructor Create(AUserData: Pointer; AInvokeInfo: TInvokeInfo;
    const ACallback: TMethodImplementationCallback); overload;

  // Properties
  property CodeAddress: Pointer read GetCodeAddress;
end;
