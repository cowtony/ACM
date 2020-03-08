Program zju_1745;
var
  target	: Integer;
  Now , Next	: Integer;  
  first		: Boolean;
begin
  first	:= true;
  While true do
    begin
      Read(Target);
      if Target = 5280 then Break;
      if first then first := false else Writeln;
      Now := 0;
      While true do
        begin
	  Read(Next);
	  Write('Moving from ',Now,' to ',Next,': ');
	  if Next = target then begin
	    Writeln('found it!'); Break;
	  end;
	  if abs(Next - target) > abs(Now - target) then Writeln('colder.')
	  else if abs(Next - target) < abs(Now - target) then Writeln('warmer.')
	  else Writeln('same.');
	  Now := Next;
	end;      
    end;
end.
