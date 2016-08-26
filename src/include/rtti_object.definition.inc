TRttiObject = class abstract
protected
  // Fields
  FHandle: Pointer;
  FPackage: TRttiPackage;
  FParent: TRttiObject;
  FRttiDataSize: Integer;
public
  // Methods
  function GetAttributes: TCustomAttributeArray; virtual; abstract;

  // Properties
  property Handle: Pointer read FHandle;
  property Package: TRttiPackage read FPackage;
  property Parent: TRttiObject read FParent;
  property RttiDataSize: Integer read FRttiDataSize;
end;
