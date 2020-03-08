//299055 2003-09-26 13:17:21 Runtime Error SIGSEGV 1625 C++ 00:00.02 5508K just for play 
//300536 2003-09-27 23:02:38 Accepted 1625 C++ 00:00.44 16764K just for play 
#include<stdio.h>
#include<string.h>

int seq[2097152];
int mapto[2097152];
int N,T;

int pow_2[21]={1,2,4,8,16,32,64,128,256,512,1024,
2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};


void process(int pre[],int cur[])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		int tcnt=0;
		tcnt+=pre[(i-2+N)%N];
		tcnt+=pre[(i-1+N)%N];
		tcnt+=pre[(i+1)%N];
		tcnt+=pre[(i+2)%N];
		if(pre[i]==1&&(tcnt<2||tcnt==3))	cur[i]=0;
		if(pre[i]==0&&(tcnt==2||tcnt==3)) cur[i]=1;
	}
}

int get_val(int cur[])
{
	int i;
	int tcnt=0;
	for(i=0;i<N;i++)
		tcnt+=pow_2[i]*cur[i];
	return tcnt;
}

void re_val(int tt,int cur[])
{
	int i;
	for(i=N-1;i>=0;i--)
	{
		cur[i]=tt/pow_2[i];
		tt%=pow_2[i];
	}
}


int main()
{
//	freopen("1625.in","r",stdin);	
	int pre[21],cur[21];
	while(scanf("%d %d",&N,&T)!=EOF)
	{
		memset(mapto,0xff,sizeof(mapto));
		int i,j,t;
		for(i=0;i<N;i++)	scanf("%d",&cur[i]);
		int pt=0;
		bool flag=false;
		int tt=get_val(cur);		

		seq[0]=tt;
		mapto[tt]=0;
		while(1)
		{	
			
			if(pt==T)	break;
			pt++;
			for(i=0;i<N;i++)	pre[i]=cur[i];
			process(pre,cur);
			tt=get_val(cur);
			if(mapto[tt]>=0){flag=true;	break;}
			seq[pt]=tt;						
			mapto[tt]=pt;
		}
		
		if(flag)
		{
			int cir=pt-mapto[tt];
			int t=(T-mapto[tt])%cir;
			
			tt=seq[mapto[tt]+t];
			re_val(tt,cur);
		}

		for(i=0;i<N;i++)
		{
				printf("%d",cur[i]);
				if(i==N-1)	printf("\n");
				else	printf(" ");
		}
	}
	return 0;
}



