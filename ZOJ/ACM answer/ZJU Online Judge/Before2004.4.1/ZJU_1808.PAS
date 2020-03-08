Program zju_1808;
var
  N		: Integer;
  List		: Array[1..100] of string;
  CaseNO	: Integer;

function check	: Boolean;
  var
    i , j	: Integer;
  begin
    Check := false;
    for i:=1 to n do
     for j:=1 to n do
       if (i <> j) and (pos(List[i] , List[j]) = 1) then Exit;
    Check := true;       
  end;
begin 

  CaseNo := 0;
  While not eof do
    begin
      N := 0;
      While true do
        begin
	  Inc(N);
	  Readln(List[N]);
	  if List[n] = '9' then break;	  
	end;
      dec(N);
      Inc(CaseNO);
      if Check then Writeln('Set ', CaseNo , ' is immediately decodable')
      else Writeln('Set ' , CaseNO , ' is not immediately decodable');      
    end;
end.
