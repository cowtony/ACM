program zju_2002;
//{$APPTYPE CONSOLE}
var
  T		: Integer;
  N , K		: Integer;
  p , r		: LongWord;

  List		: Array[1..500] of Integer;
  partition ,
  osp		: Array[0..500] of Integer;

procedure Init;
  var
    i		: Integer;
  begin
    p := 0; r := 0;

    Read(N , K); dec(K);
    for i:=1 to N do
      begin
        Read(List[i]);
	if List[i] > p then p := List[i];        
	r := r + List[i];
      end;
  end;

function Greedy(Limit	: Integer)  : Boolean;
  var
    i , p , j	: Integer;
    sum		: Integer;
  begin 
    Greedy := true;

    p := k;
    sum := List[n];
    for i:=n - 1 downto 1 do
      begin
        if(i = p) then begin
	  for j:=p downto 1 do
	    partition[j] := j + 1;
	  Exit;
	end;

	if(sum + List[i] > Limit) then begin
	  partition[p] := i + 1; dec(p); sum := List[i];
	  if p < 0 then begin Greedy := false; exit; end;
	end
	else sum := sum + List[i];
      end;
  end;

procedure Work;
  var
    m		: LongWord;
  begin
    fillchar(Partition , sizeof(Partition) ,0);
    fillchar(Osp , sizeof(Osp) , 0);
    while (p <= r) do
      begin
        m := (p + r) div 2;
        if (Greedy(m)) then begin r := m - 1; osp := partition; end
	else p := m + 1;
      end;
  end;

procedure PrintAns;
  var
    i , p	: Integer;
  begin
    p := 1;
    Write(List[1]);
    for i:=2 to n do
      begin
        if (osp[p] = i) then begin Write(' /'); Inc(p); end;
	Write(' ' , List[i]);
      end;
    Writeln;
  end;

begin
 // Assign(Input , 'In.txt'); Reset(Input);
 // Assign(Output , 'Out.txt'); Rewrite(Output);
  Read(T);
  While T > 0 do
    begin
      Dec(T);

      Init;
      Work;
      PrintAns;
    end;
end.
