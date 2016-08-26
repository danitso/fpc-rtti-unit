TRttiProcedureType = class(TRttiInvokableType)
public
  // Constructors and destructors
  constructor Create(const ATypeInfo: PTypeInfo;
    const AParent: TRttiObject = Nil); override;

  // Methods
  function GetAttributes: TCustomAttributeArray; override;
  function Invoke(const Callable: TValue;
    const Args: array of TValue): TValue; override;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiProcedureTypeArray = array of TRttiProcedureType;
