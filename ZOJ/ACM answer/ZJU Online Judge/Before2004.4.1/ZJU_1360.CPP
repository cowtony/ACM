#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const double eps = 1e-9;

int n;
double d;
struct segment{
	double x , y;
} List[1001];

bool operator < (const segment& a,const segment& b){
	return a.y <= b.y + eps;
}

int main(){
//freopen("in.txt" , "r" , stdin);
	int CaseNo = 0;
	int i , j;
	double x , y;
	int ret;
	bool Sol;
	while(scanf("%d %lf" , &n , &d) , n){
		Sol = true;
		for(i=0; i<n; i++){
			scanf("%lf %lf" , &x , &y);
			if (y > d){ Sol = false;  continue; }
			List[i].x = x - sqrt(d * d - y * y);
			List[i].y = x + sqrt(d * d - y * y);
		}
		if (! Sol){
			printf("Case %d: -1\n" , ++CaseNo); continue;
		}
		sort(&List[0] , &List[n]);		
		for(ret=i=0; i<n; ){
			ret++;
			for(j=i+1; j < n && List[j].x <= List[i].y + eps; j++){}
			i = j;
		}
		printf("Case %d: %d\n" , ++CaseNo , ret);
	}
	
	return 0;
}
