//120813 2003-04-14 23:03:17 Memory Limit Exceeded 1013 C++ 00:00.00 99400K just for play 
//120869 2003-04-14 23:24:07 Wrong Answer 1013 C++ 00:05.51 2344K just for play 
//120883 2003-04-14 23:34:52 Accepted 1013 C++ 00:05.57 2344K just for play 

#include<stdio.h>

int n;
int w[3],s[3],v[3];
int car_w[101],car_s[101];
int set[3],set_v;
int max_n[2][501][501];
int total_w[101],total_s[101];

inline int min_num(int fir,int sec)
{
	return (fir<sec)?fir:sec;
}
inline int cal_boot(int fir,int sec,int k)
{
	return (min_num((car_w[k]-fir*w[0]-sec*w[1])/w[2],(car_s[k]-fir*s[0]-sec*s[1])/s[2]));
}
inline int max_num(int fir,int sec)
{
	return (fir>sec)?fir:sec;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int count=0;bool fir_out=true;
	while(scanf("%d",&n))
	{
		if(n==0)	break;

		count++;
		if(!fir_out)	printf("\n");
		fir_out=false;
		int i,j,t,k;
		for(i=0;i<3;i++)	scanf("%d%d%d",&w[i],&s[i],&v[i]);
		scanf("%d%d%d%d",&set[0],&set[1],&set[2],&set_v);
		total_w[0]=0;total_s[0]=0;
		for(i=1;i<=n;i++)	
		{	
			scanf("%d%d",&car_w[i],&car_s[i]);
			total_w[i]=total_w[i-1]+car_w[i];
			total_s[i]=total_s[i-1]+car_s[i];
		}

		max_n[0][0][0]=0;
		int lev;
		for(lev=1;lev<=n;lev++)
		{
			int pt=lev%2;
			int fir,sec;
			fir=min_num(total_w[lev-1]/w[0],total_s[lev-1]/s[0]);
			for(i=0;i<=fir;i++)
			{
				sec=min_num((total_w[lev-1]-i*w[0])/w[1],(total_s[lev-1]-i*s[0])/s[1]);
				for(j=0;j<=sec;j++)
					max_n[pt][i][j]=-1;
			}

			fir=min_num(total_w[lev]/w[0],total_s[lev]/s[0]);			
			for(i=0;i<=fir;i++)
			{
				sec=min_num((total_w[lev]-i*w[0])/w[1],(total_s[lev]-s[0]*i)/s[1]);
				for(j=0;j<=sec;j++)
				{
					int max=-1;
					int fir_end=min_num(i,min_num(car_w[lev]/w[0],car_s[lev]/s[0]));
					int fir_beg=max_num(0,i-min_num(total_w[lev-1]/w[0],total_s[lev-1]/s[0]));
	
					for(t=fir_beg;t<=fir_end;t++)
					{
						int sec_end=min_num(j,min_num((car_w[lev]-t*w[0])/w[1],(car_s[lev]-t*s[0])/s[1]));
						int sec_beg=max_num(0,j-min_num(total_w[lev-1]/w[1],total_s[lev-1]/s[1]));
						for(k=sec_beg;k<=sec_end;k++)
						{	
							
							if(max_n[1-pt][i-t][j-k]>=0)
							{
								int tt=cal_boot(t,k,lev);
								if(tt+max_n[1-pt][i-t][j-k]>max)	max=tt+max_n[1-pt][i-t][j-k];
							}
						}
					}
					max_n[pt][i][j]=max;
				}
			}
		}
					
		int pt=n%2;
		int max_val=-1;
		int fir=min_num(total_w[n]/w[0],total_s[n]/s[0]);		
		for(i=0;i<=fir;i++)
		{
			int sec=min_num((total_w[n]-i*w[0])/w[1],(total_s[n]-s[0]*i)/s[1]);
			for(j=0;j<=sec;j++)
			{
//				cal(i,j,n);
//				printf(" %d ------ %d ------> %d\n",i,j,max_n[n][i][j]);
				if(max_n[pt][i][j]>=0)
				{
					int tt=min_num(i/set[0],min_num(j/set[1],max_n[pt][i][j]/set[2]));
					int temval=tt*set_v;
					temval+=(i-tt*set[0])*v[0];
					temval+=(j-tt*set[1])*v[1];
					temval+=(max_n[pt][i][j]-tt*set[2])*v[2];
					if(temval>max_val)	max_val=temval;
				}
			}
		}
		printf("Case %d: %d\n",count,max_val);
		
	}
	return 0;
}

	