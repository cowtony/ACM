{$MODE FPC}
{$M 0,1025}
{$R-,S-,Q-,I-}
program zju_1976;
var
  a , b , n , m		: Longword;
  i , w			: Longword;
  Ans			: Int64;

begin
  While true do
    begin
      Read(a , b);
      if (a = 0) and (b = 0) then exit;
      if (a = 0) or (b = 0) then begin Writeln(1); continue; end;
      n := a + b;
      if a < b then m := a else m := b;

      Ans := 1; w := 0;
      for i:=n - m + 1 to n do
        begin
	  Ans := Ans * i;
	  Inc(w);
	  if w <= m then Ans := Ans div w;
	end;
      Writeln(Ans);
    end;
end.
