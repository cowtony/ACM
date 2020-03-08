{$n+}
Program zju_1813;
var
  a , b , c ,d		: Double;
  CaseNo		: Integer;
begin
  CaseNo := 0;
  repeat
    readln(a , b , c);
    if b = 0 then break;
    Inc(CaseNO);
    d := a * 3.1415927 * b / 5280 / 12;
    writeln('Trip #',CaseNO,': ', d : 0 : 2,' ', d / c * 3600 : 0 : 2);
  until false;
end.
