Program zju_1700;
var
  Line		: Array[1..30] of string;
  left , right	: Array['A'..'Z'] of Char;

  n , i	, j	: Integer;
  root , ch	: char;

procedure AddNode(k , p : Char);
  begin
    if (p < k) then begin
      if left[k] = '#' then left[k] := p
      else AddNode (left[k] , p);
    end else begin
      if right[k] = '#' then right[k] := p
      else AddNode (right[k] , p);
    end;
  end;

procedure Visit(u : char);
  begin
    Write(u);
    if Left[u] <> '#' then Visit(Left[u]);
    if Right[u] <> '#' then Visit(Right[u]);
  end;
 
begin
  while true do
    begin
      n := 0;
      while true do
        begin
	  inc(n);
	  Readln(Line[n]);
	  if ( Line[n] = '*' ) or ( Line[n] = '$' ) then break;
	end;
      dec(n);

      for ch := 'A' to 'Z' do
        begin
	  left[ch] := '#';
	  right[ch] := '#';
	end;
        

      root := Line[n][1] ;
      for i:=n - 1 downto 1 do
        for j:=1 to length(Line[i]) do
	  AddNode(Root , Line[i][j]);
       
      Visit(Root);
      Writeln;    
      
      if Line[n + 1] = '$' then break;
    end;
end.
