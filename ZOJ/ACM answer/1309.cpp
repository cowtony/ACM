//269658 2003-08-22 22:23:59 Wrong Answer 1309 C++ 00:00.02 416K just for play 
//269671 2003-08-22 22:41:26 Wrong Answer 1309 C++ 00:00.04 420K just for play 
//269688 2003-08-22 23:01:13 Wrong Answer 1309 C++ 00:00.04 416K just for play 
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const double PE=1.0e-8;

struct POINT{double x,y;};
POINT light,pile[501];
double radius[501];
int pile_cnt;
double ange_from[501];
double ange_to[501];


double cal_dis(POINT from,POINT to)
{
	return sqrt((from.x-to.x)*(from.x-to.x)+(from.y-to.y)*(from.y-to.y));
}

bool cmp(int fir,int sec)
{
	return (ange_from[fir]+PE<ange_from[sec]);
}

/*
int cmp(const void* fir,const void* sec)
{
	return(ange[(*(int*) fir)]>ange[(*(int*) sec)]);
	
}
*/
int main()
{
//	freopen("f.in","r",stdin);
//	freopen("1309.out","w",stdout);
	while(scanf("%d",&pile_cnt)!=EOF)
	{
		if(pile_cnt==0)	break;
		scanf("%lf %lf",&light.x,&light.y);
		int i,j;
		for(i=0;i<pile_cnt;i++)
			scanf("%lf %lf %lf",&pile[i].x,&pile[i].y,&radius[i]);
		for(i=0;i<pile_cnt;i++)
		{
			double cur_dis=cal_dis(light,pile[i]);
			double cur_ang=acos((light.y-pile[i].y)/cur_dis);				
			if(pile[i].x+PE<light.x)	cur_ang=-cur_ang;
			double ext_ang=asin(radius[i]/cur_dis);
			ange_from[i]=light.x+light.y*tan(cur_ang-ext_ang);
			ange_to[i]=light.x+light.y*tan(cur_ang+ext_ang);
		}

		int pt[501];
		for(i=0;i<pile_cnt;i++)
			pt[i]=i;

		sort(pt,pt+pile_cnt,cmp);		
//		qsort(angpt,2*pile_cnt,sizeof(int),cmp);	
/*
		for(i=0;i<2*pile_cnt;i++)
			printf("%.2lf ",ange[angpt[i]]);
		printf("\n");
*/
		double cur_max;
		for(i=0;i<pile_cnt;i++)
		{
			if(i==0)
			{
				printf("%.2lf ",ange_from[pt[0]]);
				cur_max=ange_to[pt[0]];
			}
			else if(ange_from[pt[i]]>cur_max+PE)
			{
				printf("%.2lf\n",cur_max);
				printf("%.2lf ",ange_from[pt[i]]);
				cur_max=ange_to[pt[i]];
			}
			else if(cur_max+PE<ange_to[pt[i]])
				cur_max=ange_to[pt[i]];
		}
		printf("%.2lf\n",cur_max);


/*
		double cur_max;
		for(i=0;i<pile_cnt;i++)
		{
			if(i==0||ange_from[angpt[i]]>cur_max+PE)
			{
				if(i==0)
				{
					printf("%.2lf ",light.x+light.y*tan(ange_from[angpt[i]]));
					cur_max=ange_to[angpt[i]];
				}
				else{
					double pre_end=light.x+light.y*tan(cur_max);
					double cur_beg=light.x+light.y*tan(ange_from[angpt[i]]);
					if((int)(cur_beg*100)>(int)(pre_end*100))
					{
						printf("%.2lf\n",pre_end);
						printf("%.2lf ",cur_beg);
					}
					cur_max=ange_to[angpt[i]];
				}
			}
			else
			{
				if(cur_max+PE<ange_to[angpt[i]])	cur_max=ange_to[angpt[i]];
			}
		}
		printf("%.2lf\n",light.x+light.y*tan(cur_max));
*/
		printf("\n");
	}
	
	return 0;
}



