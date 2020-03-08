program zju_1703;
{$APPTYPE CONSOLE}
  const
    player = 'ox';

  var
    Mark        : Char;
    G           : Array[0..3 , 0..3] of Char;
    i , j       : Integer;

  function Check_Wining(x , y : Integer ; p : Char) : Boolean;
    var
      i         : Integer;
      flag      : Boolean;
    begin
      Check_Wining := true;

      flag := true;
      for i:=0 to 3 do
        if G[i , y] <> p then begin
          flag := false; break;
        end;
      if flag then Exit;

      flag := true;
      for i:=0 to 3 do
        if G[x , i] <> p then begin
          flag := false; break;
        end;
      if flag then Exit;

      if ((G[0,0] = p) and (G[1,1] = p) and (G[2,2] = p) and (G[3,3] = p)) or
         ((G[0,3] = p) and (G[1,2] = p) and (G[2,1] = p) and (G[3,0] = p)) then Exit;

      Check_Wining := false;
    end;


  function Win(x , y , p , blank     : Integer)   :  Shortint;
    var
      cur       : Char;
      i , j     : Integer;
      ret , tmp : shortint;
    begin
      cur := player[p]; 
      G[x , y] := cur; dec(blank);
      if Check_Wining(x , y , cur) then begin
        Win := 1; G[x , y] := '.'; Exit;
      end;
      if blank = 0 then begin
        Win := 0; G[x , y] := '.'; Exit;
      end;

      ret := 1;
      for i:=0 to 3 do
        for j:=0 to 3 do
          if G[i , j] = '.' then begin
            tmp := Win(i , j , 3 - p , blank);
            if tmp = 1 then begin
              G[x , y] := '.'; Win := -1; Exit;
            end;
            if tmp = 0 then ret := 0;
          end;
          
      Win := ret;
      G[x , y] := '.'
    end;

  procedure Work;
    var
      i , j   : Integer;
      blank   : Integer;
    begin
      blank := 0;

      for i:=0 to 3 do
        for j:=0 to 3 do
          if G[i , j] = '.' then Inc(blank);

      for i:=0 to 3 do
        for j:=0 to 3 do
          if (G[i , j] = '.') then
            if Win(i , j , 2 , blank) = 1 then begin
              Writeln('(' , i , ',' , j , ')');
              Exit;
            end;
      Writeln('#####');
    end;

begin
 // Assign(Input , 'in.txt'); Reset(Input);
 // Assign(Output , 'out.txt'); Rewrite(Output);
  while true do
    begin
      Readln(Mark);
      if Mark = '$' then Break;

      for i:= 0 to 3 do
        begin
          for j:= 0 to 3 do
            Read(G[i , j]);
          Readln;
        end;

      Work;
    end;
end.
