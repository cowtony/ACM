program Ural1183;

var
  source	: String;
  Len		: Integer;

  F,partition	: Array[1..100,1..100] of Integer;

Function Match(p,r	: Integer) 	: Boolean;
  begin
    Match :=    ((source[p] = '(') and (source[r] = ')'))
             OR ((source[p] = '[') and (source[r] = ']'));
  end;

Function DP(p,r	: Integer)	: Integer;
  var 
    i		: Integer;   
  begin
    if p > r then DP := 0
    else if F[p,r] > 0 then DP := F[p,r]
    else if p = r then begin F[p,r] := 2; DP := 2; end
    else begin
      if Match(p,r) then begin F[p,r] := DP(p+1, r-1) + 2; partition[p,r] := 0; end
                    else F[p,r] := Len * 10;
      for i:=p to r-1 do
        if DP(p,i) + DP(i+1,r) < F[p,r] then
           begin
	     F[p,r] := F[p,i] + F[i+1,r];
             partition[p,r] := i;
           end;
      DP := F[p,r];     
    end;   
  end;

procedure Print(p,r	: Integer);  
  begin
    if p > r then exit;
    if p = r then begin 
      if source[p] in ['(',')'] then Write('()')
                                else Write('[]');      
    end
    else if partition[p,r] = 0 then  begin    
      Write(source[p]);
      Print(p+1, r-1);
      Write(source[r]); 
    end
    else begin
      Print(p, partition[p,r]);
      Print(partition[p,r] + 1, r);
    end;
  end;

var
  N , T		: Integer;
begin
  Readln(N);
  for T:=1 to N do
    begin
      Readln;
      Readln(source);
      Len := Length(source);
      Fillchar(F,sizeof(F),0);
      DP(1,Len);  
      Print(1,Len);
      Writeln;
      if T < N then Writeln;
    end;
end.