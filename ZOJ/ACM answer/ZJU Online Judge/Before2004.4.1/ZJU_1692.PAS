Program zju_1692;
var
  N , C			: Integer;
  Valid			: Array[0..11 , 0..11] of Boolean;
  G , F			: Array[1..10 , 1..10] of Integer;
  ret , Best		: Integer;
  i , j			: Integer;

function search(i , j , k	: Integer) : Integer;  
  var
    rlt			: Integer;
  begin
    if f[i , j] = 0 then search := -1000
    else if f[i , j] <> k then search := 0
    else begin
      f[i , j] := -1;
      rlt := 1;
      if Valid[i - 1 , j] then rlt := rlt + search(i - 1 , j , k);
      if Valid[i - 1 , j - 1] then rlt := rlt + search(i - 1 , j - 1 , k);
      if Valid[i , j - 1] then rlt := rlt + search(i , j - 1 , k);
      if Valid[i , j + 1] then rlt := rlt + search(i , j + 1 , k);
      if Valid[i + 1 , j] then rlt := rlt + search(i + 1 , j , k);
      if Valid[i + 1 , j + 1] then rlt := rlt + search(i + 1 , j + 1 , k);
      search := rlt;
    end;    
  end;

function Calc : Integer;
  var
    i , j , k		: Integer;
    ret	, tmp		: Integer;
  begin
    ret := 0;
    for i := 1 to n do
      for j := 1 to i do
        if f[i , j] > 0 then begin
           k := f[i , j];
	   tmp := search( i , j , k );
	   if tmp < -100 then continue;
	   if k = C then ret := ret - tmp
	   else ret := ret + tmp;
	end; 
    Calc := ret;
  end;

begin
  while true do
    begin
      Read(N , C);
      if N = 0 then break;
      fillchar(Valid , sizeof(Valid) , 0);
      for i:=1 to N do 
        for j:=1 to i do
	  begin
	    Read(G[ i , j ]);
	    Valid[i , j] := true;
	  end;
      Best := -1000;
      for i:=1 to N do
        for j:=1 to i do
	  if G[i , j] = 0 then begin
	    f := G;
	    f[i , j] := C;
	    ret := Calc;
	    if ret > Best then Best := ret;
	  end;
      Writeln(Best);
    end;
end.
