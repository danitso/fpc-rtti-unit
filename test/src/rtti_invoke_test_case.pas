unit rtti_invoke_test_case;

{$I rtti_directives.inc}

interface

uses
  Classes,
  FPCUnit,
  SysUtils,
  TestRegistry;

type
  TRTTIInvokeTestCase= class(TTestCase)
  published
    procedure TestHookUp;
  end;

implementation

procedure TRTTIInvokeTestCase.TestHookUp;
begin
  Fail('Write your own test');
end;

initialization
  RegisterTest(TRTTIInvokeTestCase);

end.
