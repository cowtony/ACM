//185406 2003-07-01 13:22:40 Wrong Answer 1262 C++ 00:00.12 900K just for play 
//185420 2003-07-01 13:38:10 Wrong Answer 1262 C++ 00:00.08 900K just for play 
//185423 2003-07-01 13:42:15 Wrong Answer 1262 C++ 00:00.07 900K just for play 
//185722 2003-07-01 18:11:59 Accepted 1262 C++ 00:00.08 900K just for play 
#include<stdio.h>
#include<string.h>


int str_to_int(char* str)
{
	int len=strlen(str);
	int result=0,i;int cur=1;
	for(i=0;i<len;i++)
	{
		result+=(str[i]-'a')*cur;
		cur=cur<<1;
	}
	return result;
}
		
int main()
{
//	freopen("1262.in","r",stdin);
	int len;
	int occur[66000];
	int re_occur[66000];
	while(scanf("%d",&len)!=EOF)
	{
		char str[20],rule[8],temp_str[20];
		scanf("%s",str);

		int i,j,t,total;		
		for(i=0;i<8;i++)
		{
			scanf("%s",temp_str);
			t=(temp_str[0]-'a')*4+(temp_str[1]-'a')*2+(temp_str[2]-'a');
			rule[t]=temp_str[3];
		}
//		for(i=0;i<8;i++)
//			printf("%c ",rule[i]);
//		printf("\n");
		scanf("%d",&total);
		memset(occur,0xff,sizeof(occur));
		int cur=0;
		while(cur<total)
		{
			t=str_to_int(str);
			if(occur[t]>=0)	break;
			else	occur[t]=cur;
			re_occur[cur]=t;
			strcpy(temp_str,str);
			for(i=0;i<len;i++)
			{
				t=(temp_str[(i+len-2)%len]-'a')*4+(temp_str[i]-'a')*2+(temp_str[(i+1)%len]-'a');				
				str[i]=rule[t];
			}
//			printf("\n%s\n",str);
			cur++;
		}
		int tt=occur[t];
		
		if(cur<total)
		{
			t=re_occur[(total-cur)%(cur-tt)+tt];

			for(i=0;i<len;i++)
			{
				str[i]=t%2+'a';
				t/=2;
			}
		}
			char min_str[20];
			//printf("%s == \n",str);
			strcpy(min_str,str);
			for(i=0;i<len;i++)
			{
				char temp=str[0];
				for(j=0;j<len-1;j++)	str[j]=str[j+1];
				str[len-1]=temp;
				if(strcmp(str,min_str)<0)	strcpy(min_str,str);
			}
				
			printf("%s\n",min_str);
		
	}
	return 0;
}





