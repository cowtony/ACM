/*
138394 2003-05-02 10:31:49 Wrong Answer 1584 C++ 00:00.00 31<<12K just for play 
138430 2003-05-02 11:30:43 Runtime Error SIGSEGV 1584 C++ 00:00.04 392K just for play 
138431 2003-05-02 11:32:53 Wrong Answer 1584 C++ 00:00.24 408K just for play 
138437 2003-05-02 11:38:21 Accepted 1584 C++ 00:00.24 408K just for play 
138953 2003-05-02 21:27:53 Wrong Answer 1584 C++ 00:00.00 416K just for play 
*/
#include <stdio.h>
#include <string.h>

char d[1<<12];
struct num_type
{
	int num[4000];
	int total;
	void initial()
	{
		memset(num,0,sizeof(num));
		total=0;
	}
	void print()
	{
		if(total==0)	printf("0\n");
		else
		{
			printf("%d",num[total-1]);
			int pt=total-2;
			while(pt>=0)
			{
				printf("%04d",num[pt]);
				pt--;
			}
			printf("\n");
		}
	}	
	void clear()
	{
		while(total>0&&num[total-1]==0)	total--;
	}
	void convert(char* str)
	{
		total=0;
		int len=strlen(str);
		int i,j;
		for(i=len-1;i>=0;i=i-4)
		{
			int temp=0;
			for(j=i-3;j<=i;j++)
			{
				if(j<0)	continue;
				temp=temp*10+str[j]-'0';
				
			}
		
			num[total++]=temp;
		}
		
		clear();
		
	}
};

num_type fir,sec,result;
const int max_num=10000;

void multiply()
{
	result.initial();
	if(fir.total==0||sec.total==0)	return;
	int i,j;
	result.total =fir.total +sec.total ;
	for(i=0;i<sec.total ;i++)
	{		
		int left=0;int temp;
		for(j=0;j<fir.total ;j++)
		{
			temp=result.num[j]+sec.num[i]*fir.num[j]+left;
			result.num[j]=temp%max_num;
			left=temp/max_num;
		}
		while(left)
		{
			temp=result.num[j]+left;
			result.num[j]=temp%max_num;
			left=temp/max_num;
			j++;
		}
	}
	result.clear();
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	while(fgets(d,1<<12,stdin))
	{
		int N=strlen(d);
		d[--N]=0;
		if(N>1<<12-2)
		{
			printf("0\n");
			continue;
		}

		if(N-(N>>1)-(N>>1))
		{
			d[N++]='0';d[N]=0;
		}
		char str_fir[1<<12];char str_sec[1<<12];
		int i;int pt=0;
		for(i=(N>>1)-1;i>=0;i--)	str_fir[pt++]=d[i];
		str_fir[N>>1]=0;
		pt=0;
		for(i=N>>1;i<N;i++)	str_sec[pt++]=d[i];		
		str_sec[N>>1]=0;
		fir.initial();sec.initial();
		fir.convert (str_fir);
		sec.convert (str_sec);
		multiply();
		result.print ();	
	}
	return 0;
}

