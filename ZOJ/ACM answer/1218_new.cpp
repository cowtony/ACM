//98663 2003-03-26 12:07:55 Accepted 1218 C++ 00:00.26 436K Century Ghost 
#include<iostream.h>

int main()
{
	long gain,lose;int flag=0;
	while(cin>>gain>>lose)
	{
		if(flag)	cout<<endl;
		flag=1;
		double pre=gain*10*1.0/lose;
		double fix=gain*1.0/lose;
		long presec=0;
		long i,j;
		for(i=1;;i++)
		{
			double fir,sec;
			for(j=1;;j++)
			{
				fir=(j-1)*1.0/i;
				sec=j*1.0/i;
				if((fir<fix&&sec>fix)||j*lose==gain*i)	break;
			}
			if(j*lose==gain*i)	
			{
				cout<<j<<"/"<<i<<endl;
				break;
			}
			fir=fix-fir;
			sec=sec-fix;
			if(fir<sec&&fir<pre)
			{	
				cout<<(j-1)<<"/"<<i<<endl;
				pre=fir;
				presec=j-1;
				
			}
			else if(sec<pre)
			{	cout<<j<<"/"<<i<<endl;
				pre=sec;
				presec=j;
			}
		}
	}
	return 0;
}

						


