//109191 2003-04-06 15:48:36 Wrong Answer 1389 C++ 00:03.06 2500K Century Ghost 
//109209 2003-04-06 16:02:42 Wrong Answer 1389 C++ 00:06.25 2500K Century Ghost 
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
double epison=1.0e-15;
struct rect
{
	double base;
	double height;
	double width;
	double depth;
	double cal_v()
	{
		return height*width*depth;
	}
	double base_area()
	{
		return width*depth;
	}
	double curv(double lev)
	{
		if(lev-base-height>epison)
			return cal_v();
		else if(lev-base>epison)
			return width*depth*(lev-base);
		else	return 0;
	}
	void adjust(double curlev)
	{
		if(curlev-base>epison)
		{
			base=curlev;
			height=height+base-curlev;
			if(height<epison)	height=0;
		}
	}

};
vector<rect>cistern;
long n;
double rect_v;

bool smaller(const rect& fir,const rect& sec)
{
	if(fir.base+fir.height-sec.base-sec.height<epison)	return true;
	return false;
}

long select_up(long from,long to)
{
	if(from==to)	return from;
	int pt=(from+to)/2;
	long	i;
	double sum=0;
	double curlev=cistern[pt].base+cistern[pt].height;
	for(i=from;i<=to;i++)	
		sum+=cistern[i].curv(curlev);
//	printf("%ld----%ld----%lf----%lf\n",from,to,sum,rect_v);
	if(rect_v-sum>epison)
	{

		for(i=pt+1;i<=to;i++)
			cistern[i].adjust(curlev);

		rect_v-=sum;

		return select_up(pt+1,to);
	}
	else	return select_up(from,pt);
}
		
		



double select_res(long pt,double from,double to)
{
	if(to-from<0.0001)	return from;
	double sum=0;
	double middle=(from+to)/2;
//	printf("%lf,  %lf,  %lf\n",from,to,middle);
	long i;
	for(i=pt;i<n;i++)
		sum+=cistern[i].curv(middle);
//	printf("%lf----%lf\n",sum,rect_v);
	if(rect_v-sum>epison)
	{

		for(i=pt;i<n;i++)
			cistern[i].adjust(middle);

		rect_v-=sum;
		return select_res(pt,middle,to);
	}
	else	return select_res(pt,from,middle);
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nn;
	scanf("%ld",&nn);
	while(nn--)
	{
		
		scanf("%ld",&n);
		long i;double sum=0;
		cistern.clear();
		for(i=0;i<n;i++)
		{
			rect temp;
			scanf("%lf%lf%lf%lf",&temp.base,&temp.height,&temp.width,&temp.depth);
			cistern.push_back(temp);
			sum+=temp.cal_v();
		}		
		
		scanf("%lf",&rect_v);
		if(rect_v-sum>epison)
		{
			printf("OVERFLOW\n");
			continue;
		}
//		for(i=0;i<n;i++)
//		{
//			printf("%d-----\n",i);
//			cistern[i].print();
//		}

		sort(cistern.begin (),cistern.end(),smaller);
//		for(i=0;i<n;i++)
//			cistern[i].print();

		long pt=select_up(0,n-1);
//		printf("%ld\n",pt);

		double min=cistern[pt].base ;
		for(i=pt+1;i<n;i++)
			if(cistern[i].base-min<epison)	min=cistern[pt].base;

	
		double res=select_res(pt,min,cistern[pt].base+cistern[pt].height);
		printf("%.02lf\n",res);
	}
	return 0;
}

