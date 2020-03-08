program zju_1197;
type
  integer = Longint;
  rec = record
    x1 , x2 , y1 , y2   : Integer;
  end;
  point = record
    x , y               : Integer;
  end;
var
  N             : Integer;
  CaseNo    : Integer;
  List          : Array[0..26] of Rec;
  S             : Array[1..26] of point;
  D1 , D2 , p   : Array[0..26] of Integer;
  G             : Array[0..26 , 0..26] of Boolean;

function PointInRec(var R     : Rec ; var p       : Point) : Boolean;
  begin
    PointInRec := (R.x1 <= p.x) and (p.x <= R.x2)
               and(R.y1 <= p.y) and (p.y <= R.y2);
  end;
procedure Link(i , j    : Integer);
  var
    k           : Integer;
  begin
    D1[i] := 0; D2[j] := 0;
    for k:=1 to n do
      if G[i , k] then begin G[i,k] := false; dec(D2[k]); end;
    for k:=0 to n-1 do
      if G[k , j] then begin G[k,j] := false; Dec(D1[k]); end;
  end;
procedure Work;
  var
    i , j       : Integer;
    modify      : Boolean;
  begin
    fillchar(d1 , sizeof(d1) ,0);
    fillchar(d2 , sizeof(d2) ,0);
    fillchar(G , sizeof(G), 0);
    for i:=0 to n-1 do
      for j:=1 to n do
        if PointInRec(List[i] , S[j]) then begin
          G[i , j] := true;
          Inc(D1[i]); Inc(D2[j]);
        end;
    fillchar(p , sizeof(p) , 0);
    While true do
      begin
        modify := false;
        for i:=0 to N-1 do
          if D1[i] = 1 then begin
            for j:=1 to n do
              if G[i , j] then break;
            p[i] := j; modify := true;
            Link(i , j);
          end;

        for j :=1 to N do
          if D2[j] = 1 then begin
            for i:=0 to N-1 do
              if G[i , j] then break;
            p[i] := j; modify := true;
            Link(i , j);
          end;
        if not modify then break;
      end;
    modify := false;
    for i:=0 to n do
      if p[i] > 0 then begin
        if modify then write(' ') else modify := true;
        write('(' , chr(ord('A') + i) , ',' , p[i] , ')');
      end;
    if not modify then Writeln('none') else Writeln;
  end;

var
  i             : Integer;
begin
  CaseNo := 0;
  While true do
    begin
      Read(N);  if N = 0 then Break;
      for i:=0 to N-1 do
         Read(List[i].x1 , List[i].x2 , List[i].y1 , List[i].y2);
      for i:=1 to N do
         Read(S[i].x , S[i].y);

      Inc(CaseNo); Writeln('Heap ', CaseNo);
      Work;
      Writeln;
    end;  
end. 
