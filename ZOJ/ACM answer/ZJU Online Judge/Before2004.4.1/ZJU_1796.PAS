Program zju_1796;
var
  a , b , c , d , e , f	: Integer;
begin
  while true do
    begin
      Read(a , b , c , d , e , f);
      if (a = 0) and (b = 0) and (c = 0) and (d = 0) and (e = 0) and (f = 0) then break;
      writeln('Anna''s won-loss record is ', d + f - a , '-', c + e - b ,'.');
    end; 
end.
