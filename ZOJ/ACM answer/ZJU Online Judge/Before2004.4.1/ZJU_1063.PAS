program zju_1063;
const
  LEN = 62;
type
  node = record
          x, y, z	 : Byte;
         end;

Var
  n, m, k, l		: Integer;
  i, num, nm		: Integer;
  x, y, z, Head, Tail	: Integer;
  G			: Array [0..LEN, 0..LEN, 0..LEN] of Byte;
  Q			: Array [0..LEN * LEN * LEN] of node;

procedure AddNode(x, y, z : Byte);
  begin
    If G[x, y, z] = 2 Then Exit;
    G[x, y, z] := 2;
    Inc(tail);
    Q[Tail].x := x; Q[Tail].y := y; Q[Tail].z := z;
end;

function BFS		: Integer;
  Var
    x, y, z		: Byte;
    ret			: Integer;
  Begin
    ret := 0;
    Head := 0; Tail := -1;
    AddNode(0, 0, 0);

    While Head <= tail do
      begin      
        x := Q[Head].x; y := Q[Head].y; z := Q[Head].z;

        If (z + 1 < k) Then 
          If G[x, y, z + 1] = 1 Then Inc(ret) Else AddNode(x, y, z + 1);
        If (z - 1 >=0) Then 
          If G[x, y, z - 1] = 1 Then Inc(ret) Else AddNode(x, y, z - 1);
        If (x - 1 >=0) Then 
          If G[x - 1, y, z] = 1 Then Inc(ret) Else AddNode(x - 1, y, z);
        If (x + 1 < n) Then 
          If G[x + 1, y, z] = 1 Then Inc(ret) Else AddNode(x + 1, y, z);
        If (y - 1 >=0) Then 
          If G[x, y - 1, z] = 1 Then Inc(ret) Else AddNode(x, y - 1, z);
        If (y + 1 < m) Then 
          If G[x, y + 1, z] = 1 Then Inc(ret) Else AddNode(x, y + 1, z);
        Inc(Head);
      end;
    Bfs := ret;
  end;

Begin
  While true do
    begin
      Readln( n , m , k , l);
      if n = 0 then Break;
      FillChar(G, SizeOf(G), 0);
      nm := n * m;

     for i := 1 To l Do
       begin
         Read(num);
         z := num DIV nm; y := num MOD nm DIV n; x := num MOD nm MOD n;
         G[x + 1, y + 1, z + 1] := 1;
       end;

      Inc(n, 2); Inc(m, 2); Inc(k, 2);

      Writeln('The number of faces needing shielding is ', BFS, '.');      
   end;
End.
