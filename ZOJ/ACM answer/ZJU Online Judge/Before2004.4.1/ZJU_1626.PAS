Program Zju_1626;

var
  N,K		: Integer;
  Map		: Array[1..100,1..100] of Char;
  App		: Array['A'..'Z'] of Boolean;

{ Var for Match }
  G		: Array[1..100,1..100] of Boolean;
  cx,cy		: Array[1..100] of Integer;
  visited	: Array[1..100] of Boolean;

procedure Init;
  var
    i,j		: Integer;
  begin
    Readln(N,K);
    Fillchar(App,sizeof(App),0);
    for i:=1 to N do
      begin
        for j:=1 to N do
	  begin
            Read(map[i,j]);
	    App[ map[i,j] ] := True;
	  end;
        Readln;
      end;
  end;

function path(v : integer) : boolean;
 var u : integer;
 begin
  path := true;

  for u:=1 to n do
  if (not visited[u]) and (G[v,u]) then
   begin
    visited[u] := true;
    if (cy[u] = 0) or (path(cy[u])) then
     begin
      cx[v] := u;
      cy[u] := v;
      exit;
     end;
   end;

  path := false;
 end;

procedure Work;
  var
    ch		: Char;
    i,j		: Integer;
    Found	: Boolean;
    ret		: Integer;
  begin
    Found := false;
    for ch := 'A' to 'Z' do
      if App[ch] then
       begin
         { ¹¹Í¼ }
         fillchar(G,sizeof(G),0);
	 fillchar(cx,sizeof(cx),0);
	 fillchar(cy,sizeof(cy),0);
	 ret := 0;
         for i:=1 to n do
	   for j:=1 to n do
	     if map[i,j] = ch then
	        begin
		  G[i,j] := true;
		  if (cx[i] = 0) and (cy[j] = 0) then begin cx[i] := j; cy[j] := i; inc(ret); end;
		end;
	 for i:=1 to n do
	   if cx[i] = 0 then
             begin
               fillchar(visited,sizeof(visited),0);
               if path(i) then inc(ret);
             end;
         if ret > k then begin
	   Found := True; Write(ch);
	 end;
       end;


    if (not Found) then Writeln('Poor WishingTree!') else Writeln;
  end;

var
  T,Case_No	: Integer;

begin
  Read(T);
  for Case_NO := 1 to T do
    begin
      Init;
      Work;
      Writeln;
    end;
end.
