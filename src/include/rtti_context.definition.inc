TRttiContext = record
private
  // Fields
  FContextToken: IInterface;
public
  // Constructors and destructors
  class function Create: TRttiContext; static;
  procedure Free;

  // Methods
  class procedure DropContext; static;
  function FindType(const AQualifiedName: string): TRttiType;

  function GetPackages: TRttiPackageArray;
  function GetType(ATypeInfo: Pointer): TRttiType; overload;
  function GetType(AClass: TClass): TRttiType; overload;
  function GetTypes: TRttiTypeArray;

  class procedure KeepContext; static;
end;
