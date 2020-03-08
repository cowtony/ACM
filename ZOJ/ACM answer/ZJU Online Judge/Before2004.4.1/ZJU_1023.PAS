Program zju_1023;
const
  MAXN = 150;
  MAXM = 50;
type
  student = record
    Region , Score , K	: Integer;
    U			: Integer;
    Oked		: Boolean;
    List		: Array[1..MAXM] of Integer;
  end;
  university = record
    Region , C		: Integer;
    K			: Integer;
    List		: Array[1..MAXN + 1] of Integer;
  end;
var
  T		: Integer;
  N,M		: Integer;
  S		: Array[1..MAXN] of student;
  U		: Array[1..MAXM] of University;

procedure Work;
  var
    i		: Integer;
    Less	: Integer;

  function Comp( a , b	, K	: Integer)	: Boolean;
    begin
      if (S[a].Region = U[k].Region) And (S[b].Region = U[k].Region) then Comp := (S[a].score > S[b].score)
      else if (S[a].Region = U[k].Region) then Comp := (S[a].score > S[b].score * 0.7)
      else if (S[b].Region = U[k].Region) then Comp := (S[a].score * 0.7 >= s[b].score)
      else Comp := (S[a].score > S[b].score)
    end;

  procedure Try_Next( A		: Integer);
    var
      i,j,K	: Integer;
    begin
      Inc(S[A].U);
      { not accepted }
      if (S[A].U > S[A].K) then begin
        S[A].U := -1; S[A].Oked := True; Dec(Less); Exit;
      end;

      { Try Next University }
      K := S[A].List[ S[A].U ];
      for i:=1 to U[K].k do
        if Comp( A , U[K].List[i] , K ) then
          begin
	    for j := U[K].K downto i do
	      U[K].List[j + 1] := U[K].List[j];
	    U[K].List[i] := A;

	    if (U[K].K = U[K].C) then begin
	      S[A].Oked := true; S[ U[K].List[ U[K].K + 1 ] ].Oked := false;
	    end
	    else begin
	      Inc(U[K].K);
	      S[A].Oked := true; Dec(Less);
	    end;
            Exit;
          end;
      if (U[K].K < U[K].C) then begin
        Inc(U[K].K);
        U[K].List[ U[K].K ] := A;
        S[A].Oked := True;
        Dec(Less);
      end;
    end;

  begin    
    for i:=1 to M do
      U[i].k := 0;

    Less := N;
    While Less > 0 do
      begin

        for i := 1 to N do
	  if Not S[i].Oked then 
            begin
	      Try_Next(i);
	    end;

      end;
      
    for i:=1 to n do
      if S[i].U = -1 then Writeln('not accepted')
                     else Writeln(S[i].List[ S[i].u ]);
  end;

var
  i , j		: Integer;
begin
//  Assign(Input,'In.txt'); Reset(Input);
{  Assign(Output,'Out.txt'); Rewrite(Output); }
  Read(T);
  repeat 
    Read( N , M );
    for i:=1 to N do
      With S[i] do
	begin  
	  Read(Region , Score , K);
	  for j:=1 to K do
	    Read(List[j]);
	  U := 0;
	  Oked := false;
        end;
    for i:=1 to M do
      With U[i] do
        Read(Region , c);
    
    Work;
    
    dec( T );
    if (T <> 0) then Writeln;
  until T = 0;
end.
