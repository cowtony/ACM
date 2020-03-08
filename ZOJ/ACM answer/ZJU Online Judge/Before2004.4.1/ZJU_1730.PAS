program E;
type integer = Longint;
var
  T , N		: Integer;
  a , b		: Integer;
begin
  Read(T);
  While T > 0 do 
    begin
      Read(N);
      a := N div 2 - 1; b := N - N div 2 - 1;
      Writeln(a * (a + 1) div 2 + b * (b + 1) div 2);
      Dec(t);
    end;
end.