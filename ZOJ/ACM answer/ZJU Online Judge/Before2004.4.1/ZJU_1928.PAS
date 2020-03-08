Program zju_1928;
var
  a , b , c , d		: Integer;
  ret			: Integer;
begin
  while true do
    begin
      read( a , b , c , d );
      if (a=0)and(b=0)and(c=0)and(d=0) then break;
{      ret := 2 * 360 + (b - a + 40) mod 40 * 9 + 360 + (b - c + 40)mod 40 * 9 + (d - c + 40) mod 40 * 9;}
      ret := 2 * 360 + (a - b + 40) mod 40 * 9 + 360 + (c - b + 40)mod 40 * 9 + (c - d + 40) mod 40 * 9;
      Writeln(ret);
    end;
end.
