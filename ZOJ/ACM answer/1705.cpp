//346327 2003-11-11 21:29:30 Accepted 1705 C++ 00:00.01 412K just for play  f
#include<stdio.h>
#include<string.h>

struct VAL{int fir,sec;};

char str[61][21];
int str_cnt;
VAL chang[61][61];

int euric(int fir,int sec)
{
	if(fir>sec)	return euric(sec,fir);
	if(fir==0)	return sec;
	return euric(sec%fir,fir);
}

void change_val(int i,int j,int n1,int n2)
{
	
	if(chang[i][j].fir<0)
	{
		int tt=euric(n1,n2);
		chang[i][j].fir=n1/tt;
		chang[i][j].sec=n2/tt;
		chang[j][i].fir=n2/tt;
		chang[j][i].sec=n1/tt;
		int pt;
		for(pt=0;pt<str_cnt;pt++)
		{
			if(i==pt||j==pt)	continue;
			if(chang[i][pt].fir>0)
			{
				change_val(pt,j,chang[pt][i].fir*chang[i][j].fir,chang[pt][i].sec*chang[i][j].sec);

			}
		}
		for(pt=0;pt<str_cnt;pt++)
		{
			if(i==pt||j==pt)	continue;
			if(chang[j][pt].fir>0)
			{
				change_val(i,pt,chang[i][j].fir*chang[j][pt].fir,chang[i][j].sec*chang[j][pt].sec);
			}
		}
	}
}
int find_pt(char tstr[])
{
	int i;
	for(i=0;i<str_cnt;i++)
		if(strcmp(tstr,str[i])==0)	return i;
	return -1;
}

int main()
{
//	freopen("1705.in","r",stdin);
	char tstr[10],tempstr[10];
	char n1[21],n2[21];
	int v1,v2;
	int i,j;
	str_cnt=0;
	for(i=0;i<61;i++)
		for(j=0;j<61;j++)
			chang[i][j].fir=chang[i][j].sec=-1;

	while(scanf("%s",tstr)!=EOF)
	{
		if(tstr[0]=='.')	break;
		else if(tstr[0]=='!')
		{
			scanf("%d %s %s %d %s",&v1,n1,tempstr,&v2,n2);
			int t1=find_pt(n1);
			if(t1<0)	
			{
				strcpy(str[str_cnt],n1);
				t1=str_cnt;str_cnt++;				
			}
			int t2=find_pt(n2);
			if(t2<0)
			{
				strcpy(str[str_cnt],n2);
				t2=str_cnt;str_cnt++;
			}
			change_val(t1,t2,v1,v2);						
		}
		else
		{
			scanf("%s %s %s",n1,tempstr,n2);
			int t1=find_pt(n1);
			int t2=find_pt(n2);
			if(chang[t1][t2].fir<0)
			{
				printf("? %s = ? %s\n",n1,n2);
			}else{
				printf("%d %s = %d %s\n",chang[t1][t2].fir,n1,chang[t1][t2].sec,n2);
			}
		}
	}

	return 0;
}
