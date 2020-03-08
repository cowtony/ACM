program zju_1002d;
//{$APPTYPE CONSOLE}
const
 source = 'T.T^__^';
var
  Len     : Array[0..88] of int64;
  I   : Integer;
  K   : int64;

begin
  //Assign(input,'in.txt'); Reset(input);
  //Assign(output,'out.txt'); Rewrite(output);
  Len[0] := 4; Len[1] :=3;
  for i:=2 to 88 do
   begin
    Len[i] := Len[i-1] + Len[i-2];
   end;
  while not eof do
   begin
     Readln(k);
     for i:=88 downto 2 do
       if k > Len[i] then K := k - Len[i];
     Writeln(source[k]);
   end;
end.
