#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n , a , b , c, tot , m;
struct card{
	short int a , b , c , sum;
	bool used;
} list[100110] , h[310];

short int C[310][310];
int  B[310][310];
short int F[310][310] , R[310][310];

int st , ta , tb , tc , ed;

void init()
{
	scanf("%d %d %d %d" , &n , &a , &b , &c);
	tot = a + b + c;
	int i;

	for(i=0; i<n; i++){
		scanf("%d %d %d" , &list[i].a , &list[i].b , &list[i].c);
		list[i].sum = list[i].a + list[i].b + list[i].c;
		list[i].used = 0;
	}
}

bool comp_a(const card& a , const card& b){
	if(a.a != b.a) return a.a > b.a;
	return a.sum > b.sum;
}

bool comp_b(const card& a , const card& b){
	if(a.b != b.b) return a.b > b.b;
	return a.sum > b.sum;
}

bool comp_c(const card& a , const card& b){
	if(a.c != b.c) return a.c > b.c;
	return a.sum > b.sum;
}

void build()
{
	int i;
	m = 0;

	sort(list , list + n , comp_a);
	for(i=0; i<tot; i++)
		if(!list[i].used){
			list[i].used = 1;
			++m;
			h[m] = list[i]; 
		}

	sort(list , list + n , comp_b);
	for(i=0; i<tot; i++)
		if(!list[i].used){
			list[i].used = 1;
			++m;
			h[m] = list[i]; 
		}
	
	sort(list , list + n , comp_c);
	for(i=0; i<tot; i++)
		if(!list[i].used){
			list[i].used = 1;
			++m;
			h[m] = list[i]; 
		}

	st = 0;
	ta = m + 1; tb = m + 2; tc = m + 3; ed = m + 4;

	memset(C , 0 , sizeof(C));
	memset(B , 0 , sizeof(B));
	memset(F , 0 , sizeof(F));
	memset(R , 0 , sizeof(R));

	for(i=1; i<=m; i++){
		C[st][i] = 1; B[st][i] = 0; R[st][i] = 1;

		C[i][ta] = R[i][ta] = 1; B[i][ta] = h[i].a * 100000 + h[i].sum; B[ta][i] = -B[i][ta];
		C[i][tb] = R[i][tb] = 1; B[i][tb] = h[i].b * 100000 + h[i].sum; B[tb][i] = -B[i][tb];
		C[i][tc] = R[i][tc] = 1; B[i][tc] = h[i].c * 100000 + h[i].sum; B[tc][i] = -B[i][tc];		
	}

	C[ta][ed] = R[ta][ed] = a;
	C[tb][ed] = R[tb][ed] = b;
	C[tc][ed] = R[tc][ed] = c;
}

int cost;
bool inq[310];
int CT[310] , prev[310];

void path(){
	int i , j;
	bool modify;

	memset(inq , 0 , sizeof(inq));
	CT[st] = 0; inq[st] = 1;
	for(i=1; i<=ed; i++) CT[i] = -1000020000;
	
	while(1){
		modify = 0;

		for(i=0; i<ed; i++)
			if(inq[i]){
				if(i > 0 && i < ta){
					for(j=ta; j<=ed; j++)
						if(R[i][j] > 0 && CT[i] + B[i][j] > CT[j]){
							CT[j] = CT[i] + B[i][j];
							prev[j] = i;
							inq[j] = 1;
							modify = 1;
						}
				}
				else{
					for(j=0; j<=ed; j++)
						if(R[i][j] > 0 && CT[i] + B[i][j] > CT[j]){
							CT[j] = CT[i] + B[i][j];
							prev[j] = i;
							inq[j] = 1;
							modify = 1;
						}
				}
				inq[i] = 0;
			}

		if(! modify) break;
	}	

	cost += CT[ed];

	j = ed;
	while(j != st){
		i = prev[j];
		F[i][j] ++ ; F[j][i] = -F[i][j];
		R[i][j] = C[i][j] - F[i][j];
		R[j][i] = C[j][i] - F[j][i];

		j = i;
	}
}

void solve()
{
	int i;
	cost = 0;
	for(i=0; i<tot; i++){
		path();
	}

	printf("%d %d\n" , cost / 100000 , cost % 100000);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	int T;
	scanf("%d" , &T);
	
	while(T--)
	{
		init();
		build();
		solve();
	}

	return 0;
}
