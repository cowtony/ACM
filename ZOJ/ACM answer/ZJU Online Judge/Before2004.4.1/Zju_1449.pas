Program Zju_1449;
type Integer = Longint;
var
  N		: Integer;
  G		: Array[0..20,0..20,0..20] of Integer;

  x1,y1,x2,y2,
  i,j,k,
  key,sum	: Integer;
  Max		: Integer;  

begin
  Read(N);
  while N > 0 do
    begin
      fillchar(G,sizeof(G),0);
      for i := 1 to N do
        for j := 1 to N do
	  begin
	    sum := 0;
	    for k := 1 to N do
	      begin
	        read(key);
		inc(sum,key);
		G[i,j,k] := G[i,j-1,k] + sum;
	      end;
	  end;	   
      
      Max := -10000000;
      for x1 := 1 to N do
        for y1:= 1 to N do
	  for x2 := x1  to N do
	    for y2 := y1 to N do
	      begin
	        sum := 0;
	        for k :=1 to N do
	          begin
	            sum := sum + G[k,x2,y2] - G[k,x2,y1 - 1] - G[k,x1 - 1, y2] + G[k,x1 - 1, y1 -1];
		    if sum > Max then Max := sum;
		    if sum < 0 then sum := 0;
	          end;
	      end;
       Writeln(Max);
      Read(N);
    end;
end.
