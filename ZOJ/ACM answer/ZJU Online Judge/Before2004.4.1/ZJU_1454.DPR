program zju_1452;
type Integer= Longint;
const
  MAXLEN	= 1000;
var
  n		: Integer;
  A , B , C	: Integer;
  List		: Array[1..12] of Integer;
  max		: Integer;
  
  f0 , f1	: Array[0..MAXLEN] of Integer;  

function min(a , b	: Integer)	: Integer;
  begin
    if a < b then min := a else min := b;
  end;

procedure solve;
  var
    i , j , k	: Integer;
    addon       : Integer;
  begin
    for i:=0 to max do
      f0[i] := i * A;
    
    for i:=1 to n do
      begin
        for j:=0 to List[i] - 1 do
	  f1[j] := 10000000;
	for j:=List[i] to max do
	  f1[j] := f0[j] + j * B;
	if i < n then      //////last day, no need to hire or fire
	for j:=List[i] to max do
	  begin
	    addon := f0[j] + j * b;
	  {
	    for k:=j+1 to List[i+1] do      /// here change max to List[i + 1]
	      f1[k] := min(f1[k] , (k - j) * A + f0[j] + j * B);
	      }
	    if j < List[i+1] then begin
	      k := List[i+1];
	      f1[k] := min(f1[k] , (k - j) * A + addon);
	    end;
	    for k:=j-1 downto List[i + 1] do /// here change 0 to list[i + 1]
	      f1[k] := min(f1[k] , (j - k) * C + addon);
	  end;
	move(f1 , f0 ,sizeof(f1));
      end;
    k := f0[List[n]];
    for i:=List[n] + 1 to max do
      if f0[i] < k then k := f0[i];
    Writeln(k);
  end;

var
  i		: Integer;

begin
  While true do
    begin
      Read(n);
      if n = 0 then break;

      Read(A , B , C);
      max := 0;
      for i:=1 to n do
        begin
	  read(List[i]);
	  if List[i] > max then max := List[i];
	end;

      if Max > MAXLEN then RunError(Max);
      solve;      
    end;
end.
