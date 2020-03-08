{$MODE FPC}
{$M 0,1025}
{$R-,S-,Q-,I-}
Program zju_1721;
type
  point = record
    x , y	: double;
  end;
var
  N		: Integer;
  f		: Array[0..19 , 1..4] of Double;
  List		: Array[0..19 , 1..4] of point;
  x		: Double;

  procedure Init;
    var
      i , j	: Integer;
    begin     
      for i:=1 to N do
        begin
	  Read(x);
	  for j:=1 to 4 do
	    begin
	      List[i , j].x := x; Read(List[i , j].y);
  	    end;
	end; 
      for i:=1 to 4 do
        begin
	  List[0 , i].x := 0; List[0 , i].y := 5;
	end;

      for i:=1 to 4 do
        begin
	  List[n+1 , i].x := 10; List[n+1 , i].y := 5;
	end;
    end;

  
  function dist(var a , b	: point)	: Double;
    begin
      dist := sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
    end;
  
  function Multiply(var p1 , p2 , p0	: point)	: Double;
    begin 
      Multiply := (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
    end;
  
  function Min(a , b		: double)	: Double;
    begin
      if a < b then min := a  else min := b;
    end;

  function Max(a , b		: double)	: Double;
    begin
      if a > b then max := a  else max := b;
    end;

  function Cross(var p1 , p2 , q1 , q2	: point)	: Boolean;
    begin
      Cross := (Min(p1.x , p2.x) <= Max(q1.x , q2.x)) and (Min(q1.x , q2.x) <= Max(p1.x , p2.x)) and
               (Min(p1.y , p2.y) <= Max(q1.y , q2.y)) and (Min(q1.y , q2.y) <= Max(p1.y , p2.y)) and
	       (Multiply(q1 , p2 , p1) * Multiply(q2 , p2 , p1) <= 0) and
	       (Multiply(p1 , q2 , q1) * Multiply(p2 , q2 , q1) <= 0)      
    end;
   

  procedure Work; 
    var
      i , j , p , q	: Integer;
      flag		: Boolean;
      k			: Integer;
    begin
      fillchar(f , sizeof(f) , 0);
      for i:=1 to n + 1 do
        for j:=1 to 4 do
	  begin
	    f[i , j] := 1e10;
	    for p:=0 to i - 1 do
	      for q:= 1 to 4 do
	        if (dist(List[i , j] , List[p , q]) + f[p , q] < f[i , j]) then
	        begin
		  flag := true;
		  for k:=p + 1 to i - 1 do
		    begin
		      if Cross(List[p , q] , List[i , j] , List[k , 1] , List[k , 2])
		      or Cross(List[p , q] , List[i , j] , List[k , 3] , List[k , 4]) then continue;

		      flag := false; break;
		    end;
		  if flag then f[i , j] := dist(List[i , j] , List[p , q]) + f[p , q];
	        end;
	  end;
	  
      Writeln(f[n + 1 , 1] : 0 : 2);
    end;

begin
  While true do
    begin 
      Read(N);
      if N < 0 then Break;
      Init;
      Work;
    end;
end.
