Program zju_1712;
var
  tot		: Longint;
  str		: string;
  i		: Longint;
  w		: Longint;
begin
  while true do
    begin
      readln(str);
      if str = '0' then break;
      w := 0; tot := 0;
      for i:=length(str) downto 1 do
        begin
          inc(w);         
          tot := tot + (ord(str[i]) - ord('0')) * (1 shl w - 1);

        end;
      Writeln(tot);
    end;
end.
