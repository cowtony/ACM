#include <iostream>
#include <cmath>
using namespace std;

double a[501][4];
struct connet
{
	int flag;
	double jdian[2];
}con[501][501];

double temp[2];

void jiaodian(int r1,int r2)
{
	if(fabs(a[r1][0]-a[r1][2])<10e-6)
	{
		temp[0]=a[r1][0];
		temp[1]=(temp[0]-a[r2][0])*(a[r2][3]-a[r2][1])/(a[r2][2]-a[r2][0])+a[r2][1];
	}
	else if(fabs(a[r2][0]-a[r2][2])<10e-6)
	{
		temp[0]=a[r2][0];
		temp[1]=(temp[0]-a[r1][0])*(a[r1][3]-a[r1][1])/(a[r1][2]-a[r1][0])+a[r1][1];
	}
	else
	{
		double k1=(a[r1][1]-a[r1][3])/(a[r1][0]-a[r1][2]);
		double k2=(a[r2][1]-a[r2][3])/(a[r2][0]-a[r2][2]);
		temp[0]=(a[r2][1]+a[r1][0]*k1-a[r1][1]-a[r2][0]*k2)/(k1-k2);
		temp[1]=k1*(temp[0]-a[r1][0])+a[r1][1];
	}
}

double area_triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return fabs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3))/2;
}

bool isin(int i,int j,int k,int l)//判断点在三角形内
{
	double tri=area_triangle(con[i][j].jdian[0],con[i][j].jdian[1],con[j][k].jdian[0],con[j][k].jdian[1],con[i][k].jdian[0],con[i][k].jdian[1]);
	double tr1=area_triangle(a[l][0],a[l][1],con[j][k].jdian[0],con[j][k].jdian[1],con[i][k].jdian[0],con[i][k].jdian[1]);
	double tr2=area_triangle(con[i][j].jdian[0],con[i][j].jdian[1],a[l][0],a[l][1],con[i][k].jdian[0],con[i][k].jdian[1]);
	double tr3=area_triangle(con[i][j].jdian[0],con[i][j].jdian[1],con[j][k].jdian[0],con[j][k].jdian[1],a[l][0],a[l][1]);
	if(fabs(tri-tr1-tr2-tr3)<10e-6) return true;
	else return false;
}

void chushihua(int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(j==i) {con[i][j].flag=con[j][i].flag=0;continue;}
			jiaodian(i,j);
			con[i][j].flag=con[j][i].flag=0;
			if(temp[0]>a[i][0]&&temp[0]<a[i][2]||temp[0]>a[i][2]&&temp[0]<a[i][0]||
				temp[1]>a[i][1]&&temp[1]<a[i][3]||temp[1]>a[i][3]&&temp[1]<a[i][1])
			{
				if(temp[0]>a[j][0]&&temp[0]<a[j][2]||temp[0]>a[j][2]&&temp[0]<a[j][0]||
					temp[1]>a[j][1]&&temp[1]<a[j][3]||temp[1]>a[j][3]&&temp[1]<a[j][1])
				{
					con[i][j].flag=con[j][i].flag=1;//两线段相交
					con[i][j].jdian[0]=temp[0];
					con[j][i].jdian[0]=temp[0];
					
					con[i][j].jdian[1]=temp[1];
					con[j][i].jdian[1]=temp[1];
				}
			}
		}
	}
}

int main()
{
	int cas;
	int n;
	int i,j,k,l;
	scanf("%d",&cas);
	int casenum=cas;
	while(cas--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%lf",&a[i][j]);
			}
		}
		chushihua(n);
		int result=0;
		for(i=1;i<=n-2;i++)
		{
			for(j=i+1;j<=n-1;j++)
			{
				if(!con[i][j].flag) continue;
                for(k=j+1;k<=n;k++)
				{
					if(!con[j][k].flag||!con[i][k].flag) continue;
					{
						if(fabs(con[i][j].jdian[0]-con[j][k].jdian[0])<10e-6&&
							fabs(con[i][j].jdian[0]-con[i][k].jdian[0])<10e-6) continue;
						int t=0;
						for(l=1;l<=n;l++)
						{
							if(con[i][l].flag)
							{
								if(con[i][l].jdian[0]>con[i][j].jdian[0]&&con[i][l].jdian[0]<con[i][k].jdian[0]
									||con[i][l].jdian[0]>con[i][k].jdian[0]&&con[i][l].jdian[0]<con[i][j].jdian[0]
									||con[i][l].jdian[1]>con[i][j].jdian[1]&&con[i][l].jdian[1]<con[i][k].jdian[1]
									||con[i][l].jdian[1]>con[i][k].jdian[1]&&con[i][l].jdian[1]<con[i][j].jdian[1])
								{
									t=1;
									break;
								}
							}
							if(con[j][l].flag)
							{
								if(con[j][l].jdian[0]>con[j][i].jdian[0]&&con[j][l].jdian[0]<con[j][k].jdian[0]
									||con[j][l].jdian[0]>con[j][k].jdian[0]&&con[j][l].jdian[0]<con[j][i].jdian[0]
									||con[j][l].jdian[1]>con[j][i].jdian[1]&&con[j][l].jdian[1]<con[j][k].jdian[1]
									||con[j][l].jdian[1]>con[j][k].jdian[1]&&con[j][l].jdian[1]<con[j][i].jdian[1])
								{
									t=1;
									break;
								}
							}
							if(con[k][l].flag)
							{
								if(con[k][l].jdian[0]>con[i][k].jdian[0]&&con[k][l].jdian[0]<con[j][k].jdian[0]
									||con[k][l].jdian[0]>con[j][k].jdian[0]&&con[k][l].jdian[0]<con[i][k].jdian[0]
									||con[k][l].jdian[1]>con[i][k].jdian[1]&&con[k][l].jdian[1]<con[j][k].jdian[1]
									||con[k][l].jdian[1]>con[j][k].jdian[1]&&con[k][l].jdian[1]<con[i][k].jdian[1])
								{
									t=1;
									break;
								}
							}
							if(l!=i&&l!=j&&l!=k)
							{
								if(!con[i][l].flag&&!con[j][l].flag&&!con[k][l].flag)//判断一线段在三角形内
								{
									bool p=isin(i,j,k,l);
									if(p) {t=1;break;}
								}
							}
						}
						if(!t) result++;
					}
				}
			}
		}
		printf("Case %d:\n",casenum-cas);
		printf("%d\n",result);
		if(cas) printf("\n");
	}
	return 0;
}

