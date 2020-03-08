//315990 2003-10-17 22:08:39 Accepted 1641 C++ 00:00.00 436K just for play 
#include<iostream.h>
#include<stdio.h>

char input[4][2];
char prim;

int get_seq(char tch)
{
	if(tch<='9'&&tch>='0')	return tch-'0';
	else if(tch=='T')	return 10;
	else if(tch=='J')	return 11;
	else if(tch=='Q')	return 12;
	else if(tch=='K')	return 13;
	else	return 14;
}

bool larger(char fir,char sec)
{
	if(get_seq(fir)>get_seq(sec))	return true;
	return false;
}
int win_card()
{
	int i,j;
	int tset[4];int tcnt=0;
	char sel;
	for(j=0;j<2;j++)
	{
		if(j==0&&prim=='n')	continue;
		if(j==0)	sel=prim;
		else	sel=input[0][0];
		tcnt=0;
		for(i=0;i<4;i++)	
			if(input[i][0]==sel)	tset[tcnt++]=i;
		int pt=-1;char maxch='0';
		for(i=0;i<tcnt;i++)
		{
			if(larger(input[tset[i]][1],maxch))
			{
				maxch=input[tset[i]][1];
				pt=tset[i];
			}
			
		}
		if(pt!=-1)	return pt;
		
	}
}

int main()
{
//	freopen("1641.in","r",stdin);
	char nch[5];
	char temp;
	int n;
	
	while(cin>>temp)
	{
		n=0;int pt=0;
		prim='n';
		while(temp>='0'&&temp<='9')
		{
			n=n*10+temp-'0';
			nch[pt++]=temp;
			cin>>temp;
		}
		nch[pt]='\0';n+=6;
		if(temp!='N')	prim=temp;
		else	cin>>temp;
		int cnt=0;
		int win=1;
		int i,j;
		for(i=0;i<13;i++)
		{
			for(j=0;j<4;j++)
				cin>>input[j][0]>>input[j][1];
			int t=win_card();
			if(t==win||t==win+2){cnt++;win=0;}
			else	win=1;
		}
		cout<<nch;
		if(prim=='n')	cout<<"NT";
		else	cout<<prim;
		if(cnt==n)	cout<<"MK";
		else if(cnt>n)	cout<<"+"<<cnt-n;
		else	cout<<"-"<<n-cnt;
		cout<<endl;
	}
	return 0;
}

