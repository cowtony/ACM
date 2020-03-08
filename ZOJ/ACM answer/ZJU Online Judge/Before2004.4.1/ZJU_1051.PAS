Program zju_1051;
const 
  con_str : string = '.!X#';
var
  N, CaseNo	: Integer;
  K		: Integer;
  D		: Array[0..15] of Integer;
  G0,G1		: Array[0..21 , 0..21] of Integer;
  i,j		: Integer;
procedure Run_Day;
  var 
    i , j , k	: Integer;
  begin
    for i:=1 to 20 do
      for j:=1 to 20 do
        begin
	  k := G0[i,j] + G0[i-1,j] + G0[i+1,j] + G0[i,j+1] + G0[i,j-1];
	  G1[i,j] := G0[i,j] + D[k];
	  if G1[i,j] > 3 then G1[i,j] := 3;
	  if G1[i,j] < 0 then G1[i,j] := 0;
	end; 

    G0 :=  G1;    
    
  end;
begin
  fillchar(G0,sizeof(G0),0);
  fillchar(G1,sizeof(G1),0);

  Read(n);
  for CaseNo:=1 to N do
    begin
      Read(k);
      for i:=0 to 15 do
        Read(D[i]);
      for i:=1 to 20 do
        for j:=1 to 20 do
	  Read(G0[i,j]);

      for i:=1 to k do
        Run_Day;
      
      for i:=1 to 20 do
        begin
          for j:=1 to 20 do
	    Write(con_str[ G0[i , j] + 1]);
	  Writeln;
	end;
      
      if ( CaseNo < n ) then Writeln;
    end;
end.
