//91017 2003-03-17 23:22:28 Presentation Error 1189 C++ 00:00.04 920K Century Ghost 
//91019 2003-03-17 23:25:31 Accepted 1189 C++ 00:00.04 920K Century Ghost 
#include<stdio.h>
#include<string.h>



struct string
{
	char* str;
	int total[10];
	string()
	{
		str=NULL;
		int i;
		for(i=0;i<10;i++)	total[i]=0;
	}
};

void cal(string& tt)
{
	int len=strlen(tt.str);
	int i;
	for(i=0;i<len;i++)	tt.total[tt.str[i]-'0']++;
}
void form(string& tt,char* temp)
{
	int i;int pt=0;
	for(i=0;i<10;i++)
	{
		if(tt.total[i]>0)
		{
			int tval=tt.total[i];
			while(1)
			{
				if(tval/10==0)	break;
				temp[pt++]=char(tval/10+'0');
				tval%=10;
			}
			temp[pt++]=char(tval+'0');
			temp[pt++]=char(i+'0');
		}
	}
	temp[pt]='\0';
}

int main()
{

	int n;int t;
	char end_msg[4];
	strcpy(end_msg,"-1");
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{
		if(t)	printf("\n");
		char input[100];
		while(1)
		{
			scanf("%s",input);
			if(strcmp(input,end_msg)==0)	break;
			string invent[16];
			invent[0].str=new char[strlen(input)+1];
			strcpy(invent[0].str,input);
			cal(invent[0]);
			

			int i;int j;
			for(i=1;i<=15;i++)
			{

				char temp[500];
				form(invent[i-1],temp);
				invent[i].str=new char[strlen(temp)+1];
				strcpy(invent[i].str,temp);
				
				for(j=0;j<i;j++)				
					if(strcmp(invent[j].str,invent[i].str)==0)	break;
				if(j<i)	break;
				cal(invent[i]);

			}
			if(i>15)	
				printf("%s can not be classified after 15 iterations\n",input);
			else if(i==1)
				printf("%s is self-inventorying\n",input);
			else if(j==i-1)
				printf("%s is self-inventorying after %d steps\n",input,i-1);
			else
				printf("%s enters an inventory loop of length %d\n",input,i-j);
		}
	}
	return 0;
}
			

