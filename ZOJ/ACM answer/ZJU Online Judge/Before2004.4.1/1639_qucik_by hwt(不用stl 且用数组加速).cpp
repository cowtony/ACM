#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=16;
const int maxM=1024;
int n,m,best;
char name[maxN][maxN];
int value[maxN];
int end[maxN];
int mask[maxM];
int from[maxN+1];
void search(int depth,int now,int used)
{
	if(now+end[depth]<best)
		return;
	if(depth==n)
	{
		if(now>best)
			best=now;
		return;
	}
	int temp=used|(1<<depth);
	bool valid=true;
	for(int j=from[depth];j<from[depth+1];j++)
		if((mask[j]&temp)==mask[j])
		{
			valid=false;
			break;
		}
	if(valid)
		search(depth+1,now+value[depth],temp);
	search(depth+1,now,used);
}
int get_id(char buf[])
{
	for(int i=0;i<n;i++)
		if(strcmp(name[i],buf)==0)
			return i;
}
int main()
{
	int case_no=0;
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
			scanf("%s%d",name[i],&value[i]);
		end[n-1]=value[n-1];
		for(int i=n-2;i>=0;i--)
			end[i]=end[i+1]+value[i];
		scanf("%d\n",&m);
		for(int i=0;i<m;i++)
		{
			mask[i]=0;
			char buf[maxN];
			scanf("%s",buf);
			mask[i]|=1<<get_id(buf);
			char c;
			scanf("%c",&c);
			while(c!='\n')
			{
				scanf("%s",buf);
				mask[i]|=1<<get_id(buf);
				scanf("%c",&c);
			}
		}
		sort(mask,mask+m);
		int j=0;
		for(int i=0;i<n;i++)
		{
			from[i]=j;
			for(;mask[j]<(1<<(i+1))&&j<m;j++);
		}
		from[n]=m;
		best=0;
		search(0,0,0);
		cout<<"System "<<++case_no<<": "<<best<<endl;
	}
	return 0;
}
