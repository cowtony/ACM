//99595 2003-03-27 11:55:58 Time Limit Exceeded 1013 C++ 00:10.00 7340K Century Ghost 
//100314 2003-03-27 22:11:35 Wrong Answer 1013 C++ 00:05.01 15212K Century Ghost 
#include<iostream.h>
//#include<string.h>
/*
#include<fstream.h>
ofstream cout("out.txt");
ifstream cin("in.txt");
*/
int w[3],s[3],value[3];
int set[3];int mvalue;

struct node
{
	int vv[501][501];
};
int getmin(int fir,int sec)
{	
	return ((fir<sec)?fir:sec);	
}
int getmax(int fir,int sec)
{
	return ((fir<sec)?sec:fir);
}

int main()
{
	int count=0;
	int n;int flag=0;
	while(cin>>n)
	{
		if(n==0)	break;
		if(flag)	cout<<endl;
		flag=1;
		count++;
		int i;
		for(i=0;i<3;i++)
			cin>>w[i]>>s[i]>>value[i];
		cin>>set[0]>>set[1]>>set[2]>>mvalue;		
		node* beg=new node;
		node* end=new node;
		int j,t;
		for(i=0;i<501;i++)
			for(j=0;j<501;j++)
				beg->vv[i][j]=-1;
		beg->vv[0][0]=0;
		
		int tw,ts;
		int r[510][501];
		int totalw=0,totals=0;
		for(i=1;i<=n;i++)
		{
			cin>>tw>>ts;
		//	cout<<i<<"=="<<endl;
			totalw+=tw;totals+=ts;
			for(j=0;j<=501;j++)						
				for(t=0;t<501;t++)
					end->vv[j][t]=-1,r[j][t]=-1;
			int temp1=getmin(500,getmin(tw/w[0],ts/s[0]));
			int temp2;			
			for(j=0;j<=temp1;j++)
			{	temp2=getmin(500,getmin((tw-j*w[0])/w[1],(ts-j*s[0])/s[1]));
				for(t=0;t<=temp2;t++)
					r[j][t]=getmin((tw-j*w[0]-t*w[1])/w[2],(ts-j*s[0]-t*s[1])/s[2]);
			}
			temp1=getmin(500,getmin(totalw/w[0],totals/s[0]));
			for(j=0;j<=temp1;j++)
			{
				temp2=getmin(500,getmin((totalw-j*w[0])/w[1],(totals-j*s[0])/s[1]));
				for(t=0;t<=temp2;t++)
				{
					int ja,ta;
					int max=-1;
					int ttgetmin1,ttgetmax1,ttgetmin2,ttgetmax2;
					ttgetmin1=getmax(0,j-getmin(tw/w[0],ts/s[0]));
					ttgetmax1=getmin(j,getmin((totalw-tw)/w[0],(totals-ts)/s[0]));
					for(ja=ttgetmin1;ja<=ttgetmax1;ja++)
					{				
						ttgetmin2=getmax(0,t-getmin((tw-(j-ja)*w[0])/w[1],(ts-(j-ja)*s[0])/s[1]));
						ttgetmax2=getmin(t,getmin((totalw-tw-ja*w[0])/w[1],(totals-ts-ja*s[0])/s[1]));
						for(ta=ttgetmin2;ta<=ttgetmax2;ta++)						
							if(beg->vv[ja][ta]>=0&&r[j-ja][t-ta]>=0)
							{
								if(beg->vv[ja][ta]+r[j-ja][t-ta]>max)	max=beg->vv[ja][ta]+r[j-ja][t-ta];
							}																			
					}
					end->vv[j][t]=max;
					if(end->vv[j][t]>500)	end->vv[j][t]=500;
				}
			}
	/*		for(j=0;j<=getmin(500,getmin(tw/w[0],ts/s[0]));j++)
				for(t=0;t<=getmin(500,getmin(tw/w[1],ts/s[1]));t++)
					cout<<j<<"----"<<t<<"    "<<end->vv[j][t]<<endl;
*/
				
			node* temp=beg;beg=end;end=temp;
		
		}
	//	cout<<tw<<ts<<endl;
		int max=0;
		for(j=0;j<=getmin(500,getmin(totalw/w[0],totals/s[0]));j++)
			for(t=0;t<=getmin(500,getmin((totalw-j*w[0])/w[1],(totals-j*s[0])/s[1]));t++)
			{
				//cout<<j<<"-->"<<t<<"  =   "<<beg->vv[j][t]<<endl;
				if(beg->vv[j][t]>=0)
				{
					int tt=getmin(j/set[0],getmin(t/set[1],beg->vv[j][t]/set[2]));
					int total=tt*mvalue;
					total+=(j-tt)*value[0];
					total+=(t-tt)*value[1];
					total+=(beg->vv[j][t]-tt)*value[2];
					if(total>max)	max=total;
				}
			}
		cout<<"Case "<<count<<": "<<max<<endl;
	}
	return 0;
}
				


		