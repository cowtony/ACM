//392661 2003-12-11 00:33:37 Runtime ErrorSIGSEGV 1693 C++ 00:00.00 0K just for play 
//392675 2003-12-11 00:40:02 Wrong Answer 1693 C++ 00:00.02 424K just for play 
//393785 2003-12-11 18:04:16 Wrong Answer 1693 C++ 00:00.01 416K just for play 
#include<stdio.h>
#include<string.h>
#include<assert.h>

void sort(int cv[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		int pt=i;
		for(j=i+1;j<n;j++)
			if(cv[j]<cv[pt])	pt=j;

		if(i!=pt){j=cv[i];cv[i]=cv[pt];cv[pt]=j;}
	}
}

int main()
{
	freopen("1693_smh.in","r",stdin);
	//freopen("1693.out","w",stdout);
	int n;
	int dat[5001];
	int dcnt;
	scanf("%d",&n);
	while(n--)
	{
		dcnt=0;
		int buf;
		while(scanf("%d",&buf))
		{
			if(buf==0)	break;
			dat[dcnt++]=buf;
		}
/*
		if(dcnt==0)
		{
			printf("1\n");
		}
*/
		int room[101];
		int line[101][50];
		int curcnt[101];
		memset(curcnt,0,sizeof(curcnt));
		int i,j;
		int cr=0;
		int s_stack[101];		
		int s_cnt=0;
		int cur=0;
		for(i=0;i<dcnt;i++)
		{
			if(dat[i]>0){
				while(s_cnt>0&&cur>0&&curcnt[cur]>=room[cur])
					cur=s_stack[--s_cnt];				
				cr++;				
				room[cr]=dat[i];	
				if(i>0){line[cr][curcnt[cr]++]=cur;
						line[cur][curcnt[cur]++]=cr;
				}
				s_stack[s_cnt++]=cr;
				cur=cr;					
				while(s_cnt>0&&cur>0&&curcnt[cur]>=room[cur])
					cur=s_stack[--s_cnt];
				assert(cur>=1);
			}else{				
				while(s_cnt>0&&cur>0&&curcnt[cur]>=room[cur])
					cur=s_stack[--s_cnt];				
				int pt=s_stack[s_cnt-1+dat[i]];					
//				assert(pt>0);
				if(pt==cur)
				{
					printf("%d	%d	%d	%d\n",s_cnt,dat[i],pt,cur);
				}
//				assert(pt!=cur);
				line[cur][curcnt[cur]++]=pt;
				line[pt][curcnt[pt]++]=cur;
				while(s_cnt>0&&cur>0&&curcnt[cur]>=room[cur])
					cur=s_stack[--s_cnt];
				assert(cur>=1);
				
			}
		}
		for(i=1;i<=cr;i++)
		{
			sort(line[i],curcnt[i]);
			printf("%d",i);
			for(j=0;j<curcnt[i];j++)	printf(" %d",line[i][j]);
			printf("\n");
		}
	}
	return 0;
}





