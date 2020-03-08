Program Zju_1625;
type
  gene = Array[1..20] of 0..1;
var
  N,T		: Longint;
  
  i		: Integer;
  List		: Array[0..800] of gene;

function Fix(x	: Integer) : Integer;
  begin
    if x > n then dec(x,n);
    if x < 1 then inc(x,n);
    Fix := x;
  end;

procedure Work;
  var
    i,j		: Integer;
    start,rep,tmp	: Integer;

  function check(a,b : Integer): Boolean;
    var
      k		: Integer;
    begin
      check := false;
      for k :=1 to n do
        if List[a][k] <> List[b][k] then Exit;
      check := True;
    end;

  procedure print(k	: Integer);
    var
      i		: Integer;
    begin
      for i:=1 to n-1 do
        Write(List[k][i],' ');
      Writeln(List[k][n]);
    end;

  begin
    rep := -1;
    for i:=1 to T do
      begin
        for j:=1 to n do
	  begin
	    tmp := List[i-1][fix(j-2)] + List[i-1][fix(j-1)] + List[i-1][fix(j+1)] + List[i-1][fix(j+2)];
	    if (List[i-1][j] = 0) and ((tmp = 2) or (tmp = 3)) then List[i][j] := 1
	    else if (List[i-1][j] = 1) and (tmp <> 2) and (tmp <> 4) then List[i][j] := 0
	    else List[i][j] := List[i-1][j];
	  end;
	
	for j:=0 to i-1 do
	if check(i,j) then
	  begin
	    start := j; rep := i - j; break;	    
	  end;
	if rep > 0 then break;
      end;
    if rep < 0 then print(T)
    else print( start + (T - start) mod rep);
  end;

begin
  While Not eof do
    begin
      Read(N,T);
      for i:=1 to N do
        Read(List[0][i]);
      Readln;

      Work;
    end;
end.
