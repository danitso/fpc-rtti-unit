TRttiPool = class(TInterfacedObject, IRttiPool)
private class var
  // Fields
  FInstance: TRttiPool;
  FPackages: TRttiPackageArray;
  FTypes: TRttiTypeArray;
protected
  // Methods
  function LoadType(const ATypeInfo: Pointer;
    const AParent: TRttiObject = Nil): TRttiType;
public
  // Constructors and destructors
  constructor Create;
  destructor Destroy; override;

  // Methods
  function FindType(const AQualifiedName: string): TRttiType;

  class function GetInstance: IRttiPool;
  function GetPackages: TRttiPackageArray;
  function GetType(const ATypeInfo: Pointer;
    const AParent: TRttiObject = Nil): TRttiType; overload;
  function GetType(const AClass: TClass;
    const AParent: TRttiObject = Nil): TRttiType; overload;
  function GetTypes: TRttiTypeArray;

  class procedure LoadTypes;
end;
