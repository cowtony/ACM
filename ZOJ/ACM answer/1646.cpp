#include<iostream.h>
#include<string.h>

int dit[4][7];
int n;
int input[4][7];
char ch[4][3][3];
int cur[4][7];	
int maxh=-1,maxm;

void process()
{
	int i,j,t;
	for(i=0;i<4;i++)
	{
		if(ch[i][0][1]=='_')	input[i][0]=1;
		for(j=0;j<2;j++)
			for(t=0;t<3;t++)
			{
				if(ch[i][j+1][t]!=' ')	input[i][1+j*3+t]=1;
			}
	}
}
int getdig(int tdig[])
{
	if(tdig[0]==0)
	{
		if(tdig[1]==1)	return 4;
		else	return 1;
	}
	if(tdig[6]==0)	return 2;
	if(tdig[2]==0)
	{
		if(tdig[1]==1)	return 0;
		else	return 7;
	}
	if(tdig[3]==0)
	{
		if(tdig[4]==1)	return 6;
		else return 5;
	}
	if(tdig[4]==1)	return 8;
	if(tdig[1]==0)	return 3;
	return 9;
}

void get_val()
{
	int i;
	int curh=0,curm=0;
	curh=getdig(cur[0]);
	curh=curh*10+getdig(cur[1]);
	curm=getdig(cur[2]);
	curm=curm*10+getdig(cur[3]);
	if(maxh<curh||(maxh==curh&&maxm<curm)){maxh=curh;maxm=curm;}
	
}

void search(int s,int k)
{
	if(s==4)
	{
		get_val();
		return;
	}
	if(dit[s][k]==1)
	{
		cur[s][k]=1;
		search(s+(k+1)/7,(k+1)%n);
	}
	else
	{


	

int main()
{
	
	char tch;
	while(cin>>n)
	{
		memset(dit,0,sizeof(dit));
		int i,j,t,k;		
		for(i=0;i<=n;i++)
		{
			cin.get(tch);
			for(t=0;t<3;t++)
			{
				for(j=0;j<4;j++)
				{
					for(k=0;k<3;k++)
						cin.get(ch[j][t][k]);
				}
				cin.get(tch);
			}
			process();
			if(i<n)	
			{
				for(j=0;j<4;j++)
					for(t=0;t<7;t++)	
						if(input[j][t]==1)	dit[j][t]=1;
			}
		}
		maxh=-1;		
		search(0,0);
		if(maxh<10)	cout<<"0";
		cout<<maxh<<":";
		if(maxm<10)	cout<<"0";
		cout<<maxm<<endl;
	}
	return 0;
}


		




