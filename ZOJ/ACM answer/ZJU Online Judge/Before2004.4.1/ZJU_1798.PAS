Program zju_1798;
var
  CaseNo	: Integer;
  n		: Integer;
  G		: Array[0..10 , 0..10] of Boolean;
  visited	: Array[1..10] of Boolean;
  i , k		: Integer;

function search(u , k	: Integer)	: Boolean;
  var
    i		: Integer;
  begin
    search := true;
    if (k = n) then begin
        if (not G[u , 0]) then search := false;	
	Exit;
      end;
    for i:=1 to n do
      if (not visited[i]) and (G[u , i]) then begin
        visited[i] := true;
	if search(i , k + 1) then exit;
	visited[i] := false;        
      end;
    search := false;
  end;

begin
  CaseNo := 0;
  while true do
    begin
      Readln(n);
      if n = 0 then break;
      fillchar(G , sizeof(G) ,0);
      for i:=1 to n do
        begin
	  while not eoln do
	    begin
	      read(k); G[i , k] := true; G[k , i] := true;
	    end;
	  readln;	  
	end;

      Inc(CaseNo);
      fillchar(visited , sizeof(visited) , 0);
      if Search(0 , 0) then Writeln('Case ' , CaseNo , ': Granny can make the circuit.')
      else Writeln('Case ' , CaseNo , ': Granny can not make the circuit.');
    end;
end.
