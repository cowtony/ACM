Program zju_1738;
const  
  maxn = 1 shl 15;
var
  n		: Integer;
  f		: Array[0..maxn] of Integer;
  a , b , c , d	: Integer;
  ret		: Integer;
begin
  fillchar(f , sizeof(f) , 0);
  for a:=0 to trunc(sqrt(maxn)) do
    for b:=a to trunc(sqrt(maxn - a * a)) do
      for c:=b to trunc(sqrt(maxn - a * a - b * b)) do
        for d:=c to trunc(sqrt(maxn - a * a - b * b - c * c)) do
	  begin
	    ret := a * a + b * b + c * c + d * d;
	    inc(f[ret]);
	  end;
  While true do
    begin
      Readln(n);
      if n = 0 then break;
      Writeln(f[n]);
    end;
end.
