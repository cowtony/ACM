Program zju_1699;

var
  N , Len , c	: Integer;
  position	: Array[1..4] of Integer;
  source	: string;
procedure RunGame;
  var
    i , p	: Integer;
    str		: string;
  procedure find_next(ch	: Char);
    begin
      repeat
        inc(position[p]);
	if source[ position[p] ] = ch then exit;
      until position[p] = len;
      position[p] := Len;
    end;
  begin
    for i:=1 to n do position[i] := 0;
    p := 0;
    for i:=1 to C do
      begin
        Inc(p); if p > N then p := 1;
	Readln(str);
	find_next(str[1]);
	if position[p] = Len then begin
	  Writeln('Player ' , p , ' won after ' , i , ' cards.');
          while i < c do
            begin
              readln(str); inc(i);
            end;
	  exit;
	end;
	if length(str) > 1 then begin
	  find_next(str[2]);
  	  if position[p] = Len then begin
	    Writeln('Player ' , p , ' won after ' , i , ' cards.');
            while i < c do
              begin
                readln(str); inc(i);
              end;
	    exit;
	   end;
	end;
      end;
    Writeln('No player won after ', c ,' cards.');
  end;
begin
  While true do
    begin
      Readln(N , Len , C);
      Readln(source);
      if N = 0 then Break;
      RunGame;
    end;
end.
