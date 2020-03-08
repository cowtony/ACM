{$MODE FPC}
{$M 0,1025}
{$R-,S-,Q-,I-}
Program zju_1715;
var
  N , Q		: Integer;
  co		: Array[1..100] of Integer;
  i , j , k , p	: Integer;
  max		: Integer;
begin
  while true do
    begin
      Read(n ,  Q);
      fillchar(co , sizeof(co) , 0);
      if n = 0  then break;
      for i:=1 to n do
        begin
	  read(k);
	  for j:=1 to k do
	    begin
	      Read(p);
	      inc(co[p]);
	    end;
	end;
      k := 0; max := q - 1;
      for i:=1 to 100 do
        if co[i] > max then begin max := co[i]; k := i; end;
      Writeln(k);      
    end;
end.
