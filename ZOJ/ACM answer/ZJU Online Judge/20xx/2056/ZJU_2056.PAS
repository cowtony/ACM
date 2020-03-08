
program Ural_1066;
var
 N       : Integer;
 La      : Array[1..1000] of Double;
 K       : Array[1..1000] of integer;
 i       : Integer;

procedure Work;
 var max,tmp : Double;
     i     : integer;
 function Value(p : integer) : Double;
  begin
   Value := (-La[p] / K[p]) * K[n] + La[n];
  end;
 begin
  max := 0;
  for i:=2 to n-1 do
  if La[i] < 0 then
   begin
    tmp := Value(i);
    if max < tmp then max := tmp;
   end;
  if max < 0 then max := 0;
  writeln(max :  0  : 2);
 end;
var
 T , TC	: Integer;
begin
  Readln(T);
  for TC := 1 to T do
    begin
      Readln;

 Readln(N,La[1]);
 K[1] := 0; La[2] := 0; K[2] := 1;
 for i:=2 to N-1 do
  begin
   La[i+1] := 2 * La[i] + 2 - La[i-1];
   K[i+1] := 2 * K[i] - K[i-1];
  end;

 Work;

 if TC < T then Writeln;
 end;
end.
