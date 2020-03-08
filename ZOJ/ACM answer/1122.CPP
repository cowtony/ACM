 #include<iostream.h>

 int main(){
	int a,b,c,d;
	cout<<"Initial time  Final time  Passes"<<endl;

	while(cin>>a>>b>>c>>d){
		int pass;
		if(c<a) pass=c+12-a-1;
		else if(c==a&&b>d) pass=c+12-a-1;
		else pass=c-a-1;
		float hour2,hour1;
		int aa=a,cc=c;
		if(aa==12) aa=0;

		if(cc==12) cc=0;
		hour1=aa*5+b*5*1.0/60;
		hour2=cc*5+d*5*1.0/60;
		cout<<hour1<<"\t"<<hour2<<"===="<<endl;

		if(b<hour1)
			pass--;
		if(b<hour2&&d>hour2)
			pass+=2;
		if(b<hour2&&d<hour2)
			pass+=1;
		if(b>hour2&&d>hour2)
			pass+=1;

		cout<<"       ";
		if(a<10) cout<<"0";
		cout<<a<<":";
		if(b<10) cout<<"0";
		cout<<b<<"      ";
		if(c<10) cout<<"0";
		cout<<c<<":";
		if(d<10) cout<<"0";
		cout<<d;
		cout.width(7);
		cout<<pass<<endl;
	}
	return 0;
 }



