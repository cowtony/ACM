program zju_1653;
{$APPTYPE CONSOLE}
const TOP = 5000;
var
  CaseNo          : Integer;
  K , N           : Integer;
  Max             : Integer;
  Ans , Stack     : Array[1..10] of Integer;
  Bot             : Array[0..TOP] of Boolean;

function Calc(n   : Integer)   : Integer;
  procedure fill( s , last , c : Integer);
    begin
      Bot[s] := true;
      if (last = n) or (c = k) then Exit;
      fill(s , last + 1 , c);
      fill(s + Stack[last + 1] , last , c + 1);
    end;
  var
    i             : Integer;
  begin
    fillchar(Bot , sizeof(Bot) , 0);
    Fill( 0 , 0 , 0 );
    for i:=1 to TOP do
      if not Bot[i] then begin Calc := i; exit; end;
  end;

procedure Search(Last : Integer; pipe   : Integer);
  var
    i , ret       : Integer;
  begin
    if pipe > N then begin
      ret := Calc(pipe - 1) - 1;
      if ret > Max then begin
        Move(Stack[1] , Ans[1] , sizeof(Integer) * N);
        Max := ret;
      end;
      Exit;
    end;

    ret := Calc(pipe - 1);
    for i := Last + 1 to ret do
      begin
        Stack[pipe] := i;
        Search(i , pipe + 1);
      end;
  end;

procedure Work;
  var
    i             : Integer;
  begin
    Max := 0;
    Stack[1] := 1;
    Search(1 , 2);

    Writeln(Max);
    for i:= 1 to N - 1 do
      Write(Ans[i] , ' ');
    Writeln(Ans[N]);
  end;

begin
  Assign(Input , 'In.txt'); Reset(Input);
  Assign(output , 'Out.txt'); Rewrite(Output);

  Read(CaseNO);
  While CaseNO > 0 do
    begin
      Dec(CaseNO);

      Read(K , N);
      N := N div 100;
      if (K = 0) or (N = 0) then Writeln('sorry')
      else Work;
    end;          
end.
