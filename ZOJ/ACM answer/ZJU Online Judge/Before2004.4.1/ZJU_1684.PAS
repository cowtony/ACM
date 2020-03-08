{$mode delphi}
Program zju_1684;
const
{                  abcdefghijklmnopqrstuvwxyz }
  tran : string = '22233344455566677778889999';
var
  n		: Integer;
  Words		: Array[1..50] of String;
  code		: Array[1..50] of String;
  L		: Array[1..50] of Integer;
  Source	: String;
  f		: Array[1..1255 , 1..20] of Integer;
  Got		: Array[0..1255] of Integer;
  OnTarget	: Array[0..1255] of Boolean;
  Len		: Integer;

  C		: Integer;
  Ans		: Array[1..20] of string;

procedure Work;
  var 
    i , j	: Integer;
  begin
    for i:=1 to n do
      begin
        code[i] := Words[i];
	L[i] := length(Words[i]);
	for j:=1 to L[i] do
	  Code[i][j] := tran[ord(Code[i][j]) - ord('a') + 1];
      end;
  end;

procedure Search(p	: Integer; s	:string);
  var
    i		: Integer;
  begin
    if p = 0 then begin
      inc(c);
      Ans[c] := s;
      exit;
    end;

    if p <> Len then s := ' ' + s;
    for i:=1 to Got[p] do
      Search(p - L[f[p,i]] , Words[f[p,i]] + s); 
  end;

procedure Main;
  var    
    i , j	: Integer;
    tmp		: string;
  begin
    fillchar(Got , sizeof(Got) , 0); Got[0] := 1;
    Len := length(source);
    for i:=0 to Len do
      if Got[i] > 0 then
        for j:=1 to n do
	  if L[j] + i <= Len then begin
	    if copy(source , i + 1 , L[j]) = code[j] then begin
	      inc(Got[i + L[j]]);
	      f[i + L[j] , Got[i + L[j]] ] := j;
	    end;
	  end;
    C := 0;
    Search(Len , ''); 
    for i:=1 to c-1 do
      for j:=i+1 to c do
        if Ans[j] < Ans[i] then begin
	  tmp :=Ans[i]; Ans[i] := Ans[j]; Ans[j] := tmp;
	end;
    for i:=1 to c do
      Writeln(Ans[i],'.');

    Writeln('--');
  end;

var
  i 		: Integer;
begin
  While true do
    begin
      Readln(n);
      if n = 0 then break;
      for i:=1 to n do
        Readln(Words[i]);
      Readln(source);
      Work;
      Main;
    end;
end.
