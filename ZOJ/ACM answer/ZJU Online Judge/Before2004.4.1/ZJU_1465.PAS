{$R-,S-,Q-,P-} // ÎªÉ¶»áRunErrorÄù?
Program zju_1465;
type 
  point = record
    x , y	: double;
  end;

var
  N , L			: Integer;
  Len			: double;
  T , CaseNO		: Integer;
  List			: Array[1..1500] of point;
  Result		: Array[1..1500] of Integer;

procedure swap(var a , b	: point);
  var
    tmp			: point;
  begin
    tmp := a; a := b; b := tmp;
  end;

function dist(var a , b		: point) : double;
  begin
    dist := sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
  end;

function Multiply(var p1 , p2 , p0	: Point)	: double;
  begin
    Multiply := (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
  end;

procedure Work;
  var
    i , j , k		: Integer;    
    ret			: Double;
    top			: Integer;
  begin
    k := 1;
    for i:=2 to n do
      if (List[i].x < List[k].x) then k := i
      else if (List[i].x = List[k].x) and (List[i].y < List[k].y) then k := i;
    Swap(List[1] , List[k]);

    for i:=2 to n-1 do
       begin
         k := i;
         for j:=i + 1 to n do
	   begin
	     ret := Multiply( List[j] , List[k] , List[1] );
	     if (ret > 0) or ((ret = 0) and (dist(List[1] , List[j]) < dist(List[1] , List[k]))) then k := j;
	   end;
	 swap(List[i] , List[k]);
       end;   

    Result[1] := 1; Result[2] := 2; Result[3] := 3; top := 3;
    for i:=4 to N do
      begin
        While Multiply(List[i] , List[Result[top]] , List[Result[top-1]]) >= 0 do
	  Dec(top);
	Inc(top);
	Result[top] := i;
      end;

    Len := 3.1415926 * 2 * L + dist(List[Result[top]] , List[Result[1]]);
    for i:=1 to top - 1 do
      Len := Len + dist(List[Result[i]] , List[Result[i + 1]]);
    Writeln(Len : 0 : 0);
  end;

var
  i		: Integer;

begin
  Read(CaseNO);

  for T :=1 to CaseNO do
    begin
      Read(N , L);
      
      for i:=1 to N do
        Read(List[i].x ,  List[i].y);

      Work;
      
      if T < CaseNO then Writeln;
    end;
end.
