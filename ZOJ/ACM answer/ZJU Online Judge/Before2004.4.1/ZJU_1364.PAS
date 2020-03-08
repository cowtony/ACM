{$R-} //????
Program zju_1364;
const MaxLen = 100; 
var 
  n,m,k		: integer; 
  G		: array[1..MaxLen,1..MaxLen] of Boolean; 
  visited	: array[1..MaxLen] of Boolean;  
  cx,cy		: array[1..MaxLen] of integer; 

function path(v : integer) : boolean; 
  var u		: integer; 
  begin 
   path := true; 

   for u:=1 to m do 
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

function match	: integer; 
  var
    ret,i,j	: integer; 
  begin 
    fillchar(cx,sizeof(cx),0); 
    fillchar(cy,sizeof(cy),0); 
    ret := 0; {
    for i:=1 to n do 
      for j:=1 to m do 
        if (G[i,j]) and (cy[j] = 0) then begin 
          cx[i] := j; cy[j] := i; inc(ret); break; 
        end; }

    for i:=1 to n do 
      if cx[i] = 0 then 
        begin 
          fillchar(visited,sizeof(visited),0); 
          if path(i) then inc(ret); 
        end; 
    match := ret; 
end; 

var 
  i,p,a,b	: Integer;

begin 
  while true do
    begin
      Read(n); if n = 0 then break;
      read(m,k); 
      fillchar(G,sizeof(G),0); 
      for i:=1 to k do 
        begin 
           read(p,a,b); G[a,b] := true; 
        end;     
     writeln(match); 
   end;
end.
