{$n+}
Program zju_1032;

type
  point = record
    x,y		: Double;
  end;
var
  CaseNo,T		: Integer;
  N			: Integer;
  List			: Array[0..100] of point;
  I,E			: Integer;
  Area			: double;

function gcd(a,b	: Integer)	: Integer;
  begin
    if b = 0 then gcd := a
    else gcd := gcd (b , a mod b);
  end;

var 
  p			: Integer;
  dieta_x,dieta_y	: Integer;  
begin
  Read(CaseNo);
  for T :=1 to CaseNo do
    begin
      List[0].x := 0 ; List[0].y := 0;
      Read(N); E := N;
      for p:=1 to N do
        begin
	  Read(dieta_x,dieta_y );
	  E := E + gcd(abs(dieta_x) , abs(dieta_y)) - 1;
	  List[p].x := List[p - 1].x + dieta_x;
  	  List[p].y := List[p - 1].y + dieta_y;
	end;

      Area := 0;
      for p:=0 to N-1 do
	  Area := Area + List[p].x * List[p+1].y - List[p].y * List[p+1].x;	  

      Area := abs(Area) / 2.0;
      I := trunc( ((Area + 1.0) * 2.0 - E) / 2.0 );
      
      Writeln('Scenario #', T , ':');
      Writeln(I , ' ' , E , ' ' , Area : 0 : 1);
      Writeln;
    end;
end.
