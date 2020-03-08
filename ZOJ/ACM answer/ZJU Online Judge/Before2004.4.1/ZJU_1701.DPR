program zju_1701;
//{$APPTYPE CONSOLE}
const
  direct : Array[1..8 , 1..2] of shortint =
    ((1 , 1) , (1 , 0) , (1 , -1) , (0 , 1) , (0 , -1) , (-1 ,1) , (-1 , 0) , (-1 , -1));
    
var
  N         : Integer;
  List      : Array[0..3 ,0..320] of Integer;
  Line      : Array[0..320] of Integer;

  function min (a , b     : Integer)    : Integer;
    begin
      if a < b then min := a else min := b;
    end;

  procedure Work;
    var
      value , Len     : Integer;
      p , r , y       : Integer;
      last , L        : Integer;
      i               : Integer;
    procedure printLine;
      var
        i , j         : Integer;
        c             : Integer;
      begin
        for i:=1 to n do
          begin
            Line[i] := 0;
            for j:=1 to 8 do
                if  (List[(p + direct[j , 1]) mod 4 , i + direct[j , 2]] >= 0)
                and (Abs(List[p mod 4 , i] - List[(p + direct[j , 1]) mod 4 , i + direct[j , 2]]) > Line[i])
                  then Line[i]:= Abs(List[p mod 4 , i] - List[(p + direct[j , 1]) mod 4 , i + direct[j , 2]]);
          end;
        if (Last = Line[1]) then c := L + 1 else
         begin  c := 1; if Last >= 0 then Writeln(Last , ' ' , L); end;
        for i:=2 to n do
          if (Line[i] = Line[i - 1]) then inc(c)
          else begin
            Writeln(Line[i - 1] , ' ' , c);
            c := 1;
          end;
        Last := Line[n]; L := c;
      end;

    procedure paintLine;
      begin
        While (y <= n) and (Len > 0) do
          begin
            Dec(Len); List[r mod 4 , y] := value;
            inc(y);
          end;
        if(y > n) then begin
          y := 1; inc(r);
          if r >= p + 2 then begin printLine; inc(p); end;
        end;
      end;

    begin
      if N > 1000 then begin
        Read(Value , Len);
        Writeln(0 , ' ' , Len);
        Read(Value , Len); Exit;
      end;
      fillchar(List , sizeof(List) , 255);
      p := 4; r := 4; y := 1; Last := - 1; L := 0;
      While true do
        begin
          Read(value , Len);
          if Len = 0 then Break;
          paintLine;
          if Len > 0 then paintLine;
          if Len > n then begin
            if Last <> 0 then begin Writeln(Last , ' ' , L); L := 0; Last := 0; end;
            L := L + Len div n * n;
            Len := Len mod n;
          end;
          paintLine;
        end;
      for i:=1 to n do
        List[r mod 4 , i] := -1;
      printLine;
      Writeln(Last , ' ' , L);
    end;

begin
//  Assign(Input , 'edge.in'); Reset(Input);
//  Assign(Output , 'Out.txt'); Rewrite(Output);
  while true do
    begin
      Read(N); Writeln(N);
      if n = 0 then Exit;
      Work;
      Writeln('0 0');
    end;
end.

