Program zju_1811;
var
  List			: Array[1..1000] of integer;
  N , c , point		: Integer;
  Mark			: Array[1..100]	of Integer;
  a , b , k		: Integer;
  pos			: Array[0..6] of Integer;

procedure Work;
  var
    i			: Integer;
    cur			: Integer;
  begin
    for i:=0 to n -1 do pos[i] := 0;
    i := -1; point := 0;
    while true do
      begin
        i := (i + 1) mod n;
	if pos[i] < 0 then begin
	  pos[i] := -pos[i]; continue;
	end;
	inc(point);
	if (pos[i] >= 94) then begin
	  if (List[point] <> 100 - pos[i]) then continue;
	  Writeln(i + 1); exit;
	end;
	pos[i] := pos[i] + List[point];
	if Mark[pos[i]] > 0 then pos[i] := Mark[pos[i]];
	if(Mark[pos[i]] = -1) then begin
	  i := i - 1; continue;
	end;
	if(Mark[pos[i]] = -2) then begin
	  pos[i] := - pos[i];	   
	end;
      end;

  end;

begin  
  c := 0;
  while true do
    begin
      Inc(c);
      read(List[c]);
      if List[c] = 0 then break;
    end;
  Dec(c);

  while true do
    begin
      read(n);
      if n = 0 then break;
      fillchar(Mark , sizeof(Mark) , 0);
      while true do
        begin
	  read(a , b);
	  if a = 0 then break;
	  Mark[a] := b;
	end;
      while true do
        begin
	  read(k);
	  if k = 0 then break;
	  if k > 0 then Mark[k] := -1 else Mark[-k] := -2;
	end;
      Work;
    end;
end.
