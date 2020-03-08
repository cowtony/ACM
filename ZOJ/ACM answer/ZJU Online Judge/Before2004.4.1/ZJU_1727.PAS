program zju_1727;
//{$APPTYPE CONSOLE}
type
  piece = record
    G     : Array[1..25] of string[25];
    top, left, bottom , right : Integer;
  end;
var
  N , H , W     : Integer;
  List          : Array[0..100] of piece;
  Used          : Array[0..100] of Boolean;
  map           : Array[0..10 , 0..10] of Integer;

function findpiece(left , top     : Integer) : Integer;
  var
    i           : Integer;
  begin
    for i:=1 to n * n do
      if (List[i].left = left) and (List[i].top = top) then begin findpiece := i; exit; end;
  end;

procedure Print;
  var
    i , j , k   : Integer;
  begin
    for i:=1 to n do
      begin
        for k:=1 to H do
          begin
            for j:=1 to n do
              Write(List[map[i , j]].G[k]);
            Writeln;
          end;
      end;
  end;

function search(x , y       : Integer)  : Boolean;
  var
    i             : Integer;
  begin
    if (y > N) then begin
      Inc(x); y := 1;
    end;
    if (x > N) then begin
      search := true; print; exit;
    end;

    search := true;
    for i:=1 to N * N do
      if (not Used[i]) and (List[i].left + List[map[x , y - 1]].right = 0) and (List[i].top + List[map[x - 1 , y]].bottom = 0)
         then begin
           map[x , y] := i;
           Used[i] := true;
           if search(x , y + 1) then exit;
           Used[i] := false;
         end;
    search := false;
  end;

var
  i , j         : Integer;
begin
 // Assign(input , '399.in'); Reset(input);
 // Assign(output , 'out.txt'); Rewrite(output);
  List[0].left := 0;
  List[0].right := 0;
  List[0].top := 0;
  List[0].bottom := 0;
  While not eof do
    begin
      Readln(N , H , W);
      for i:=1 to N * N do
        begin
          With List[i] do
            begin
              for j:=1 to H do
                Readln(G[j]);
              Readln(top, left, bottom , right);
            end;
          Readln;
        end;

      fillchar(map , sizeof(map) , 0);
      fillchar(Used , sizeof(Used) , 0);
      Search(1 , 1);
    end;

end.
