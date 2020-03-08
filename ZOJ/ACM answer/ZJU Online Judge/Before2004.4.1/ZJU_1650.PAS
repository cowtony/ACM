{$n+}
Program zju_1650;
var
  a , b , c , d		: Double;
  max , area		: Double;

procedure swap( var a , b	: Double);
  var
    tmp			: Double;
  begin
    tmp := a; a := b; b := tmp;    
  end;

function calc	: Double;
  begin
    calc := 0;
    if a + b + c - d <= 0 then exit;
    if a + b - c + d <= 0 then exit;
    if a - b + c + d <= 0 then exit;
    if -a + b + c + d <= 0 then exit;    
    calc := sqrt((a+b+c-d) * (a+b-c+d) * (a-b+c+d) * (-a+b+c+d)) / 4;
  end;
begin
  while not eof do
    begin
      readln(a , b , c , d);
      if b > a then swap(a , b);
      if c > a then swap(a , c);
      if d > a then swap(a , d);
      max := calc;
      while a > 0.05 do
        begin
          a := a - 0.05;          
          area := calc;
          if area > max then max := area;
        end;  
      writeln(max : 0 : 2);
    end;
end.
