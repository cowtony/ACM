program Zju_1752;
type  
  rect = Record
    x1,y1,x2,y2	: Integer;
    color	: Integer;
  End;

var
  N		: Integer;
  List		: Array[1..4000] of Rect; 

  i,j,k,Color	: Integer;
  cnt,old_cnt	: Integer;
  ret		: Integer;
  CaseNo	: Integer;

procedure Swap(var a,b	: Integer);
  var
    tmp : 	Integer;
  begin
    tmp := a; a := b; b := tmp;   
  end;

Function CutRect(var A,B  : Rect)	: Integer;
{   用矩形B去切割矩形A  }       
  begin
    {不相交}
    if (A.x1 > B.x2) or (B.x1 >= A.x2) or (A.y1 > B.y2) or (B.y1 >= A.y2) then begin CutRect := -1; Exit; end;

    {B完全覆盖A}
    if (B.x1 <= A.x1) And (B.y1 <= A.y1) And (B.x2 >= A.x2) And (B.y2 >= A.y2) then begin CutRect := 0; Exit; end;

    if B.x1 > A.x1 then begin
      Inc(cnt); List[cnt] := A;
      List[cnt].x2 := B.x1;
      A.x1 := B.x1;
    end;
    if B.x2 < A.x2 then begin 
      Inc(cnt); List[cnt] := A;
      List[cnt].x1 := B.x2;
      A.x2 := B.x2;
    end;
    if B.y1 > A.y1 then begin
      Inc(cnt); List[cnt] := A;
      List[cnt].y2 := B.y1;
      A.y1 := B.y1;
    end;
    if B.y2 < A.y2 then begin
      Inc(cnt); List[cnt] := A;
      List[cnt].y1 := B.y2;
      A.y2 := B.y2;
    end;

    CutRect := 1;
  end;

procedure Print;
  var
    ret		: Integer;
    i		: Integer;  
  begin    
    ret := 0;
    for i:=1 to Cnt do
        if (List[i].color = Color) then inc(ret , (List[i].x1 - List[i].x2) * (List[i].y1 - List[i].y2));
    Inc(CaseNo);
    Writeln('The area of color ' , Color , ' in dataset ', CaseNO ,' is: ' , ret);
  end;

begin
  CaseNo := 0;
  While true do
    begin
      Readln(N , Color);
      if N = 0 then Break;
      cnt := 0;

      for i:=1 to N do
        begin
          Inc(cnt);
          Read(List[cnt].color,List[cnt].x1,List[cnt].y1,List[cnt].x2,List[cnt].y2);
          if List[cnt].x1 > List[cnt].x2 then Swap(List[cnt].x1 , List[cnt].x2);
          if List[cnt].y1 > List[cnt].y2 then Swap(List[cnt].y1 , List[cnt].y2);

  	  old_cnt := cnt;
          j := 1;
          while j < old_cnt do
            begin
              ret := CutRect(List[j] , List[old_cnt]);
              if ret = 0 then begin
                Move(List[j+1],List[j],sizeof(rect) * (cnt - j));
                dec(cnt); dec(old_cnt); dec(j);
              end
              else if ret = 1 then begin
                List[j] := List[cnt]; Dec(cnt);
              end;                 
              Inc(j);
            end;
        end; 
      Print;   
   end;
end.    