Program zju_2000;
type
  Integer = Longint;
var
  N		: Integer;
  c , List , power	: Array[-1..18] of Integer;

  i		: Integer;
  digit         : Array[1..18] of Integer;

procedure solve;
  var
    L           : Integer;
    i , p       : Integer;
  begin
    if n <= 9 then begin writeln(n); exit; end;
    for L:=18 downto 0 do
      if n > c[L] then break;
    Inc(L);

    n := n - C[L - 1];
    digit[1] :=(n - 1) div power[L - 2] + 1;
    n := (n - 1) mod power[L - 2] + 1;
    digit[L] := digit[1];
    p := L;

    for i:=2 to (L + 1) div 2 do
      begin
        p := p - 2;
        digit[i] := (n - 1) div power[p - 2];
        n := (n - 1)  mod power[p - 2] + 1;
        digit[L - i + 1] := digit[i];
      end;

    for i:=1 to L do
     Write(digit[i]);
    Writeln;

  end;

begin
  c[0] := 0; c[1] := 9; List[0] := 1; List[1] := 9; List[-1] := 1;
   power[0] := 1; power[-1] := 1; power[1] := 10;
  for i:=2 to 18 do
    begin
      if odd(i) then List[i] := List[i - 1] * 10
      else List[i] := List[i-1];
      if odd(i) then power[i] := power[i-1]*10
      else power[i] := power[i - 1];
      c[i] := List[i] + c[i - 1];
    end;
  while true do
    begin
      Read(N);
      if n = 0 then break;
      solve;
    end;
end.
