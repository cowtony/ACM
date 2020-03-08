#include <stdio.h>
int main()
{
	int a[6];
	long count;
	int i,t;
	while(1)
	{
		for(i=0;i<6;i++)
			scanf("%d",&a[i]);
		if(!a[0]&&!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]) break;
		count=a[5];
		count+=a[4];
		a[0]-=a[4]*11;
		count+=a[3];
		t=a[1];
		a[1]-=a[3]*5;
		if(a[1]<0) {a[0]-=(a[3]*5-t)*4;}
		count+=a[2]/4;
		a[2]=a[2]%4;
		if(a[2]!=0)
		{
			count+=1;
			if(a[2]==3)
			{
				a[1]-=1;
				a[0]-=5;
			}
			else if(a[2]==2)
			{
				a[1]-=3;
				a[0]-=6;
			}
			else 
			{
				a[1]-=5;
				a[0]-=7;
			}
		}
		if(a[1]>0)
		{
			count+=a[1]/9;
			a[1]=a[1]%9;
			if(a[1]!=0) count+=1;
			a[0]-=(36-a[1]*4);
		}
		if(a[0]>0)
		{
			count+=a[0]/36;
			a[0]=a[0]%36;
			if(a[0]!=0) count+=1;
		}
		printf("%ld\n",count);
	}
	return 0;
}


		


		
