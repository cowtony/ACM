#include<iostream.h>

struct point
{
	double h,dis;
};
int main()
{
	int n;point leap[101];
	while(cin>>n)
	{
		int i;
		for(i=0;i<n;i++)
			cin>>leap[i].h>>leap[i].dis;
		point coord[101];
		double countx=0;
		coord[0].h=0;coord[0].dis=0;
		int firpt,secpt;int pt=1;
		for(i=0;i<n;i++)
		{
			countx+=leap[i].dis;
			if(leap[i+1].h>coord[pt-1].h)
			{
				coord[pt].h=leap[i+1].h;coord[pt++].dis=countx;
			}
		}
		firpt=pt;
		pt=n-2;
		coord[n-1].h=0;coord[n-1].dis=countx;
		for(i=n-1;i>=0;i--)
		{
			countx-=leap[i].dis;
			if(leap[i-1].h>coord[pt+1].h)
			{
				coord[pt].h=leap[i-1].h;coord[pt--].dis=countx;
			}
		}
		for(i=0;i<firpt;i++)
			cout<<coord[i].h<<"  "<<coord[i].dis<<" ";
		for(i=pt+1;i<n;i++)
			cout<<coord[i].h<<"  "<<coord[i].dis;
		cout<<endl;
		secpt=pt;
	}
	return 0;
}



			
