{$n+}
Program zju_1081;
type
  point = record
    x , y	: Double;
  end;
var
  N , M		: Integer;
  List		: Array[0..100] of point;
  
  p,p1		: point;

function Multiply(p1 , p2 , p0 : point) : Double;
  begin
    Multiply := (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
  end;

function Max( a , b	: Double)	: Double;
  begin
    if a > b then max := a else max := b;
  end;

function Min( a , b	: Double)	: Double;
  begin
    if a < b then min := a else min := b;
  end;

function OnSegment( p , p1,p2	: point)	: Boolean;
  begin 
    OnSegment := (min(p1.x , p2.x) <= p.x) and (p.x <= max(p1.x , p2.x)) and
                 (min(p1.y , p2.y) <= p.y) and (p.y <= max(p1.y , p2.y)) and
		 (Multiply(p , p2 , p1) = 0);
  end;

function Segment_Cross(A1 , A2 , B1 , B2 : Point) : Boolean;
  begin
    Segment_Cross := (min(A1.x , A2.x) < max(B1.x , B2.x)) AND (min(B1.x , B2.x) < max(A1.x , A2.x)) AND
                     (min(A1.y , A2.y) < max(B1.y , B2.y)) AND (min(B1.y , B2.y) < max(A1.y , A2.y)) AND
		     (Multiply(B1,A2,A1) * Multiply(B2,A2,A1) < 0) AND
		     (Multiply(A1,B2,B1) * Multiply(A2,B2,B1) < 0);
  end;

function Check	: Boolean;
  var 
    Count	: Integer;
    i		: Integer;
  begin
    Count := 0;
    p1 := p; p1.x := -10000000.0;

    Check := true;
    for i:=0 to n-1 do
      begin
        if OnSegment( p , List[i] , List[i+1] ) then Exit;
	if (List[i].y = List[i+1].y) then continue; { Ë®Æ½±ß ²»¿¼ÂÇ }
        if OnSegment( List[i] , p , p1 ) then begin
	  if List[i].y > List[i + 1].y then Inc(Count);
	end
	else if OnSegment( List[i + 1] , p , p1 ) then begin
  	  if List[i + 1].y > List[i].y then Inc(Count);
	end
	else if (Segment_Cross(p , p1 , List[i] , List[i+1])) then Inc(Count);	  
      end;
    Check := odd ( Count );
  end;

var
  i , CaseNo	: Integer;
begin
  CaseNo := 0;
  while true do
    begin 
      Read(N);
      if N = 0 then break;
      Read(M);
      for i:= 0 to N-1 do
        Read(List[i].x , List[i].y);
      List[n] := List[0];

      if CaseNo > 0 then Writeln;
      Inc(CaseNo);
      Writeln('Problem ', CaseNo ,':');
      for i:=1 to M do
        begin
	  Read(p.x , p.y);
	  if Check then Writeln('Within') else Writeln('Outside');
	end;       
        
    end; 
end.


