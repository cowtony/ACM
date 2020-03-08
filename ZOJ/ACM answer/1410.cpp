#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long x;
    long long a[5][2]={0,0,1,45,11,9000,192,1386450,2893,188019000};
	int cas,i;
    long long num;
	cin>>cas;
	while(cas--)
	{
		cin>>num;
		for(i=1; i<5; i++)
		{
			if(num<a[i][1]) break;
			num-=a[i][1];
		}
		if(num==0) {cout<<"9"<<endl; continue;}
		double a1,d;
		if(i==5)
		{
			a1=38894;
			d=5;
		}
		else
		{
			a1=a[i][0];
			d=i;
		}
		double b=(2*a1-d)/d;
		double c=-2*num/d; 
        double x=(sqrt((double)(b*b-4*c))-b)/2.0;
        long long n=(long long)x;
		num-=(long long)((n*a1)+n*(n-1)*d/2);
		if(!num) num=(long long)(a1+(n-1)*d);
		int br[5]={9,180,2700,36000,450000};
		for(i=0; i<5; i++)
		{
			if(num>br[i]) num-=br[i];
			else break;
		} 
		long long tata=num/(i+1);
		int val=1,j;
		for(j=0; j<i; j++)
		{
			val*=10;
		}
		val+=(tata-1);
		if(num%(i+1)==0) cout<<val%10<<endl;
		else if(num%(i+1)==1) 
		{
			val++;
			while(val>=10)
			{
				val/=10;
			}
			cout<<val<<endl;
		}
		else if(num%(i+1)==2)
		{
			val++;
			while(val>=100)
			{
				val/=10;
			}
			cout<<val%10<<endl;
		}
		else if(num%(i+1)==3)
		{
			val++;
			while(val>=1000)
			{
				val/=10;
			}
			cout<<val%10<<endl;
		}
		else 
		{
			val++;
			while(val>=10000)
			{
				val/=10;
			}
			cout<<val%10<<endl;
		}
	}
	return 0;
}
