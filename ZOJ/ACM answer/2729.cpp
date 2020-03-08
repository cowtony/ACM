#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int main()
{
	int n,result,num,count,temp,i;
	vector <int> svec;
	int a[16];
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) return 0;
		result=0;
		while(n--)
		{
			scanf("%d",&num);
			for(i=15;i>=0;i--)
			{
				a[i]=num%2;
				num/=2;
			}
			for(i=0;i<16;i++)
			{
				svec.push_back(a[i]);
			}
			while(svec.size()>6)
			{
				vector <int>::iterator iter=svec.begin()+1;
				temp=5;
				count=0;
				for(;iter<svec.begin()+7;iter++)
				{
					count+=*iter*(int)pow((double)2,(double)temp--);
				}
				if(*svec.begin()==1) count=0-count;
				result+=count;
				svec.erase(svec.begin(),svec.begin()+7);
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
	



