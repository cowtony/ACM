#include <stdio.h>
#include <string.h>

int n , m;
struct point{
	short D[10];
};
struct edge{
	point p1 , p2;
	bool used ;
} List[200];

point Q[20000];

point p1 , p2;

bool Eq_point(const point& a , const point& b){
	for(int i=0; i<n; i++)
		if(a.D[i] != b.D[i]) return 0;
	return 1;
}

bool Bfs(){
	if(Eq_point(p1 , p2)) return 1;
	int head , tail , i;
	head = tail = 0;
	Q[0] = p1;	
	point p;
	while(head <= tail){
		p = Q[head++];
		for(i = 0; i<m; i++)
			if(!List[i].used && Eq_point(p , List[i].p1)){
				if ( Eq_point(p2 , List[i].p2) )return 1;
				Q[++tail] = List[i].p2;
				List[i].used = 1;
			}else if(Eq_point(p , List[i].p2)){
				if ( Eq_point(p2 , List[i].p1) )return 1;
				Q[++tail] = List[i].p1;
				List[i].used = 1;
			}
	}
	return 0;
}

int main(){
	//freopen("in.txt" , "r" , stdin);
	int CaseNo = 0;
	int i , k;
	while(scanf("%d", &n) , n){
		printf("Maze #%d " , ++CaseNo);
		m = 0;
		for(i = 0;  i < n; i++)
			scanf("%d" , &p1.D[i]);
		for(i = 0;  i < n; i++)
			scanf("%d" , &p2.D[i]);

		while(scanf("%d" ,&k) , k >= 0){
			List[m].p1.D[0] = k;
			List[m].used = 0;
			for(i = 1;  i < n; i++)
				scanf("%d" , &List[m].p1.D[i]);
			for(i = 0;  i < n; i++)
				scanf("%d" , &List[m].p2.D[i]);

			m++;
		}


		if (Bfs()) printf("can be travelled\n");
		else printf("cannot be travelled\n");		
	}	
	
	return 0;
}
