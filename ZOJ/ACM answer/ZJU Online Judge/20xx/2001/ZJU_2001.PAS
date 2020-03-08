program zju_2001;
var
  a , b , T     : Integer;

function Reverse(k      : Integer)      : Integer;
  var
    ret         : Integer;
  begin
    ret := 0;
    while k > 0 do
      begin
        ret := ret * 10 + k mod 10;
        k := k div 10;
      end;
    Reverse := ret;
  end;

begin
  readln(T);
  while T > 0 do
    begin
      dec(T);
      read(a , b);
      Writeln(Reverse( Reverse(a) + Reverse(b) ));
    end;
end.