//346180 2003-11-11 20:22:47 Wrong Answer 1704 C++ 00:00.00 380K just for play 
//346197 2003-11-11 20:33:53 Accepted 1704 C++ 00:00.01 380K just for play 
#include<stdio.h>

struct POINT 
{
	char ch;
	int x,y;
};

int n;
POINT inp[16];

int multi_cal(int fir,int sec,int mid)
{
	return ((inp[fir].x-inp[mid].x)*(inp[sec].y-inp[mid].y)-
			(inp[fir].y-inp[mid].y)*(inp[sec].x-inp[mid].x));
}

bool in_triangle(int cur,int fir,int sec,int thi)
{
	if(multi_cal(fir,cur,thi)*multi_cal(cur,sec,thi)>=0&&
		multi_cal(thi,cur,sec)*multi_cal(cur,fir,sec)>=0&&
		multi_cal(sec,cur,fir)*multi_cal(cur,thi,fir)>=0)
		return true;
	return false;
}



bool form_valid(int fir,int sec,int thi)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==fir||i==sec||i==thi)	continue;
		if(in_triangle(i,fir,sec,thi))	return false;
	}
	return true;
}
int main()
{
//	freopen("1704.in","r",stdin);
	int i,j,t;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		char str[2];
		for(i=0;i<n;i++)
		{
			scanf("%s %d %d",str,&inp[i].x,&inp[i].y);
			inp[i].ch=str[0];
		}
		int sel_i,sel_j,sel_t;
		int  maxarea=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				for(t=j+1;t<n;t++)
				{
					if(form_valid(i,j,t))
					{
						
						int area=multi_cal(i,j,t);
						if(area<0)	area=-area;
						if(area>maxarea)
						{
							maxarea=area;
							sel_i=i;sel_j=j;sel_t=t;
						}
					}
				
				}
		printf("%c%c%c\n",inp[sel_i].ch,inp[sel_j].ch,inp[sel_t].ch);
	}
	return 0;
}
		


