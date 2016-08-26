TRttiAnsiStringType = class(TRttiStringType)
protected
  // Methods
  function GetCodePage: Word; virtual;
public
  // Properties
  property CodePage: Word read GetCodePage;
end;

// We need to define the array type the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. This should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
TRttiAnsiStringTypeArray = array of TRttiAnsiStringType;
