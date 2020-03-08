{$n+}
Program zju_1763;
var
  prev , next	: Double;
begin
  read(prev);
  while true do
    begin
      read(next);
      if (next = 999) then break;
      writeln(next - prev : 0 : 2);
      prev := next;
    end;
  Writeln('End of Output');
end.
