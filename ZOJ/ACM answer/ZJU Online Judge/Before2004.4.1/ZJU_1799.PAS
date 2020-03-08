Program zju_1799;
var
  key , source		: string;
  Len , Col		: Integer;
  G			: Array[1..10 , 1..100] of char;

function find_next	: Integer;
  var
    k , i		: Integer;
  begin
    k := 1;
    for i:=2 to Len do
      if key[i] < key[k] then k := i;
    key[k] := '^'; find_next := k;    
  end;

procedure Work;
  var
    i , k , j , p	: Integer;
  begin
    p := 0;
    for i:=1 to Len do
      begin
        k := find_next;
	for j := 1 to Col do
	  begin
	    inc(p);
	    G[j , k] := source[p];
	  end;
      end;
    for i:=1 to Col do
      for j:=1 to Len do
        Write(G[ i , j ]);
    Writeln;    
  end;

begin
  while true do
    begin
      readln(key);
      if key = 'THEEND' then break;      
      readln(source);
      Len := length(key); Col := length(source) div Len;
      Work;
    end;
end.
