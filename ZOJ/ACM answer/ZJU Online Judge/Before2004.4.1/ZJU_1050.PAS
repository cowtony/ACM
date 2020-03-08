{$n+}
Program zju_1050;
type
  reco = record
    str		: string;
    t1,t2	: Integer;
  end;
var
  Blocks,CaseNo		: Integer;
  source , docu		: string;
  
  List			: Array[1..256] of Reco;
  N			: Integer;

procedure Add_source; 
  var
    str			: string;
    i,j			: Integer;
    find		: Boolean;
  begin
    source := source + ' ';
    str := '';
    for i:=1 to Length(source) do
      begin
        if source[i] = ' ' then begin
	  if str <> '' then begin
	    find := false;

	    for j:=1 to n do
	      if str = List[j].str then begin
	        find := true; inc(List[j].t1); break;
	      end;

	    if not find then begin
	      inc(N); List[N].str := str;
	      List[N].t1 := 1;
	    end;

	    str := '';
	  end;
	end
	else if (('a' <= source[i]) and (source[i] <= 'z')) or (('0' <= source[i]) and (source[i] <= '9')) then str := str + source[i]
	else if (('A' <= source[i]) and (source[i] <= 'Z')) then str := str + chr( ord(source[i]) + 32 );
      end;
  end;

procedure Add_Docu;
  var
    str			: string;
    i,j			: Integer;
  begin
    docu := docu  + ' ';
    str := '';
    for i:=1 to Length(docu) do
      begin
        if docu[i] = ' ' then begin
	  if str <> '' then begin

	    for j:=1 to n do
	      if str = List[j].str then begin
		 inc(List[j].t2); break;
	      end;

	    str := '';
	  end;	    
	end
	else if (('a' <= docu[i]) and (docu[i] <= 'z')) or (('0' <= docu[i]) and (docu[i] <= '9')) then str := str + docu[i]
	else if (('A' <= docu[i]) and (docu[i] <= 'Z')) then str := str + chr( ord(docu[i]) + 32 );
      end;    
  end;

var 
  i			: Integer;
  sum			: Double;
begin
{  Assign(input,'in.txt'); Reset(input); }
  Readln(Blocks);
  for CaseNo :=1 to Blocks do
    begin
      Readln; N := 0;
      while true do
        begin
	  readln(source);
	  if source = '----------' then break;	  
	  Add_source;
	end;

      while true do
        begin	  
	  for i:=1 to n do
	    List[i].t2 := 0;

	  readln(docu);
	  if docu = '----------' then break;
	  repeat
	    Add_docu;
	    readln(docu);
	  until docu = '----------';

	  sum := 0;
	  for i := 1 to n do
	    sum :=sum + sqrt (List[i].t1 * List[i].t2);
	  
	  Writeln(sum : 0 : 2);
	end;

      if CaseNo < Blocks then Writeln;
    end;
end.
