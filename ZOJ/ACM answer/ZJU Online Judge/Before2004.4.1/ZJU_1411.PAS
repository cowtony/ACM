{$A-,B-,D-,E-,F-,G-,I-,L-,N-,O-,P-,Q-,R-,S,T-,V-,X-,Y-}
{$M 16384,0,655360}
Program zju_1411;
type Integer = Longint;
const
  MAXLEN = 30;
var
  T		: Integer;
  Len , N	: Integer;
  List		: Array[1..10] of Integer;
  
  G		: Array[1..MAXLEN] of Integer;

function Check( i , j , p : Integer) : Boolean;   
  var
    k , ret	: Integer;
  begin    
    ret := (1 shl p - 1) shl (len - j - p + 1);
    Check := false;
    if (i + p - 1 > LEN) then Exit;
    if (j + p - 1 > LEN) then Exit;

    for k := i  to i + p - 1  do
      if (G[k] AND ret > 0) then Exit;
    Check := true;
  end;

procedure Fill( i , j , p : Integer);
  var
    k , ret	: Integer;
  begin
    ret := (1 shl p - 1) shl (len - j - p + 1);
    for k := i  to i + p - 1  do
      G[k] := G[k] Or ret;
  end;

procedure Return( i , j , p : Integer);
  var
    k , ret	: Integer;
  begin
    ret := NOT ( (1 shl p - 1) shl (len - j - p + 1) );
    for k := i  to i + p - 1  do
      G[k] := G[k] And ret;
  end;
 
procedure Find_Blank( var  i , j : Integer);
  begin

    While (i <= Len) and ( G[i] AND (1 shl (Len - j)) > 0) do 
      begin
        Inc(j);
	if j > Len then begin Inc(i); j := 1; end;
      end;
  end;

function Search( i,j	: Integer): Boolean;
  var
    p			: Integer;
  begin
    search := True;    
    Find_Blank( i , j );
    if i > Len then Exit;

    for p := 10 downto 1 do
      if (List[p] > 0) and (Check( i , j , p)) then
        begin
	  Dec(List[p]);                
	  Fill( i , j , p);
          if Search( i , j ) then Exit;
	  Return( i , j , p);
	  Inc(List[p]);	 
	end;	
    search := false;
  end;
 
var
  i , k		: Integer;

begin
  Assign(input,'in.txt'); Reset(input);
  Read(T);
  repeat
    Read(Len , N);
    fillchar(List, sizeof(List) ,0);
    for i:=1 to N do
      begin
        Read( k );
	Inc(List[k]);
      end;

    fillchar( G , sizeof(G) ,0);
    if Search( 1 , 1 ) then Writeln('KHOOOOB!') else Writeln('HUTUTU!');
     
    dec(T);
  until T = 0;
end.
