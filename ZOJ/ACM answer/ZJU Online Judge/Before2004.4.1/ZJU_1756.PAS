Program zju_1756;
var
  n		: Integer;
  List		: Array[1..600] of Integer;
  used		: Array[1..600] of Boolean;  
  i , j , k	: Integer;
  ret		: Integer;
begin
  while true do
    begin
      n := 1;
      read(k , List[1]);
      if k < 0 then Break;
      while true do
        begin
	  inc(n);
	  Read(k , List[n]);
	  if k = 0 then Break;
	end;
      Dec(n);

      fillchar(used , sizeof(used) , 0);
      ret := 0;
      for i:=1 to n do
        if ( not used[i] ) then begin
	  k := i; inc(ret); used[i] := true;
	  for j:=i + 1 to n do
	    if (not used[j]) and (List[j] >= List[k]) then begin
	      k := j; used[j] := true;
	    end;
	end;
      Writeln(ret);
    end;
end.
