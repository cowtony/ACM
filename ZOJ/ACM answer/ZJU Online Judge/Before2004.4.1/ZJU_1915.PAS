{$n+}
Program zju_1915;
var
  T	: Integer;
  N	: Integer;
  List	: Array[1..1000] of double;

  i	: Integer;
  avg	: double;
  ret	: double;
begin
  Read(T);
  While T > 0 do
    begin
      Dec(T);
      Read(N); avg := 0;
      for i:=1 to N do
        begin
	  Read(List[i]);
	  avg := avg + List[i];
	end;
      avg := avg / N; ret := 0;
      for i:=1 to N do 
        if List[i] > avg then ret := ret + 1;
      ret := ret / n * 100;
      Writeln(ret : 0 : 3 , '%');
    end;
end.
