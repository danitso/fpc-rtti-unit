{$IFDEF RTTI_INCLUDE_TYPE_TATTRDATA}
  TAttrData = record
    Len: Word;
   {AttrEntry: array[] of TAttrEntry;}
  end;
  PAttrData = ^TAttrData;
{$ENDIF}

{$IFDEF RTTI_INCLUDE_TYPE_TSYMBOLNAME}
  TSymbolName = ShortString;
{$ENDIF}

{$IFDEF RTTI_INCLUDE_TYPE_TTYPEINFOFIELDACCESSOR}
  TTypeInfoFieldAccessor = record
  strict private
    FData: PByte;
  public
    class operator Equal(const Left, Right: TTypeInfoFieldAccessor): Boolean;
      inline;
    procedure SetData(const Data: PByte); inline;
    function Tail: PByte; inline;
    function ToByteArray: TBytes;
    {$IFNDEF NEXTGEN}
      function ToShortUTF8String: ShortString; inline;
    {$ENDIF !NEXTGEN}
    function ToString: string;
    function UTF8Length: integer; inline;
  end;
{$ENDIF}

{$IFDEF RTTI_INCLUDE_TYPE_TARRAYPROPINFO}
  TArrayPropInfo = packed record
    Flags: Byte;
    ReadIndex: Word;
    WriteIndex: Word;
    Name: TSymbolName;
    function NameFld: TTypeInfoFieldAccessor; inline;
   {AttrData: TAttrData;}
    function AttrData: PAttrData; inline;
  end;
  PArrayPropInfo = ^TArrayPropInfo;
{$ENDIF}

{$IFDEF RTTI_INCLUDE_TYPE_TCUSTOMATTRIBUTE}
  TCustomAttribute = class(TObject);
{$ENDIF}

TCustomAttributeArray = array of TCustomAttribute;

{$IFDEF RTTI_INCLUDE_TYPE_TMEMBERVISIBILITY}
  TMemberVisibility = (mvPrivate, mvProtected, mvPublic, mvPublished);
{$ENDIF}

{$IFDEF RTTI_INCLUDE_TYPE_TPARAMDATA}
  TParamData             = record
    Flags                : TParamFlags;
    ParamName            : ShortString;
    TypeName             : ShortString;
  end;
  PParamData             = ^TParamData;
{$ENDIF}
