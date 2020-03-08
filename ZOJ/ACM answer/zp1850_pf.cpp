program prog1850; 

var 
     prime   :array[1..100] of record 
                                     pe   :longint; 
                                     s   :integer; 
                                  end; 
     n,m   :longint; 
     t      :integer; 

function isprime(n:longint):boolean; 
     var 
          i   :longint; 
     begin 
          isprime:=false; 
          for i:=2 to trunc(sqrt(n)) do 
            if n mod i=0 then exit; 
          isprime:=true; 
     end; 

procedure broke(m:longint); 
     var 
          i   :longint; 
     begin 
          if isprime(m) then 
          begin 
               t:=1; 
               prime[t].pe:=m;prime[t].s:=1; 
               exit; 
          end; 
          t:=0; i:=1; 
          while m>1 do 
          begin 
              inc(i); 
              if m mod i=0 then 
              begin 
                   inc(t); 
                   prime[t].pe:=i; 
                   prime[t].s:=0; 
                   while m mod i=0 do begin inc(prime[t].s);m:=m div i; end; 
                   if isprime(m) then 
                   begin 
                       inc(t); 
                       prime[t].pe:=m;prime[t].s:=1; 
                       exit; 
                   end; 
              end; 
          end; 
     end; 

function check:boolean; 
      var 
          i   :integer; 
      begin 
          check:=false; 
          for i:=1 to t do 
          if n div prime[i].pe<prime[i].s then exit; 
          check:=true; 
      end; 

begin 
     repeat 
          readln(n,m); 
          if (m=0) or (n=0) then writeln(m,' does not divide ',n,'!') else 
          begin 
              broke(m); 
              if check then writeln(m,' divides ',n,'!') else writeln(m,' does not divide ',n,'!'); 
          end; 
     until eof(input); 
end.