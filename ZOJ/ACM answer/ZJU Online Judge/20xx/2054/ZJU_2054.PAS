Program Ural_L;
var
  K,C		: Integer;
  App		: Array[1..10001] of Boolean;


function B_Search(N	: Integer)	: Boolean;
var
  p, q, i, L	: Integer;
begin
  p := 0;   { Left border of the search  }
  q := N-1; { Right border of the search }
  L := 0;   { Comparison counter         }
  while p <= q do
   begin
    i := (p + q) div 2;
    inc(L);
    if i = K then begin
      if L = C then B_Search := True else B_search := False; Exit;
    end;
    if k < i then
      q := i - 1
    else
      p := i + 1;
   end;
  B_search := False;
end;

procedure print;
  var i,C	: Integer;
      st,ed	: Integer;
  begin
    st := 1; c := 0;
    while (st <= 10000) do
      begin
        while (not App[st]) and (st <= 10000) do inc(st);
	if st > 10000 then break;
	ed := st;
	while App[ed] do Inc(ed);
	Inc(c);
	st := ed;
      end;
    Writeln(c);
    st := 1;
    while (st <= 10000) do
      begin
        while (not App[st]) and (st <= 10000) do inc(st);	
	if st > 10000 then break;
	ed := st;
	while App[ed] do Inc(ed);
	Writeln(st,' ',ed - 1);
	st := ed;
      end;   
  end;

var
  N	: Integer;

var
  T , TC	: Integer;
begin
  Readln(T);
  for TC := 1 to T do
    begin

  Read(K,C);
  fillchar(App,sizeof(App),0);
  for N:=1 to 10000 do
    if B_search(N) then  App[N] := True; 
  print;
  if TC < T then Writeln;
  end;
end.
