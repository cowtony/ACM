
Program zju_1718;
const MAXN = 100;
type
  Circle = record
    x , y , z	: double;
    r		: double;
  end;
var
  n		: Integer;
  List		: Array[1..MAXN] of Circle;
  G		: Array[1..MAXN , 1..MAXN] of double;
  Low		: Array[1..MAXN] of Integer;

  function dist(var a , b	: Circle)	: double;
    var
      ret	: double;
    begin
      ret := sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z)) - a.r - b.r;
      if ret < 0 then ret := 0;
      dist := ret;
    end;

  procedure Work;
    var
      i , j , k	: Integer;
      min	: double;
      Ret	: double;
    begin
      for i:=1 to n do
        for j:=1 to n do
	  G[i , j] := dist(List[i] , List[j]);
      ret := 0;
      Low[1] := -1;
      for i:=2 to n do Low[i] := 1;

      for j:=2 to n do
        begin
	  min := 1e10;
	  for i:=1 to n do
	    if (Low[i] > 0) and (G[i , Low[i]] < min) then begin
	      k := i;  min := G[i , Low[i]];
	    end;
	  ret := ret + min;
	  Low[k] := -1;
	  for i:=1 to n do
	    if (Low[i] > 0) and (G[i , k] < G[i , Low[i]]) then Low[i] := k;
	end;
      Writeln(ret : 0 : 3);
    end;

var
  i		: Integer;
begin
  While true do
    begin
      Read(n);
      if n = 0 then break;
      for i:=1 to n do 
        With List[i] do
	  Read(x , y , z , r);
      Work;
    end;
end.
