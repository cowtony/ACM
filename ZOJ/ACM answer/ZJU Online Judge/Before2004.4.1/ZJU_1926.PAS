Program zju_1926;
var
  k		: Integer;

  Mark		: Array[1..10] of ShortInt;

procedure Judge;
  var
    str		: string;    
    rec		: boolean;

  function check	: boolean;
    var
      i		: integer;
    begin
      check := false;
      for i:=1 to 10 do
        begin
          if (mark[i] = 0) and (i >= k) then exit;
	  if (mark[i] = 1) and (i <= k) then exit;
	end;
      check := true;
    end;

  begin
    readln(str);
    if str = 'right on' then begin Writeln('Stan may be honest'); exit; end;
    fillchar(mark , sizeof(mark) , 255);
    mark[k] := ord(str = 'too high');
    rec	:= true;

    while true do
      begin
        readln(k);
	readln(str);
	if str = 'right on' then begin
	  if rec and Check then Writeln('Stan may be honest') else Writeln('Stan is dishonest');
	  exit;
	end;
	if mark[k] < 0 then begin
	  mark[k] := ord(str = 'too high');
	end
	else if mark[k] <> ord(str = 'too high') then rec := false;	 
      end;
  end;

begin  
  While true do
    begin
      Readln(k);
      if k = 0 then break;
      Judge;
    end;
end.
