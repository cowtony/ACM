Program zju_1697;
var
  List			: Array[1..6,0..2] of Integer;
  count			: Array[1..100] of Integer;  
  str			: string;
  Best			: Integer;

function check : boolean;
  var
    i		: Integer;
  begin
    check := false;
    for i:=1 to 100 do
      if count[i] <> 0 then exit;
    check := true;
  end;  

procedure search(p , got	: Integer);
  var
    i		: Integer;
  begin
    if p > 6 then begin
      if (Got > Best) and (check) then Best := Got;
      exit;
    end;
    for i:=0 to 2 do
      begin
        Inc(count[ List[p , (i + 1) mod 3] ]);
	Dec(count[ List[p , (i + 2) mod 3] ]);
	Search(p + 1 , got + List[p , i]);
	Dec(count[ List[p , (i + 1) mod 3] ]);
	Inc(count[ List[p , (i + 2) mod 3] ]);
      end;
  end;

var
  i , j			: Integer;
begin
  While true do
    begin
      
      for i:=1 to 6 do
        for j:=0 to 2 do	
	    Read(List[i , j]);
	
      Best := -1;
      fillchar(count , sizeof(count) , 0);
      Search(1 , 0);
      if Best > 0 then Writeln(Best) else Writeln('none');
      Readln;
      Readln(str);
      if (str = '$') then break;
    end;
end.