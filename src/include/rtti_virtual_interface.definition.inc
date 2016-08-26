TVirtualInterface = class(TInterfacedObject, IInterface)
protected
  // Fields
  FOnInvoke: TVirtualInterfaceInvokeEvent;
public
  // Constructors and destructors
  constructor Create(PIID: PTypeInfo); overload;
  constructor Create(PIID: PTypeInfo;
    InvokeEvent: TVirtualInterfaceInvokeEvent); overload;
  destructor Destroy; override;

  // Properties
  property OnInvoke: TVirtualInterfaceInvokeEvent read FOnInvoke
    write FOnInvoke;
end;
