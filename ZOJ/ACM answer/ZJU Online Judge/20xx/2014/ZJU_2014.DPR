program zju_2014;
{$APPTYPE CONSOLE}
type
    Integer = Longint;
    PIG = Record
            W , P   : Integer;
//            V       : Double;
          End;
var
    E , F       : Integer;
    N           : Integer;
    List        : Array[1..500] of PIG;
    d           : Array[0..10000] of Integer;

procedure Init;
var
    i           : Integer;
begin
    Read(E , F);  Dec(F , E);
    Read(N);

    for i := 1 to N do
    begin
        Read(List[i].P , List[i].W);
//        List[i].V := List[i].P / List[i].W;
    end;
end;
{
procedure Sort;
var
    i , j , k   : Integer;
    tmp         : PIG;
begin
    for i := 1 to n do
    begin
        k := i;
        for j := i + 1 to n do
            if(List[j].V < List[k].V) then k := j;
        if (k <> i) then
        begin
            tmp := List[i];
            List[i] := List[k];
            List[k] := tmp;
        end;
    end;
end;
}
procedure Solve;
var
    i , j       : Integer;
begin
    filldword(d , F + 1 , 100000000);
    d[0] := 0;

    for i := 1 to n do
    begin
    {
        for j := List[i].W to F do
        begin
            if(d[j - List[i].W] >= 0) and ((d[j] < 0) or (d[j - List[i].W] + List[i].P < d[j])) then
            begin
               d[j] := d[j - List[i].W] + List[i].P;
            end;
        end;
    }
        for j := 0 to F - List[i].W do
        begin
        //    if(d[j] >= 0) then
        //    begin
                if(d[j] + List[i].P < d[j+List[i].W])
                    then begin
                        d[j + List[i].W] := d[j] + List[i].P;
                    end;
        //    end;
        end;
    end;

    if(d[F] = 100000000) then Writeln('This is impossible.')
    else Writeln('The minimum amount of money in the piggy-bank is ' , d[F] , '.');
end;

var
    T       : Integer;
begin
//    Assign(Input , 'pig.in'); Reset(Input);
//    Assign(Output , 'Out.txt'); ReWrite(Output);

    Read(T);
    while (T > 0) do
    begin
        Init;
 //       Sort;
        Solve;
        Dec(T);
    end;

//    Close(Input); Close(Output);
end.
