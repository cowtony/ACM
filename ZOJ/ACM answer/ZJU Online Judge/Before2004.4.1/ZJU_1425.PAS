Program Zju_1425;
const
  MaxLen  =  100;
var
  T,N,M		: Integer;
  UP,Down	: Array[1..MaxLen] of Integer;
  f		: Array[0..MaxLen , 0..MaxLen] of Integer;
  i,j,p,q	: Integer;
begin
  Read(T);
  repeat
    Read(N,M);
    for i:=1 to N do
      Read(UP[i]);
    for i:=1 to M do
      Read(Down[i]);

    fillchar(f,sizeof(f),0);
    for i:=1 to N do
      for j:=1 to M do
        begin
	  if f[i-1,j] > f[i,j-1] then f[i,j] := f[i-1,j]
	  else f[i,j] := f[i,j-1];
	  if Up[i] = Down[j] then continue;
	  p:=i - 1; while (p>0) and (Up[p]<>Down[j]) do dec(p);
          q:=j - 1; while (q>0) and (Down[q]<>Up[i]) do dec(q);
          if (p>0) and (q>0) and (f[p-1,q-1]+2>f[i,j]) then
            f[i,j]:=f[p-1,q-1]+2;
	end;
    Writeln(f[n,m]);
    dec(T);
  until T = 0;
end.