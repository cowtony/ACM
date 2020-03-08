
#include<iostream.h>
#include<math.h>
const double pre=1.0E-12;

struct point
{
	long x,y;
};
point node[151];point center;double radius;
int flag[151];
void exchange(point& fir,point& sec)
{
	point temp;temp.x=fir.x;temp.y=fir.y;
	fir.x=sec.x;fir.y=sec.y;
	sec.x=temp.x;sec.y=temp.y;
}
long multi(point fir,point sec,point cen)
{
	return ((fir.x-cen.x)*(sec.y-cen.y)-(sec.x-cen.x)*(fir.y-cen.y));
}
double dis(point fir,point cen)
{
	return ((double)(fir.x-cen.x)*(double)(fir.x-cen.x)+(double)(fir.y-cen.y)*(double)(fir.y-cen.y));
}
void bubblesort(int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		int pt=i;
		for(j=i+1;j<n;j++)
			if(multi(node[j],node[pt],node[0])>0)	pt=j;
		if(pt!=i)	exchange(node[i],node[pt]);
	}
}
int main()
{
	while(cin>>center.x>>center.y>>radius)
	{
		if(radius<0)	break;
		int n;int i,j;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>node[i].x>>node[i].y;
		int min=0;
		for(i=1;i<n;i++)
			if(node[i].y<node[min].y||(node[i].y==node[min].y&&node[i].x<node[min].x))	min=i;
		exchange(node[0],node[min]);
		bubblesort(n);

		double double_radius=radius*radius;
		for(i=0;i<n;i++)	flag[i]=0;
		for(i=0;i<n;i++)
			if(dis(node[i],center)<double_radius||fabs(dis(node[i],center)-double_radius)<pre)	flag[i]=1;

		int max=0;
		for(i=0;i<n;i++)
		{
			if(!flag[i])	continue;
			int count=1;
			for(j=i+1;;j++)
			{	int jjj=j%n;
				if(jjj==i)	break;
				if(!flag[jjj])	continue;
				if(multi(node[i],node[jjj],center)>=0)	count++;
				else	break;
			}
			if(count>max)	max=count;
		}
		cout<<max<<endl;
	}
	return 0;
}