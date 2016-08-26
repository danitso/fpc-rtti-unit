TRawVirtualClass = class(TInterfacedObject, IInterface)
type
  // TVTable
  TVTable = class

  end;
public
  // Constructors and destructors
  constructor Create(Guids: TGUIDArray;
    VTable: TRawVirtualClass.TVTable); overload;
  destructor Destroy; override;

  // Methods
  class function GetInstanceFromInterface(
    Intf: Pointer): TRawVirtualClass; static;
end;
