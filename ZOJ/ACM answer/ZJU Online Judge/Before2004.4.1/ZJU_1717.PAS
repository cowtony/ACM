Program zju_1717;
var
  n , m		: Integer;
  G		: Array[1..70] of string;
  f		: Array[0..70 , 0..70] of Integer;
  reco		: Array[0..70 , 0..70] of string;


procedure work;
  var
    i , j , max	: Integer;
    sol         : string;

  begin
    fillchar(f , sizeof(f) , 0);
    for i:=1 to n do
      for j:=1 to m do
        if ('1' <= G[i,j]) and (G[i,j] <= '9') then begin f[i,j] := 1; reco[i,j]:=G[i,j]; end
	else begin f[i , j]:=-10000; reco[i,j]:=''; end;
    for i:=1 to n do
      begin
        f[i , 0] := -10000;
	reco[i ,0]:='';
      end;
    for j:=1 to m do
      begin
        f[0 , j] := -10000;
	reco[0,j]:='';
      end;

    for i:=1 to n do
      for j:=1 to m do
        if ('0' <= G[i,j]) and (G[i,j] <= '9') then
          begin
	    if f[i-1, j]+1 > f[i,j] then begin f[i,j] := f[i-1,j] + 1; reco[i,j]:=reco[i-1,j] + G[i,j] end;
	    if (f[i-1,j]+1 = f[i,j]) and (reco[i-1,j]+ G[i,j] > reco[i,j]) then reco[i,j] := reco[i-1,j] + G[i,j];
	    if f[i, j-1]+1 > f[i,j] then begin f[i,j] := f[i,j-1] + 1; reco[i , j] := reco[i,j-1] + G[i,j] end;
	    if (f[i,j-1]+1 = f[i,j]) and (reco[i,j-1]+ G[i,j] > reco[i,j]) then reco[i,j] := reco[i,j-1] + G[i,j];
	  end;
    max := 0;
    for i:=1 to n do
      for j:=1 to m do
        if max < f[i , j] then begin max := f[i,j]; sol := reco[i,j] end
	else if (max = f[i , j]) and (reco[i , j] > sol) then sol := reco[i ,j];
    Writeln(sol);
  end;

var
  i		: Integer;
begin
  while true do
    begin
      readln(m , n);
      if n = 0 then break;
      for i:=1 to n do
        Readln(G[i]);
      work;
    end;   
end.
