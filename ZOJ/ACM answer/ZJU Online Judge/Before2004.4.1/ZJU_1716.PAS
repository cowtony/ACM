program zju_1716;
var
  n , m	, c	: Integer;
  ap , G	: Array[0..100 , 0..100] of Integer;
  
  a , b , sum	: Integer;
  i , j		: Integer;
  h , w		: Integer;
  max		: Integer;
begin
  while true do
    begin
      read(c); if c = 0 then break;
      read(n , m);
      fillchar(ap , sizeof(ap) , 0); 
      fillchar(G  , sizeof(G) , 0);
      for i:=1 to c do
        begin
	  read(a , b);
	  ap[a , b] := 1;
	end; 
      read(h , w);
      for i:=1 to n do
        begin
	  sum := 0;
          for j:=1 to m do
	    begin
	      sum := sum + ap[i , j];
	      G[i , j] := sum + G[i - 1 , j];
	    end;
	end;
      max  :=  0;
      for i := h to n do
        for j:= w to m do 
	  begin
	    sum := G[i , j] - G[i - h , j] - G[i , j - w] + G[i - h , j - w];
	    if sum > max then max := sum;
	  end;
      Writeln(max);
    end;  
end.