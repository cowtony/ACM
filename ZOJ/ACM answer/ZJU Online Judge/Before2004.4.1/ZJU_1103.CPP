#include <iostream>
#include <string>
using namespace std;

int n , p1 , p2 , p3 , L;
char G[51][51];

struct Q_dat{
	int p1 , p2 , p3 , L;
} Q[50 * 50 * 50 / 3 + 1];
bool visited[51][51][51];

//每次只能走另外两个子之间连线的颜色

void visit(int p1 , int p2 , int p3){
	visited[p1][p2][p3] = true;
	visited[p1][p3][p2] = true;
	visited[p2][p1][p3] = true;
	visited[p2][p3][p1] = true;
	visited[p3][p1][p2] = true;
	visited[p3][p2][p1] = true;
}

int main(){
	int i , j;
	while(cin >> n , n){
		cin >> p1 >> p2 >> p3;
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++){
				cin >> G[i][j];
			}
		int head , tail;
		head = tail = 0;
		Q[0].p1 = p1; Q[0].p2 = p2; Q[0].p3 = p3; Q[0].L = 0;
		memset(visited , 0 , sizeof(visited));
		visit(p1 , p2 , p3);
		while(head <= tail){
			p1 = Q[head].p1;
			p2 = Q[head].p2;
			p3 = Q[head].p3;
			L  = Q[head].L ;
			if(p1 == p2 && p2 == p3) {
				cout << L << endl;
				break;
			}	
			for(i = 1; i<=n; i++){
				if(G[p1][i] == G[p2][p3] && !visited[i][p2][p3]){
					visit(i , p2 , p3);
					Q[++tail] = Q[head]; Q[tail].L ++;	Q[tail].p1 = i;
				}
				if(G[p2][i] == G[p1][p3] && !visited[p1][i][p3]){
					visit(p1 , i , p3);
					Q[++tail] = Q[head]; Q[tail].L ++;	Q[tail].p2 = i;
				}
				if(G[p3][i] == G[p1][p2] && !visited[p1][p2][i]){
					visit(p1 , p2 , i);
					Q[++tail] = Q[head]; Q[tail].L ++;	Q[tail].p3 = i;
				}
			}				
			
			head++;
		}
		if(head > tail) cout << "impossible" << endl;
	}
	return 0;
}