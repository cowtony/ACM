Program zju_1702;
var
  str , tmp	: string;
  List		: Array[1..25] of string;
  n , m		: Integer;

procedure Work;
  var
    i , j	: Integer;
    max	, p , L ,prev ,c : Integer;
  begin
    for i:=1 to n do
        List[i] := '| ' + List[i] + '&';
    prev := 1;
    for j:=1 to m do
      begin
        max := 0;
        for i:=1 to n do
	  begin
	    p := pos('&' , List[i]);
	    if p > max then max := p;
	  end;
	for i:=1 to n do
    	  begin
            c := 0;
	    repeat
	      p := pos('&' , List[i]);
              inc(c);
  	      if p < max then
                if (str[j] = '>') or ((str[j] ='=') and(c mod 2 = 0))  then Insert(' ' , List[i], prev + 1)
                else Insert( ' ' , List[i] , p);
	    until p = max;
	    delete(List[i] , p ,1);
	    Insert(' | ' , List[i] , p);
	  end;
        prev := max + 1;
      end;
    for i:=1 to n do
      begin
        Delete(List[i] , length(List[i]) , 1);
      end;
    L := length(List[1]);    
    Write('@');
    for i:=2 to L-1 do
      Write('-');
    Writeln('@');
    Writeln(List[1]);

    Write('|');
    for i:=2 to L-1 do
      if List[1][i] = '|' then Write('+') else Write('-');
    Writeln('|');

    for i:=2 to n do
      Writeln(List[i]);
    
    Write('@');
    for i:=2 to L-1 do
      Write('-');
    Writeln('@');    
  end;
 
begin
 // Assign(input , 'in.txt'); Reset(input);
  readln(str);
  while str <> '*' do
    begin
      n	:= 0; m := Length(str);
      while true do
        begin
	  readln(tmp);
	  if (tmp[1] in ['<' , '>' , '=' , '*']) then break;
	  inc(n);
	  List[n] := tmp;
	end;
      Work;
      str := tmp;      
    end;
end.
