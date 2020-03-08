Program zju_1797;
type integer = int64;
function gcd(a , b	: Integer)	: Integer;
  begin
    if b = 0 then gcd := a
    else gcd := gcd(b , a mod b);
  end;

var
  T			: Integer;
  ret , i , m , k	: Integer;
begin
  readln(T);
  repeat
    ret := 1;
    read(m);
    repeat
      read(k);
      ret := ret div gcd(ret , k) * k;
      dec(m);
    until m = 0;
    Readln;
    Writeln(ret);
    Dec(T);
  until T = 0;
end.
