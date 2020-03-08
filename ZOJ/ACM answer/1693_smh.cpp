// 1693 Map of Ninja House
// 393829 2003-12-11 18:21:59 Accepted 1693 C++ 00:00.01 512K NeedForSpeed

#include<stdio.h>
#include<assert.h>
#include<algorithm>
#include<vector>
using namespace std;


struct ROOM{int dist, spare, top, nbr[100];}list[100];

void addEdge(int a, int b)
{
	list[a].nbr[list[a].top++]=b;
	list[b].nbr[list[b].top++]=a;
	list[a].spare--;
	list[b].spare--;
}
bool IntegerLess(const int& a, const int& b)
{
	if (a<b) return true;
	return false;
}
int main()
{
	freopen("1693_smh.in","r",stdin);
	freopen("1693_smh.out","w",stdout);
	int total, n;
	scanf("%d", &total);
	while(total--){

		scanf("%d", &n);
		list[0].dist=0;
		list[0].spare=n;
		list[0].top=0;

		int roomtop=0;
		do{
			scanf("%d", &n);
			if (n==0) break;

			if (n>0){
				roomtop++;
				list[roomtop].spare=n;
				list[roomtop].top=0;

				int fa=roomtop-1;
				while(fa>=0&&list[fa].spare<=0) fa--;
				assert(fa>=0);///////

				addEdge(fa, roomtop);
				list[roomtop].dist=list[fa].dist+1;

			} else {
				// < 0
				int fa, rm=roomtop, dd;
				while(rm>=0&&list[rm].spare<=0) rm--;
				dd=list[rm].dist+n;
				fa=rm-1;
				while(fa>=0){
					if (list[fa].spare<=0||list[fa].dist!=dd){
						fa--;
					} else
						break;
				}

				assert(fa>=0);///////

				addEdge(fa, rm);
			}
		}while(1);

		for (int i=0; i<=roomtop; i++){
			printf("%d ", i+1);
			int size=list[i].top;
			vector<int> outlist(list[i].nbr, list[i].nbr + size);
			sort(&outlist[0], &outlist[size], IntegerLess);
			for (int j=0; j<list[i].top; j++){
				//printf("%d ", list[i].nbr[j]+1);
				if (j) printf(" ");
				printf("%d", outlist[j]+1);
			}
			printf("\n");
		}
		//printf("\n");
	}
	return 0;
}


