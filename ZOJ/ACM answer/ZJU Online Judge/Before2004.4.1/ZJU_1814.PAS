Program zju_1814;
var
  N		: Integer;
  List , tmp	: Array[0..100] of Integer;
  i , mem , T	: Integer;
  flag		: Array[0..100] of Integer;
function Check	: Boolean;
  var
    i		: Integer;
  begin
    Check := false;
    for i:=2 to n do
      if List[i] <> List[i-1] then Exit;
    Check := true;
  end;

begin
  While true do 
    begin
      read(N);
      if N = 0 then break;
      for i:=1 to N do 
        Read(List[i]);
      T := 0;
      mem := sizeof(Integer) * N;
      While Not Check do
        begin
	  move(List[1] , tmp[1] , mem);
	  tmp[0] := List[n];	  
	  for i := 1 to n do
	    begin
	      List[i] := (tmp[i] div 2 + tmp[i - 1] div 2);
	      if odd(List[i]) then Inc(List[i]);
	    end;
	  Inc(T);
	end;
      Writeln(T , ' ' , List[1]);      
    end;
end.
