program Ural_1060;
type 
  Integer = Longint;
  State   = Array[1..4 , 1..4] of Char;
  Qtype   = record
    L		: Integer;
    stat	: State;
  end;

const
  LEN		= (1 shl 16) - 1;

var
  G		: State;
  Q		: Array[0..1 shl 16] of Qtype;  
  App		: Array[0..1 shl 16] of Boolean;

procedure Init; 
  var
    i , j	: Integer;
  begin
    for i:=1 to 4 do
      begin
        for j:=1 to 4 do
	  Read(G[i , j]);
	Readln;
      end;
  end;

function Hash	: Integer;
  var
    i , j	: Integer;
    ret		: Integer;
  begin    
    ret := 0;
    for i:=1 to 4 do
      for j:=1 to 4 do 
        begin
	  ret := (ret shl 1) + Ord(G[i , j] = 'b');
	end; 
    Hash := ret;   
  end;

procedure Doit(x , y	: Integer);
  begin
    if (x >= 1) and (x <= 4) and (y >= 1) and (y <= 4) then 
       if G[x , y] = 'b' then G[x , y] := 'w'
       else G[x , y] := 'b';
  end;  

procedure Flip( i , j	: Integer );
  begin
    Doit(i , j);
    Doit(i - 1 , j);
    Doit(i + 1 , j);
    Doit(i , j - 1);
    Doit(i , j + 1);
  end;

procedure Work;
  var
    head , tail : Integer;
    ret		: Integer;
    i , j	: Integer;
  begin   
    fillchar(App , sizeof(App) , 0); App[Hash] := true;
    head := 0; tail := 0;
    Q[0].stat := G; Q[0].L := 0;

    while head <= tail do
      begin
        for i := 1 to 4 do
	  for j := 1 to 4 do
	    begin
	      G := Q[head].stat;
	      Flip(i , j);

	      ret := Hash;
	      if (App[ret]) then continue;

	      if (ret = 0) or (ret = Len) then begin Writeln(Q[head].L + 1); exit; end;

	      App[ret] := true;
	      Inc(tail); Q[tail].stat := G; Q[tail].L := Q[head].L + 1;
	    end;        
	Inc(head);
      end;
    Writeln('Impossible');
  end;

var
  T , TC	: Integer;
begin
  Readln(T);
  for TC := 1 to T do
    begin
      Readln;
      Init;
      if (Hash = 0) or (Hash = LEN) then Writeln(0) else Work;
      if TC < T then Writeln;
    end;
end.
