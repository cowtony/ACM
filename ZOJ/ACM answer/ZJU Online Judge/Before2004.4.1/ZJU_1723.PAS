Program zju_1723;
const
  fx 			: string = 'ABCDEFGH';
  fy			: string = '12345678';
type
  MoveType = string[6];
var
  G			: Array[1..8] of string;
  i 			: Integer;
  op			: char;
  first			: Boolean;
  count			: Integer;
  List			: Array[1..8*8*8] of MoveType;
  
function Valid(x , y	: Integer)	: Boolean;
  begin
    Valid := (x >= 1) and (x <= 8) and (y >= 1) and (y <= 8);
  end;

procedure Reco(x1 , y1 , x2 , y2	: Integer);
  begin
    Inc(Count);
    List[Count] := fx[x1] + fy[y1] + '-' + fx[x2] + fy[y2];
  end;

var
  H , W , d1 , d2	: Array[-16..16] of Integer;

function check(x , y , d_x , d_y , k	: Integer)	: Boolean;
  begin
    check := false;
    while k > 0 do
      begin
        x := x + d_x;
	y := y + d_y;
	if (G[x , y] <> op) and (G[x , y] <> '.') then Exit;
        dec(k);
      end;
    check := true;
  end;

procedure Work;
  var
    i , j , k	: Integer;
  begin
    fillchar(H , sizeof(H) , 0);
    fillchar(W , sizeof(W) , 0);
    fillchar(d1 , sizeof(d1) , 0);
    fillchar(d2 , sizeof(d2) , 0);

    for i:=1 to 8 do
      for j:=1 to 8 do
        if G[i , j] <> '.' then begin
	  Inc(H[i]); Inc(W[j]); Inc(d1[i - j]); Inc(d2[i + j]);
	end;
    
    for i:=1 to 8 do
      for j:=1 to 8 do
        if G[i , j] = op then 
	  begin
	    { 左上  和  右下 }
	    k := d1[i - j];
	    if Valid(i - k , j - k) and Check(i , j , -1 , -1 , k-1) and (G[i-k , j+k] <> op) then Reco(i , j , i-k , j-k);
	    if Valid(i + k , j + k) and Check(i , j , +1 , +1 , k-1) and (G[i+k , j-k] <> op) then Reco(i , j , i+k , j+k);

	    { 左下  和  右上 }
	    k := d2[i + j];
	    if Valid(i + k , j - k) and Check(i , j , +1 , -1 , k-1) and (G[i+k , j-k] <> op) then Reco(i , j , i+k , j-k);
	    if Valid(i - k , j + k) and Check(i , j , -1 , +1 , k-1) and (G[i-k , j+k] <> op) then Reco(i , j , i-k , j+k);

	    { 正上  和  正下 }
	    k := W[j];
	    if Valid(i - k , j) and Check(i , j , -1 , 0 , k-1) and (G[i-k , j] <> op) then Reco(i , j , i-k , j);
	    if Valid(i + k , j) and Check(i , j , +1 , 0 , k-1) and (G[i+k , j] <> op) then Reco(i , j , i+k , j);

	    { 正左  和  正右 }
	    k := H[i];
	    if Valid(i , j - k) and Check(i , j , 0 , -1 , k-1) and (G[i , j - k] <> op) then Reco(i , j , i , j-k);
   	    if Valid(i , j + k) and Check(i , j , 0 , +1 , k-1) and (G[i , j + k] <> op) then Reco(i , j , i , j+k);	    
	  end;
  end;

procedure sort(p , r	: Integer);
  var
    i , j	: Integer;
    x , tmp	: MoveType;
  begin
    if p >= r then Exit;

    i := p - 1; j := r + 1; x := List[(p + r) div 2];
    while true do
      begin
        repeat dec(j); until List[j] <= x;
	repeat inc(i); until List[i] >= x;
	if (i >= j) then break;
	tmp := List[i]; List[i] := List[j]; List[j] := tmp;
      end;

    Sort(p , j);
    Sort(j + 1 , r);
  end;

begin
  { Assign(input , 'in.txt'); Reset(input); }
  first := true;
  While not eof do
    begin
      if first then first := false else Writeln;
      for i:=1 to 8 do Readln(G[i]);
      Readln(op);
      Count := 0;
      Work;
      if (Count = 0) then Writeln('No moves are possible')
      else sort(1 , Count);
      for i:=1 to Count do
        Writeln(List[i]);
    end;
end.
