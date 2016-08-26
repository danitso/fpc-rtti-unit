{$IFDEF RTTI_INCLUDE_TYPE_EINVALIDOPEXCEPTION}
  EInvalidOpException = class(Exception);
{$ENDIF}

{$IFDEF RTTI_INCLUDE_TYPE_TARRAY}
  TArray<T> = array of T;
{$ENDIF}

// We need to define array types the old way as we otherwise loose the code
// insight feature in Lazarus 1.6. These should be converted to TArray<type> as
// soon as the bug in Lazarus is fixed.
StringArray = array of string;
TGUIDArray = array of TGUID;
TVarRecArray = array of TVarRec;
