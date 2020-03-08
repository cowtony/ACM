Program zju_1720;
var
  L     	: Array[0..8] of Integer;
  i             : Integer;
  first		: Boolean;
begin
{ Assign(input , 'in.txt'); Reset(input); }
  while not eof do
    begin
      for i:=8 downto 0 do
        Read(L[i]);
      Readln;
      first := true;
      for i:=8 downto 0 do
        if L[i] <> 0 then
          if ( first ) then begin
	    if(L[i] < 0) then Write('-');
	    if(Abs(L[i]) > 1) or (i = 0) then  Write(Abs(L[i])); 
	    if i > 0 then Write('x');
	    if i > 1 then Write('^' , i);
	    first := false;
	  end
	  else begin	    
	    if L[i] > 0 then Write(' + ') else Write(' - ');
	    if (abs(L[i]) > 1) or (i = 0) then Write(abs(L[i]));
	    if i > 0 then Write('x');
	    if i > 1 then Write('^' , i);
	  end;
      if first then Writeln(0) else Writeln;
    end;
end.
