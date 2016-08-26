{*******************************************************************************

   RTTI unit for Free Pascal
   Copyright (c) 2016 by Danitso

   See the file COPYING.txt, included in this distribution, for details
   about the copyright.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*******************************************************************************}

unit RTTI;

{$I rtti_directives.inc}

interface

uses
  Classes,
  SysUtils,
  TypInfo,
  Variants;

const
  // Messages
  RTTI_E_INSUFFICIENT_RTTI = 'Insufficient RTTI';
  RTTI_E_NOT_IMPLEMENTED = 'Not implemented';

type
  // Forward declarations
  TRttiFloatType = class;
  TRttiMethod = class;
  TRttiInstanceType = class;
  TRttiInterfaceType = class;
  TRttiOrdinalType = class;
  TRttiPackage = class;
  TRttiParameter = class;
  TRttiRecordType = class;
  TRttiSetType = class;
  TRttiType = class;

  // Type definitions
  {$I rtti_activex.definition.inc}
  {$I rtti_sysutils.definition.inc}
  {$I rtti_typinfo.definition.inc}

  EInsufficientRtti = class(Exception);
  EInvocationError = class(Exception);
  ENonPublicType = class(Exception);

  TDispatchKind = (dkStatic, dkVtable, dkDynamic, dkMessage, dkInterface);
  TRttiStringKind = (skShortString, skAnsiString, skWideString,
    skUnicodeString);

  TInvokeInfo = record
    DispatchID: Integer;
    Flags: Word;
    Params: TDispParams;
    FnResult: OleVariant;
    ArgErr: Cardinal;
    SCode: HRESULT;
  end;

  {$I rtti_value_data_interface.definition.inc}
  {$I rtti_value_data_object.definition.inc}
  {$I rtti_value_data.definition.inc}
  {$I rtti_value.definition.inc}

  TInterceptAfterNotify = procedure(Instance: TObject; Method: TRttiMethod;
    const Args: TValueArray; var Result: TValue);
  TInterceptBeforeNotify = procedure(Instance: TObject; Method: TRttiMethod;
    const Args: TValueArray; out DoInvoke: Boolean; out Result: TValue);
  TInterceptExceptionNotify = procedure(Instance: TObject; Method: TRttiMethod;
    const Args: TValueArray; out RaiseException: Boolean;
    TheException: Exception; out Result: TValue);

  TMethodImplementationCallback = procedure(UserData: Pointer;
    const Args: TValueArray; out Result: TValue);
  TVirtualInterfaceInvokeEvent = procedure(Method: TRttiMethod;
    const Args: TValueArray; out Result: TValue);

  {$I rtti_method_implementation.definition.inc}
  {$I rtti_object.definition.inc}
  {$I rtti_managed_field.definition.inc}
  {$I rtti_named_object.definition.inc}
  {$I rtti_member.definition.inc}
  {$I rtti_field.definition.inc}
  {$I rtti_indexed_property.definition.inc}
  {$I rtti_parameter.definition.inc}
  {$I rtti_method.definition.inc}
  {$I rtti_property.definition.inc}
  {$I rtti_type.definition.inc}
  {$I rtti_package.definition.inc}
  {$I rtti_instance_property.definition.inc}
  {$I rtti_structured_type.definition.inc}
  {$I rtti_array_type.definition.inc}
  {$I rtti_class_ref_type.definition.inc}
  {$I rtti_dynamic_array_type.definition.inc}

  {$IFNDEF FPUNONE}
    {$I rtti_float_type.definition.inc}
  {$ENDIF}

  {$I rtti_interface_type.definition.inc}
  {$I rtti_instance_type.definition.inc}
  {$I rtti_int64_type.definition.inc}
  {$I rtti_invokable_type.definition.inc}
  {$I rtti_method_type.definition.inc}
  {$I rtti_ordinal_type.definition.inc}
  {$I rtti_enumeration_type.definition.inc}
  {$I rtti_pointer_type.definition.inc}
  {$I rtti_procedure_type.definition.inc}
  {$I rtti_record_type.definition.inc}
  {$I rtti_set_type.definition.inc}
  {$I rtti_string_type.definition.inc}
  {$I rtti_ansi_string_type.definition.inc}

  {$I rtti_context.definition.inc}
  {$I rtti_pool.interface.inc}
  {$I rtti_pool.definition.inc}

  {$IFDEF RTTI_ENABLE_SYSTEM_TYPES_WORKAROUND}
    {$I rtti_system_types.definition.inc}
  {$ENDIF}

  {$I rtti_raw_virtual_class.definition.inc}
  {$I rtti_virtual_interface.definition.inc}
  {$I rtti_virtual_method_interceptor.definition.inc}

  TRttiClass = class of TRttiObject;

var
  // System Type Information
  RttiTypeInfoAnsiString: PTypeInfo;
  RttiTypeInfoBoolean: PTypeInfo;
  RttiTypeInfoCurrency: PTypeInfo;
  RttiTypeInfoDouble: PTypeInfo;
  RttiTypeInfoInt64: PTypeInfo;
  RttiTypeInfoInteger: PTypeInfo;
  RttiTypeInfoSingle: PTypeInfo;
  RttiTypeInfoQWord: PTypeInfo;
  RttiTypeInfoUnicodeString: PTypeInfo;

// Method definitions
{$I rtti_methods.definition.inc}

implementation

// Method implementations
{$I rtti_methods.implementation.inc}

// Type implementations
{$I rtti_typinfo.implementation.inc}

{$I rtti_ansi_string_type.implementation.inc}
{$I rtti_array_type.implementation.inc}
{$I rtti_class_ref_type.implementation.inc}
{$I rtti_context.implementation.inc}
{$I rtti_dynamic_array_type.implementation.inc}
{$I rtti_enumeration_type.implementation.inc}
{$I rtti_field.implementation.inc}

{$IFNDEF FPUNONE}
  {$I rtti_float_type.implementation.inc}
{$ENDIF}

{$I rtti_indexed_property.implementation.inc}
{$I rtti_instance_property.implementation.inc}
{$I rtti_instance_type.implementation.inc}
{$I rtti_int64_type.implementation.inc}
{$I rtti_interface_type.implementation.inc}
{$I rtti_invokable_type.implementation.inc}
{$I rtti_managed_field.implementation.inc}
{$I rtti_member.implementation.inc}
{$I rtti_method.implementation.inc}
{$I rtti_method_implementation.implementation.inc}
{$I rtti_method_type.implementation.inc}
{$I rtti_ordinal_type.implementation.inc}
{$I rtti_package.implementation.inc}
{$I rtti_parameter.implementation.inc}
{$I rtti_pointer_type.implementation.inc}
{$I rtti_pool.implementation.inc}

{$I rtti_procedure_type.implementation.inc}
{$I rtti_property.implementation.inc}
{$I rtti_raw_virtual_class.implementation.inc}
{$I rtti_record_type.implementation.inc}
{$I rtti_set_type.implementation.inc}
{$I rtti_string_type.implementation.inc}
{$I rtti_type.implementation.inc}
{$I rtti_value.implementation.inc}
{$I rtti_value_data_object.implementation.inc}
{$I rtti_virtual_interface.implementation.inc}
{$I rtti_virtual_method_interceptor.implementation.inc}

initialization
  TRttiPool.LoadTypes;

end.
