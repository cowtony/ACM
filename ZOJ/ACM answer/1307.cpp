//109796 2003-04-07 00:14:53 Accepted 1307 C++ 00:00.01 436K Century Ghost 
#include<iostream.h>
#include<stdio.h>

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	int left[7];
	while(cin>>left[1]>>left[2]>>left[3]>>left[4]>>left[5]>>left[6])
	{
		if(left[1]==0&&left[2]==0&&left[3]==0&&left[4]==0&&left[5]==0&&left[6]==0)
			break;
		int total=0;
		total+=left[6];
		total+=left[5];
		if(left[1]>left[5]*11)	left[1]-=left[5]*11;
		else	left[1]=0;
		total+=left[4];
		if(left[2]>=left[4]*5)
			left[2]-=left[4]*5;
		else
		{
			left[1]-=(left[4]*5-left[2])*4;
			left[2]=0;
		}
		total+=left[3]/4;
		left[3]%=4;
		if(left[3]==3)
		{
			total++;
			if(left[2]>=1)
			{	left[2]-=1;left[1]-=5;}
			else{	left[1]-=9;left[2]=0;}
		}
		if(left[3]==2)
		{
			total++;
			if(left[2]>=3)
			{	left[2]-=3;left[1]-=6;}
			else
			{
				left[1]-=6+4*(3-left[2]);left[2]=0;
			}
		}
		if(left[3]==1)
		{
			total++;
			if(left[2]>=5)
			{
				left[2]-=5;left[1]-=7;
			}
			else{left[1]-=7+4*(5-left[2]);left[2]=0;}
		}
		total+=left[2]/9;
		left[2]%=9;
		if(left[2]>0)
		{
			total++;left[1]-=36-4*left[2];
		}
		if(left[1]>0)
		{
			total+=left[1]/36;
			if(left[1]%36!=0)	total++;
		}
		cout<<total<<endl;
	}
	return 0;
}


