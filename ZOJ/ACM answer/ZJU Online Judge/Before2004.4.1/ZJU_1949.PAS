Program zju_1949;
var
  N		: Integer;
  G		: Array[1..100 , 1..100] of ShortInt;

procedure solve;
  var
    i , j , k1 , k2	: Integer;
    s			: Integer;
  begin
    for i:=1 to n do
      for j:=1 to n do
        read(G[i , j]);
    k1 := 0; k2 := 0;
    for i:=1 to n do
      begin
        s := 0;
	for j:=1 to n do
	  inc(s , G[i , j]);
	if odd(s)
	  then if k1 = 0 then k1 := i
	  else k1 := -1;
      end;
    
    for j:=1 to n do
      begin
        s := 0;
	for i:=1 to n do
	  inc(s , G[i , j]);
	if odd(s)
	  then if k2 = 0 then k2 := j
	  else k2 := -1;
      end;
    
    if (k1 = 0) and (k2 = 0) then Writeln('OK')
    else if (k1 > 0) and (k2 > 0) then Writeln('Change bit (', k1 ,',' , k2 ,')')
    else Writeln('Corrupt');
  end;

begin
  While true do
    begin
      Read(N);
      if n = 0 then break;
      solve;      
    end;
end.
