Program zju_1005;

var
  G		: Array[0..500,0..500] of Integer;
  t,n,m,k	: Integer;
  i,j,key,sum	: Integer;
  x1,y1,x2,y2   : Integer;
  caseno	: Integer;
begin
  Read(t);
  for caseno:=1 to t do
    begin
      Read(n,m);
      fillchar(g,sizeof(g),0);
      for i:=1 to n do
      begin
        sum := 0;
        for j:=1 to m do
	  begin
	    Read(key); key := key * key; inc(sum,key);
	    G[i,j] := G[i-1,j] + sum;
	  end; 
      end;

      read(k);
      Writeln('Case ',caseno,':');

      for i:=1 to k do
        begin
	  read(x1,y1,x2,y2);
	  Writeln(G[x2,y2] - G[x2,y1 - 1] - G[x1 - 1,y2] + G[x1 - 1,y1 - 1]);
	end;     
    end;
end.
