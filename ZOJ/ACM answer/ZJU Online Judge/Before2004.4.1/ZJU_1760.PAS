Program pku_1552;
var
  ret		: Integer;
  k		: Integer;
  Count		: Array[1..100] of Integer;
  i		: Integer;

function min(a,b: Integer) : Integer;
  begin
    if a < b then min := a else min := b;
  end;
begin
  while true do
    begin
      Read(k);
      if k < 0 then break;
      fillchar(count , sizeof(count) , 0);      
      while k > 0 do
        begin
	  inc(count[k]);
	  read(k);
	end;
      ret := 0;
      for i:=1 to 50 do
        if (Count[i] > 0) and (Count[i * 2] > 0) then
	  begin
	    ret := ret + min(Count[i] , Count[i * 2]);
	  end;
      Writeln(ret);
    end;
end.
