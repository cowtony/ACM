 #include<iostream.h>

 int isodd(long fir,long sec)
 {
	long min=(fir>sec)?sec:fir;
	long i;
	for(i=2;i<=min;i++)
	{
		if(fir%i==0&&sec%i==0)	return 0;
	}
	return 1;
 }
 int main()
 {
	long step,mod;
	while(cin>>step>>mod)
	{
		cout.width(10);
		cout.setf(ios::right);
		cout<<step;
		cout.width(10);
		cout.setf(ios::right);
		cout<<mod;
		cout<<"    ";
		if(isodd(step,mod))	cout<<"Good Choice"<<endl;
		else	cout<<"Bad Choice"<<endl;
		cout<<endl;
	}
	return 0;
 }
