program Ural_1061;
var
 N,K : Longint;
 Min,L : Longint;

 sum,Last : Array[0..100000] of Longint;

 i   : Longint;
 ch  : char;
 T , TC	: Integer;
begin
  Readln(T);
  for TC := 1 to T do
    begin
      Readln;
 Min := MaxLongint; L := 0;
 Readln(N,K);
 Last[0] := 0; sum[0] := 0;
 For i:=1 to n do
  begin
   read(ch);
   if i mod 80 = 0 then readln;
   if ch = '*' then begin
    Last[i] := 0; sum[i] := 0;
   end
   else begin
     Last[i] := Last[i-1] + 1;
     sum[i] := sum[i-1] + ord(ch) - ord('0');

     if Last[i] >= K then begin
      if sum[i] - sum[i-k] < min then begin
       min := sum[i] - sum[i-k]; L := i - k + 1;
      end;
     end;
  end;
 end;
 Writeln(L);
 if TC < T then Writeln;
 end;
end.