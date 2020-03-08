//{$define DEBUG}
program F;
{$ifdef DEBUG}
{$APPTYPE CONSOLE}
{$endif}
var
 t : integer;
 r,c,n,run : integer;
 i,j : integer;
 G,te : array[1..100,1..100] of char;
 ch : char;
function attack (x,y : integer; var ch : char) : boolean;
 var killch  : char;
 begin
//Rocks, Scissors, or Papers.
  case G[x,y] of
  'R' : killch := 'P';
  'S' : killch := 'R';
  'P' : killch := 'S';
   end;
  attack := true; ch := killch;
  if(x > 1) and (G[x-1,y] = killch) then exit;
  if(y > 1) and (G[x,y-1] = killch) then exit;
  if(x < r) and (G[x+1,y] = killch) then exit;
  if(y < c) and (G[x,y+1] = killch) then exit;
  attack := false;
 end;
begin
{$ifdef DEBUG}
 assign(input,'in.txt'); reset(input);
 assign(output,'out.txt'); rewrite(output);
{$endif}
 readln(t);
 while(t > 0) do begin
   readln(r,c,n);
   for i:=1 to r do
    begin
     for j:=1 to c do
      read(G[i,j]);
     readln;
    end;
   for run :=1 to n do
    begin
      for i:= 1 to r do
       for j:= 1 to c do
        begin
         if (attack(i,j,ch)) then Te[i,j] := ch else Te[i,j] := G[i,j];
        end;
      G := Te;
    end;
   for i:=1 to r do
    begin
     for j:=1 to c do
      write(G[i,j]);
     writeln;
    end;

   dec(t);
   if t > 0 then writeln;
  end;


{$ifdef DEBUG}
 close(input); close(output);
{$endif}
end.
