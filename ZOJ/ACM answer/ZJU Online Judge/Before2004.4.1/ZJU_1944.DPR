//{$DEFINE DEBUG}
program Uva_536;
{$IFDEF DEBUG}
{$APPTYPE CONSOLE}
{$ENDIF}
var s : string;
    p : integer;
function find(x1 , x2 :string): string;
 var ch: char;
     l : integer;
     len : integer;
 begin
  len := length(x1);
  if (len < 2) then
  begin
   find:= x1;
   exit;
  end;
  ch := x1[1];
  l := pos(ch,x2);
  find:=find(copy(x1,2,l-1),copy(x2,1,l-1)) + find(copy(x1,l+1,len-l),copy(x2,l+1,len-l)) + ch;
 end;
begin
{$IFDEF DEBUG}
  assign(input,'in.txt');
  reset(input);
  assign(output,'out.txt');
  rewrite(output);
{$ENDIF}

  while not eof do
   begin
    readln(s); p:=pos(' ',s);
    writeln(find(copy(s,1,p-1),copy(s,p+1,255)));
   end;

{$IFDEF DEBUG}
  close(input);
  close(output);
{$ENDIF}
end.
