 #include<iostream.h>
 #include<math.h>
 const double EP=0.000000000000001;
 const double pi=3.141592653589793;
 int equal(double fir,double sec)
 {
	if(fir-sec<EP&&sec-fir<EP) return 1;
	return 0;
 }
 double cal(double firx,double firy,double secx,double secy)
 {
	if(equal(firx,secx)) return 0.0;
	return (-(firx-secx)/(firy-secy));
 }
 int main()
 {
	double x1,y1,x2,y2,x3,y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		double midx1,midy1,midx2,midy2;
		midx1=(x1+x2)/2.0;midy1=(y1+y2)/2.0;
		midx2=(x2+x3)/2.0;midy2=(y2+y3)/2.0 ;
		double k1,k2;int flag1=0;int flag2=0;
		if(!equal(y1,y2)) k1=cal(x1,y1,x2,y2);
		else flag1=1;
		if(!equal(y2,y3)) k2=cal(x2,y2,x3,y3);
		else flag2=1;
		double diameter;double cenx,ceny;
		if(flag1) {cenx=midx1;ceny=k2*(midx1-midx2)+midy2;}
		else if(flag2){cenx=midx2;ceny=k1*(midx2-midx1)+midy1;}
		else{cenx=(midy2-midy1+k1*midx1-k2*midx2)/(k1-k2);
		     ceny=(k2*midy1-k1*midy2-k1*k2*(midx1-midx2))/(k2-k1);
		}

		diameter=sqrt((cenx-x1)*(cenx-x1)+(ceny-y1)*(ceny-y1));
		double circum=2*pi*diameter;
		cout.setf(ios::showpoint|ios::fixed);
		cout.precision(2);
		if(equal(circum,0.0)) circum=0.0;
		cout<<circum<<endl;
	}
	return 0;
 }



