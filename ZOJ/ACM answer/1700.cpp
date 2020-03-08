//334978 2003-11-03 00:21:15 Accepted 1700 C++ 00:00.01 376K just for play 
#include<stdio.h>
#include<string.h>

char ch[26][30];
int pt[26];

void output(int t,char tch)
{
	if(t<0)	return;
	if(pt[t]<strlen(ch[t])&&ch[t][pt[t]]<tch){
		printf("%c",ch[t][pt[t]]);
		output(t-1,ch[t][pt[t]]);
		pt[t]++;
		output(t-1,tch);
	}
	else{
		output(t-1,tch);		
	}
}

int main()
{
	
	
	int cnt,i;
	while(1)
	{
		cnt=0;
		while(1)
		{
			scanf("%s",ch[cnt]);
			if(strcmp(ch[cnt],"*")==0||strcmp(ch[cnt],"$")==0)	break;
			cnt++;
		}
		memset(pt,0,sizeof(pt));
		output(cnt-1,'Z'+1);
		printf("\n");
		if(strcmp(ch[cnt],"$")==0)	break;
	}	
	return 0;
}


