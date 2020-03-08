#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char s[100],c;
	double time,timenow;
	double dis,t;
	double speed;
	int i=0;
	dis=0;
	while(scanf("%s",s)!=EOF)
	{
		timenow=((s[0]-48)*10+(s[1]-48))*3600+((s[3]-48)*10+(s[4]-48))*60+(s[6]-48)*10+(s[7]-48);
		if(i==0) time=timenow;
		scanf("%c",&c);
		if(c==' ') 
		{
			dis+=(timenow-time)*speed/3600;
			time=timenow;
			scanf("%lf",&speed);
		}
		else
		{
			t=dis+(timenow-time)*speed/3600;			
			printf("%s %.2lf km\n",s,t);
		}
		i=1;
	}
	return 0;
}
    
