Program zju_1085;
const
  MAXN = 10;
var
  CaseNo,T		: Integer;
  N,ET			: Integer;
  G			: Array[0..MAXN , 0..MAXN] of Integer;

  a,b			: Integer;
  Q,Q2			: Array[0..MAXN] of Integer;
  Got,Visit		: Array[0..MAXN] of Boolean;

function Check( u	: Integer) : Boolean;
  var
    head , tail		: Integer;
    i			: Integer;
  begin
    Check := false;
    head := 0; tail := 0;
    Q2[0] := ET; 
    fillchar(Visit , sizeof (Visit), 0);
    Visit[ET] := true; Visit[u] := true;
    While head <= tail do
      begin
        for i:=1 to G[Q2[head], 0] do 
	  if (not Visit[ G[Q2[head] , i] ]) then
             begin
	       if G[Q2[head] , i] = 0 then Exit;
	       Inc(tail); Q2[tail] := G[Q2[head], i];
	       Visit[ G[Q2[head] , i] ] := true;
	     end;
	Inc(head);
      end;        
    Check := true;
  end;

procedure Work;
  var
    head , tail		: Integer;
    i			: Integer;
  begin
    head := 0; tail := 0;
    Q[0] := ET; 
    fillchar(Got , sizeof (Got), 0);
    Got[ET] := true;
    While head <= tail do
      begin
        for i:=1 to G[Q[head], 0] do 
	  if not Got[ G[Q[head] , i] ] then
             begin
	       if Check(G[ Q[head] , i ]) then begin Writeln('Put guards in room ',G[Q[head], i],'.'); exit; end;
	       Inc(tail); Q[tail] := G[Q[head], i];
	       Got[ G[Q[head] , i] ] := true;
	     end;
	inc(Head);
      end;        
  end;

begin
  Readln(CaseNo);
  for T:=1 to CaseNo do
    begin
      Readln(N,ET);
      fillchar(G, sizeof(G), 0);
      While (not Eoln) and (not Eof) do
        begin
	  Readln( a, b);
	  inc(G[b,0]);
	  G[ b , G[b,0] ] := a;
	end;

      Work;

      if T < CaseNo then Writeln;
    end;

end.
