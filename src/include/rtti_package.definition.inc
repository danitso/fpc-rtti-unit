TRttiPackage = class(TRttiNamedObject)
protected
  // Fields
  FBaseAddress: Pointer;

  // Methods
  function GetHandle: THandle; virtual; abstract;
public
  // Methods
  function FindType(const AQualifiedName: string): TRttiType; virtual; abstract;
  function GetTypes: TRttiTypeArray; virtual; abstract;

  // Properties
  property BaseAddress: Pointer read FBaseAddress;
  property Handle: THandle read GetHandle;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiPackageArray = array of TRttiPackage;
