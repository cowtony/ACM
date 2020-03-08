{$A-,B-,D-,E-,F-,G-,I-,L-,N-,O-,P-,Q-,R-,S-,T-,V-,X-,Y-}
{$M 16384,0,655360}
Program zju_1651;

type
  integer = Longint;

const
  Len = (1 shl 15) - 1;

var
  n , L		: Integer;
  p , d		: Array[0..14] of Integer;
  
  f , time	: Array[0..Len] of Integer;
  pre		: Array[0..Len] of Byte;
  i , j		: Integer;
  Space		: Boolean;

procedure search( k	: Integer);
  var
    i , cost	: Integer;
  begin
    if f[k] < maxlongint then exit;
    for i := 0 to n do
      if (k and (1 shl i)) > 0 then 
        begin
          search(k xor (1 shl i));
	  if Time[k] <= d[i] then Cost := 0
	  else Cost := Time[k] - d[i];
	  if (f[k xor (1 shl i)] + Cost <= f[k]) then begin f[k] := f[k xor (1 shl i)] + Cost; pre[k] := i; end;
        end;
  end;

procedure path( k	: Integer);
  begin
    if k = 0 then exit;
    path(k xor (1 shl pre[k]));
    if Space then write(' ') else Space := true;
    write(pre[k] + 1);
  end;

begin  
  While not eof do  
    begin
      Read(n); L := (1 shl n) - 1; dec(n);
      for i:=0 to n do
        Read(p[i] , d[i]);
      Readln;
      f[0] := 0;
      for i:=1 to L do
        f[i] := maxlongint;

      for i:=0 to L do
        begin
          Time[i] := 0;
          for j := 0 to n do
            if (i and (1 shl j)) > 0 then inc(Time[i] , p[j]);
        end;

      search( L );
      Writeln( f[L] );
      Space := false;
      path(L);
      Writeln;
    end;
end.
