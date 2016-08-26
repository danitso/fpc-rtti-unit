TVirtualMethodInterceptor = class
protected
  // Fields
  FOnAfter: TInterceptAfterNotify;
  FOnBefore: TInterceptBeforeNotify;
  FOnException: TInterceptExceptionNotify;
  FOriginalClass: TClass;
  FProxyClass: TClass;
public
  // Constructors and destructors
  constructor Create(AClass: TClass);
  destructor Destroy; override;

  // Methods
  procedure Proxify(AInstance: TObject);
  procedure Unproxify(AInstance: TObject);

  // Properties
  property OnAfter: TInterceptAfterNotify read FOnAfter write FOnAfter;
  property OnBefore: TInterceptBeforeNotify read FOnBefore write FOnBefore;
  property OnException: TInterceptExceptionNotify read FOnException
    write FOnException;
  property OriginalClass: TClass read FOriginalClass;
  property ProxyClass: TClass read FProxyClass;
end;
