{$MODE FPC}
{$M 0,1025}
{$R-,S-,Q-,I-}
Program zju_1713;
const
  Ovw : set of char = ['a','e','i','o','u','y'];
var
  Line		: string;
  p		: Integer;
  i , c		: Integer;
begin
  While true do
    begin
      Readln(Line);
      if Line = 'e/o/i' then break;

      p := pos('/' , Line);
      c := ord(Line[1] in Ovw);
      for i:=2 to p-1 do
        if (Line[i] in Ovw) and (not (Line[i-1] in Ovw)) then Inc(c);
      if c <> 5 then begin Writeln(1); continue; end;
      delete(Line , 1 , p);

      p := pos('/' , Line);
      c := ord(Line[1] in Ovw);
      for i:=2 to p-1 do
        if (Line[i] in Ovw) and (not (Line[i-1] in Ovw)) then Inc(c);
      if c <> 7 then begin Writeln(2); continue; end;
      delete(Line , 1 , p);
      
      c := ord(Line[1] in Ovw);
      for i:=2 to Length(Line) do
        if (Line[i] in Ovw) and (not (Line[i-1] in Ovw)) then Inc(c);
      if c <> 5 then begin Writeln(3); continue; end;
       
      Writeln('Y');
    end;
end.
