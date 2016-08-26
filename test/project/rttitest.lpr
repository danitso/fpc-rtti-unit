program rttitest;

{$mode objfpc}{$H+}

uses
  Classes,
  ConsoleTestRunner,
  RTTI,
  RTTI_Invoke_Test_Case;

type

  { TLazTestRunner }

  TMyTestRunner = class(TTestRunner)
  protected
  // override the protected methods of TTestRunner to customize its behavior
  end;

var
  Application: TMyTestRunner;

{$R *.res}

begin
  Application := TMyTestRunner.Create(nil);
  Application.Initialize;
  Application.Run;
  Application.Free;
end.
