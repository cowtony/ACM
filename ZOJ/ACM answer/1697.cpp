//327372 2003-10-28 00:22:16 Accepted 1697 C++ 00:00.01 436K just for play 
#include<iostream.h>
#include<string.h>
#include<stdio.h>

int tran[6][3];
bool has_put[6];
int tran_put[6];
int max_num;

void rotate(int td[])
{
	int i;
	int tt=td[0];
	for(i=0;i<2;i++)
		td[i]=td[i+1];
	td[2]=tt;
}
void fan(int td[])
{
	int tt=td[1];
	td[1]=td[2];td[2]=tt;
}

void try_put(int lev)
{
	//cout<<tran[tran_put[lev-1]][0]<<" "<<tran[tran_put[lev-1]][1]<<" "<<tran[tran_put[lev-1]][2]<<endl;
	
	//cout<<(lev-1)<<" == "<<tran_put[lev-1]<<endl;
	int i,j;
	if(lev==6)
	{
		if(tran[tran_put[5]][1]!=tran[0][2])	return;
		int tcnt=0;
		for(i=0;i<6;i++)	tcnt+=tran[i][0];
		if(tcnt>max_num)	max_num=tcnt;
		return;
	}	
	for(i=1;i<6;i++)
	{
		if(has_put[i])	continue;
		has_put[i]=true;
		for(j=0;j<3;j++)
		{
			//cout<<tran[i][0]<<" = "<<tran[i][1]<<" = "<<tran[i][2]<<endl;

			if(tran[i][2]==tran[tran_put[lev-1]][1])
			{
				tran_put[lev]=i;
				try_put(lev+1);
			}
			rotate(tran[i]);
//			if(j==2)	fan(tran[i]);
//			else	rotate(tran[i]);
		}
		has_put[i]=false;
	}
}

int main()
{
//	freopen("1697.in","r",stdin);		
//	freopen("1697.out","w",stdout);
	char ch;
	while(1)
	{
		int i,j,t;
		for(i=0;i<6;i++)
			cin>>tran[i][0]>>tran[i][1]>>tran[i][2];
		cin>>ch;
		
		memset(has_put,false,sizeof(has_put));
		max_num=-1;
		has_put[0]=true;
		tran_put[0]=0;
		for(i=0;i<3;i++)
		{
			try_put(1);
			rotate(tran[0]);
//			if(i==2)	fan(tran[0]);
//			else	rotate(tran[0]);
		}
		if(max_num<0)	cout<<"none"<<endl;
		else	cout<<max_num<<endl;
		if(ch=='$')	break;
	}
	return 0;
}
	

		


