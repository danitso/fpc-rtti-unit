IRttiPool = interface
  ['{A4BE10DE-A3BA-41C8-9852-DDF81D6FE376}']
  function FindType(const AQualifiedName: string): TRttiType;

  function GetPackages: TRttiPackageArray;
  function GetType(const ATypeInfo: Pointer;
    const AParent: TRttiObject = Nil): TRttiType; overload;
  function GetType(const AClass: TClass;
    const AParent: TRttiObject = Nil): TRttiType; overload;
  function GetTypes: TRttiTypeArray;
end;
