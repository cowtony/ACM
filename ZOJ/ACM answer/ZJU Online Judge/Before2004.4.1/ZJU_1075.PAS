Program zju_1075;
type
  CardType = string[5];
var  
  List		: Array[1..12] of CardType;
  
  i		: Integer;
  a,b,c		: Integer;
  Outed		: Boolean;
  Count		: Integer;

function check(var a,b,c : CardType) : Boolean;
  var
    i		: Integer;
    c1,c2	: Integer;
  begin
    c1 := 0; c2 := 0;
    for i:=1 to 4 do 
      begin  
        if (a[i] <> b[i]) and (a[i] <> c[i]) and (b[i] <> c[i]) then inc(c1);
	if (a[i] = b[i]) and (b[i] = c[i]) then inc(c2);        
      end;
    check := (c1 + c2 = 4);
  end;

begin
// Assign(input,'in.txt'); Reset(input); 
  Outed := false;
  While not eof do
    begin
      if Outed then Writeln else Outed := true;
      Write('CARDS: ');
      for i:=1 to 12 do
        begin
	  repeat Readln(List[i]); until List[i] <> '';
	  Write(' ',List[i]);
	end;
      Writeln;

      Write('SETS:   ');
      Count := 0;
      for a:=1 to 10 do
        for b:=a+1 to 11 do
	  for c:=b+1 to 12 do
	    if Check(List[a] , List[b], List[c]) then begin
	      Inc(Count);
	      if count = 1 then Writeln('1.  ',List[a],' ',List[b],' ',List[c])
	      else Writeln('        ',Count,'.  ',List[a],' ',List[b],' ',List[c]);
	    end;
	     
      if Count = 0 then Writeln('*** None Found ***');
    end; 

end.
