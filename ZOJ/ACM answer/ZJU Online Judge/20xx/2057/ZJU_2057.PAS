program Ural_1067;
type
 strType = string[90];
var
 N : integer;
 List : array[1..500] of strType;

 i,p : integer;
 ta,tb : strType;

function LessEqua(a,b : string) : Boolean;
 var pa,pb : integer;
 begin
  while true do
   begin
    pa := pos('\',a); pb := pos('\',b);
    ta := copy(a,1,pa-1); tb := copy(b,1,pb-1);    
    if (ta < tb) then begin LessEqua := true; exit; end;
    if (ta > tb) then begin LessEqua := false; exit; end;
    delete(a,1,pa); delete(b,1,pb);
    if (a = '') then begin LessEqua := true; exit; end;
    if (b = '') then begin LessEqua := false; exit; end;
   end;
 end;

procedure Qsort(p,r : integer);
 var i,j : integer;
     x,tmp : strType;
 begin
  if p >= r then exit;
  i := p - 1; j := r + 1;
  x := List[(p + r) shr 1];
  while true do
   begin
    repeat dec(j) until LessEqua(List[j],x);
    repeat inc(i) until LessEqua(x,List[i]);
    if i >= j then break;
    tmp := List[i]; List[i] := List[j]; List[j] := tmp;
   end;
  Qsort(p, j);
  Qsort(j + 1,r );
 end;

procedure DfsPrint(pre,head : strType);
 var L,i : integer;
 begin
  if pre = List[p] then inc(p);
  L := length(pre);
  while (p <= n) and (Copy(List[p],1,L) = pre) do
   begin
    for i:=L+1 to Length(List[p]) do
     if List[p][i] = '\' then break;
    writeln(head,copy(List[p],L+1,i-L-1));
    DfsPrint(copy(List[p],1,i),head + ' ');
   end;
 end;
var t , caseno : integer;
begin
readln(t);
for caseno := 1 to t do
begin
 if (caseno > 1) then writeln;
 Readln(n);
 for i:=1 to n do
 begin
  Readln(List[i]);
  List[i] :='#\' + List[i] + '\';
 end;
 Qsort(1,n);

 p := 1;
 DfsPrint('#\','');
end;
end.