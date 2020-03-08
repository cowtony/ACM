//170113 2003-06-11 13:04:34 Wrong Answer 1105 C++ 00:00.00 440K just for play 
//170127 2003-06-11 13:17:11 Accepted 1105 C++ 00:00.00 440K just for play 

#include<iostream.h>
#include<stdio.h>
#include<math.h>

int main()
{
	//freopen("1105.in","r",stdin);
	double x,y;
	double curx1,cury1,curx2,cury2;
	while(scanf("%lf %lf",&x,&y)==2)
	{
		char tch;char end[5];
		double dis=0;
		cin.get();
		while(cin.get(tch))
		{
			if(tch=='j')
			{
				cin>>end;break;
			}
			cin.putback(tch);
			cin>>curx1>>cury1>>curx2>>cury2;		
			dis+=sqrt((curx1-curx2)*(curx1-curx2)+(cury1-cury2)*(cury1-cury2));		
			cin.get();
		}
				
		int hour,minute;
		dis/=10000.0;
		dis+=1/120.0;					//avoid  1:60  round here
		hour=dis;
		minute=(dis-hour)*60;				
		printf("%d:%02d\n", hour, minute);
		
	}
	return 0;
}
/*
	Need For Speed's input

  	while(gets(buf)){
			if (buf[0]=='j') break;
			if (buf[0]=='\0') continue;
			sscanf(buf, "%lf %lf %lf %lf", &a, &b, &c, &d);// EXCELLENT!
			len+=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		}
*/


