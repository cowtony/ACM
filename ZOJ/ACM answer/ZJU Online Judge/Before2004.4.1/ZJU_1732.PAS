program zju_1732;
//{$APPTYPE CONSOLE}
var
  N , tot         : Integer;
  Len             : Integer;
  List            : Array[1..10000] of Integer;
  p               : Array[1..1000] of Integer;
  procedure Init;
    var
      i  , k      : Integer;
    begin
      Read(tot);
      n := trunc(sqrt(tot * 2)) + 1;
      fillchar(List , sizeof(List) , 0);
      for i:=1 to tot do
        begin
          Read(K);
          Inc(List[k]);
        end;
      Len := K;
      fillchar(p , sizeof(p) , 0);
      p[1] := 0; p[N] := Len;
      Dec(List[Len]);
    end;

  procedure Calc_Answer;
    var
      i , ret       : Integer;
    begin
      ret := 1;
      for i:=1 to n - 1 do
        ret := ret * (p[i + 1] - p[i]);
      Writeln(ret);
    end;

  function Search(pos , k         : Integer)  : Boolean;
    var
      i             : Integer;
      point         : Integer;
    begin
      search := true;
      if k = N then begin
        Calc_Answer;
        Exit;
      end;
      if pos >= Len then begin search := false; exit; end;

      //Try this position
      if List[ p[n] - pos ] > 0 then
        begin
          dec( List[p[n] - pos] );
          point := 1;
          While (point < k) and (List[pos - p[point]] > 0) do
            begin
              Dec(List[pos - p[point]]);
              Inc(point);
            end;
          p[k] := pos;
          if point = k then
            if search(pos + 1 , k + 1) then Exit;
          inc( List[p[n] - pos] );
          for i:=1 to point - 1 do
            Inc(List[pos - p[i]]); 
        end;
      //next
      if (Search(pos + 1 , k)) then Exit;
      search := false;
    end;

begin
// Assign(Input , 'E.in'); Reset(Input);
//  Assign(Output , 'Out.txt'); Rewrite(Output);

  While Not Eof do
    begin
      Init;
      if (not Search(1 , 2)) then Writeln('No solution');
    end;
end.
