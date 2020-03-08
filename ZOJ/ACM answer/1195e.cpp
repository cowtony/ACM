//92469 2003-03-19 16:55:09 Accepted 1195 C++ 00:00.01 436K Century Ghost 
#include<iostream.h>
#include<string.h>
const int max=21;

int main()
{
	int n,m,c;
	int count=0;
	while(cin>>n>>m>>c)
	{
		if(n==0&&m==0&&c==0)	break;
		count++;
		int i;long maxcon=0;long total=0;
		long cap[max];int state[max];
		for(i=0;i<n;i++)	state[i]=0;
		for(i=0;i<n;i++)	cin>>cap[i];
		int input;int fuse=0;
		for(i=0;i<m;i++)
		{
			cin>>input;
		
			if(fuse)	continue;
			if(state[input-1])
			{
				total-=cap[input-1];
				state[input-1]=0;
			}
			else	
			{
				total+=cap[input-1];
				state[input-1]=1;
			}
			if(total>c)	fuse=1;
			if(total>maxcon)	maxcon=total;
		}
		cout<<"Sequence "<<count<<endl;
		if(fuse)	cout<<"Fuse was blown."<<endl;
		else	{
			cout<<"Fuse was not blown."<<endl;
			cout<<"Maximal power consumption was "<<maxcon<<" amperes."<<endl;
		}
		cout<<endl;
	}
	return 0;
}


		