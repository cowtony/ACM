#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const double EPS=5.0*1.0e-13;

struct CIR
{
	double	x,y,r;
};
CIR con[101];
int n;

double  dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void gen_point(double& cx,double& cy,int pt,int se)
{

    double tr=con[pt].r*(se/10000)*1.0/100;
	cx=con[pt].x-tr+2*tr*(se%10000)/10000.0;
	cy=sqrt(tr*tr-cx*cx);
	if(se%2==0)	cy=-cy;

}
bool	can_see(int pt)
{
    double cx,cy;
    int i,j;
    for(i=0;i<101000;i++)
    {
        gen_point(cx,cy,pt,i);
		if(dis(cx,cy,con[pt].x,con[pt].y)>con[pt].r+EPS)	continue;
        for(j=pt+1;j<n;j++)
                if(dis(cx,cy,con[j].x,con[j].y)+EPS<con[j].r)  break;
        if(j==n)                return true;
    }
    
	return false;
}
	

int main()
{
	int i;	
    freopen("1696.in","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		for(i=0;i<n;i++)	
			scanf("%lf %lf %lf",&con[i].x,&con[i].y,&con[i].r);
		int cnt=0;
		for(i=0;i<n;i++)
		{
			if(can_see(i))	cnt++;
		}
		printf("%d\n",cnt);
	}
	return  0;
}
