{$A-,B-,D-,E-,F-,G-,I-,L-,N-,O-,P-,Q-,R-,S-,T-,V-,X-,Y-}
{$M 16384,0,655360}
Program Zju_1227;
type 
  integer = Longint;
const
  MAXN = 40;

var
  n		: Integer; 
  mark		: Array[1..MAXN + 1 , 1..MAXN + 1 , 1..MAXN + 1 , 1..MAXN + 1] of Boolean;
  List		: Array[1..4 , 1..MAXN] of Integer;
  Best		: Integer;

procedure search(p1 , p2 , p3 , p4 , stat , c , got : Integer);
  begin
    if mark[p1 , p2 , p3 , p4] then exit;
    mark[p1 , p2 , p3 , p4] := true;
    if best < got then  best := got;
    if c = 5 then exit;
     
    if p1 <= n then 
    if (stat and ( 1 shl List[1 , p1] ) > 0) then begin
      search(p1 + 1 , p2 , p3 , p4 , stat xor ( 1 shl List[1 , p1] ) , c - 1 , got + 1);
    end
    else search(p1 + 1 , p2 , p3 , p4 , stat xor ( 1 shl List[1 , p1] ) , c + 1 , got);
    
    if p2 <= n then 
    if (stat and ( 1 shl List[2 , p2] ) > 0) then begin
      search(p1 , p2 + 1 , p3 , p4 , stat xor ( 1 shl List[2 , p2] ) , c - 1 , got + 1);
    end
    else search(p1 , p2 + 1 , p3 , p4 , stat xor ( 1 shl List[2 , p2] ) , c + 1 , got);
    
    if p3 <= n then 
    if (stat and ( 1 shl List[3 , p3] ) > 0) then begin
      search(p1 , p2 , p3 + 1 , p4 , stat xor ( 1 shl List[3 , p3] ) , c - 1 , got + 1);
    end
    else search(p1 , p2 , p3 + 1 , p4 , stat xor ( 1 shl List[3 , p3] ) , c + 1 , got);
    
    if p4 <= n then 
    if (stat and ( 1 shl List[4 , p4] ) > 0) then begin
      search(p1 , p2 , p3 , p4 + 1 , stat xor ( 1 shl List[4 , p4] ) , c - 1 , got + 1);
    end
    else search(p1 , p2 , p3 , p4 + 1 , stat xor ( 1 shl List[4 , p4] ) , c + 1 , got);
   
  end;

procedure Work;
  begin
    fillchar(mark , sizeof(mark) ,0);
    Best := 0;
    search(1 , 1 , 1 , 1 , 0 , 0 , 0);
    Writeln(Best);    
  end;

var
  i , j		: Integer;

begin
 // Assign(input , 'in.txt'); Reset(input);
  While true do
    begin
      Read(n);
      if n = 0 then break;
      for i:=1 to n do
        for j:=1 to 4 do
	  begin
            read(List[j , i]);
	    dec(List[j , i]);
	  end;
      Work;
    end;  
end.
