program zju_1819;
//{$APPTYPE CONSOLE}
const MaxLen = 50;

type
 BigNum = record
  l : integer;
  n : array [1..MaxLen] of integer;
 end;

var
  N         : Integer;
  f         : Array[1..50 , 1..50] of BigNum;
  tot       : Array[1..50] of BigNum;

procedure Increase(var a : BigNum;var b : BigNum);
 {A := A  +  B}
 var i : integer;
 begin
  if a.l < b.l then a.l := b.l;
  for i:=1 to a.l do
   begin
    a.n[i] := a.n[i] + b.n[i];
    a.n[i+1] := a.n[i+1] + a.n[i] div 10;
    a.n[i] := a.n[i] mod 10;
   end;
  while(a.n[a.l + 1] > 0) do
   begin
    Inc(a.l);
    a.n[a.l + 1] := a.n[a.l] div 10;
    a.n[a.l] := a.n[a.l] mod 10;
   end;
 end;

procedure Multiply_int(var A : BigNum; k : integer);
{ A := A * k | k > 0 }
 var i: integer;
 begin
  A.n[1] := A.n[1] * k;
  for i:=2 to A.l do
   begin
    A.n[i] := A.n[i] * k + A.n[i-1] div 10;
    A.n[i-1] := A.n[i-1] mod 10;
   end;
  While(A.n[A.l] >= 10) do
   begin
    A.n[A.l + 1] := A.n[A.l] div 10;
    A.n[A.l] := A.n[A.l] mod 10;
    inc(A.l);
   end;
 end;

procedure print(var A : BigNum);
 var i : integer;
 begin
  for i:=A.l downto 1 do
   write(A.n[i]);
  writeln;
 end;


var
  i , j       : Integer;
begin
  fillchar(f , sizeof(f) , 0);
  fillchar(tot , sizeof(tot) , 0);
  f[1 , 1].l := 1; f[1 , 1].n[1] := 1;
  tot[1].l := 1; tot[1].n[1] := 1;
  for i:=2 to 50 do
    begin
      f[i , 1].l := 1; f[i , 1].n[1] := 1;
      f[i , i].l := 1; f[i , i].n[1] := 1;
      tot[i].l := 1; tot[i].n[1] := 2;
      for j:=2 to i - 1 do
        begin
          f[i , j] := f[i - 1 , j];
          Multiply_int(f[i , j] , j);
          Increase(f[i , j] , f[i - 1 , j - 1]);
          Increase(tot[i] , f[i , j]);
        end;  
    end;

  while true do
    begin
      read(n);
      if n = 0 then break;
      write(n , ' ');
      print(tot[n]);
    end;
end.
