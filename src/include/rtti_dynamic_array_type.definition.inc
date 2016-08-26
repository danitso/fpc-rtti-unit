TRttiDynamicArrayType = class(TRttiType)
protected
  // Methods
  function GetDeclaringUnitName: string; virtual;
  function GetElementSize: Integer; virtual;
  function GetElementType: TRttiType; virtual;
  function GetOleAutoVarType: TVarType; virtual;
public
  // Properties
  property DeclaringUnitName: string read GetDeclaringUnitName;
  property ElementSize: Integer read GetElementSize;
  property ElementType: TRttiType read GetElementType;
  property OleAutoVarType: TVarType read GetOleAutoVarType;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiDynamicArrayTypeArray = array of TRttiDynamicArrayType;
