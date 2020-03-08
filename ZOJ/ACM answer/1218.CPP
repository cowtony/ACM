 #include<iostream.h>
 #include<stdlib.h>

 int main()
 {
	int fir,sec;     int flag=0;
	while(cin>>fir)
	{
		cin>>sec;
		if(flag==1)	cout<<endl;
		if(flag==0)	flag=1;

		double ini=fir*1.0/sec;
		int tt=floor(ini);

		double rate=tt;
		int temp=0;
		if(ini>rate)	temp=1;
		int i,j;
		if(ini>=1){
			cout<<tt<<"/1"<<endl;
			for(i=2;i<sec;i++)
			{
				for(j=floor(rate*i);j<=ceil(rate*ini);j++)
				{
					if(j*1.0/i-rate>0.000001&&(j+1)*1.0/i-ini<0.0001)
					{
						cout<<j<<"/"<<i<<endl;
						rate=j*1.0/i;
						break;
					}
				}
			}
		}

		cout<<fir<<"/"<<sec<<endl;






