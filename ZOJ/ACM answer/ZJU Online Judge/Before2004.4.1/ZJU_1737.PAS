Program zju_1737;

var
  T , CaseNo		: Integer;
  Order , source	: string;
  i			: Integer;
  Len			: Integer;

procedure Mr_J;
{
Mr. J rotates all characters of the message
to the left by one. For example, he transforms "aB23d" to "B23da".
}
  begin
    source := source[Len] + source;
    delete(source , Len + 1 , 1);
  end;

procedure Mr_C;
{
Miss C rotates all characters of the message
to the right by one. For example, she transforms "aB23d" to "daB23".
}
  begin
    source := source + source[1];
    delete(source , 1 , 1);
  end;

procedure Mr_E;
{
Mr. E swaps the left half of the message with 
the right half. If the message has an odd number of characters, 
the middle one does not move. For example, he transforms "e3ac" to "ace3", and "aB23d" to "3d2aB".
}
  begin
    if odd(Len) then source := copy(source , Len div 2 + 2 , Len div 2) + source[Len div 2 + 1] + copy(source , 1 , Len div 2)
    else source := copy( source , Len div 2 + 1 , Len div 2) + copy(source , 1 , Len div 2);
  end;

procedure Mr_A;
{
Mr. A reverses the message. For example, he transforms "aB23d" to "d32Ba".
}
  var 
    i			: Integer;
    ret			: string;
  begin
    ret := '';
    for i:= Len downto 1 do
      ret := ret + source[i];
    source := ret;
  end;

procedure Mr_P;
{
Dr. P increments by one all the digits in the message. 
If a digit is '9', it becomes '0'. 
The alphabet characters do not change. 
For example, he transforms "aB23d" to "aB34d", and "e9ac" to "e0ac".
}
  var
    i			: Integer;
  begin
    for i:=1 to Len do
      if (source[i] = '0') then source[i] := '9'
      else if (source[i] >= '1') and (source[i] <= '9') then source[i] := char(ord(source[i]) - 1);
  end; 

procedure Mr_M;
{
Mr. M decrements by one all the digits in the message. 
If a digit is '0', it becomes '9'. The alphabet characters do not change. 
For example, he transforms "aB23d" to "aB12d", and "e0ac" to "e9ac".
}
  var
    i			: Integer;
  begin
    for i:=1 to Len do
      if (source[i] = '9') then source[i] := '0'
      else if (source[i] >= '0') and (source[i] <= '8') then source[i] := char(ord(source[i]) + 1);
  end; 

begin
  Readln(CaseNo);
  for T := 1 to CaseNO do
    begin
      Readln(Order);
      Readln(source);
      Len := Length(source);
      for i := Length(Order) downto 1 do
	  Case Order[i] of 
	    'J' : Mr_J;
	    'C' : Mr_C;
	    'E' : Mr_E;
	    'A' : Mr_A;
	    'P' : Mr_P;
	    'M' : Mr_M;
	   end;
      Writeln(source);
    end; 
end.
