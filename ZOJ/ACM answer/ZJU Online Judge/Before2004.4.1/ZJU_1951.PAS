Program zju_1951;
const
  MAXN = 1000000;
var
  prim		: Array[1..MAXN] of Boolean;
  N		: Integer;

procedure calc_prim;
  var
    i ,  k	: Integer;
  begin
    fillchar(prim , sizeof(prim) , 1);
    for i:=2 to maxn do
    if prim[i] then
      begin    
        k := i + i;
	while k <= maxn do
	  begin
	    prim[k] := false;
	    inc(k , i);
	  end;
      end;    
  end;

procedure solve;
  var
    i		: Integer;
    p1  	: Integer;
  begin
    p1 := 3;
    while true do
      begin
	if prim[p1] and prim[n - p1] then begin
	  writeln(n , ' = ' , p1 , ' + ' , n - p1);
          exit;
	end;        
	inc(p1 , 2);
      end;   
  end;
  

begin
  calc_prim;
  while true do 
    begin
      read(n);
      if n = 0 then break;
      solve;
    end;    
end.
