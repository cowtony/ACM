#include <iostream>
#include <string>
using namespace std;

int  n , m;
char map[201][201];
struct point{
	int x , y;
};
point Q[200 * 200 * 5];
point List[200 * 200 * 5];

int G[201][201];
int x0 , y0;
int head , tail , L;

bool step(int x , int y , int preLen){
	if(x < 0 || x >= n || y < 0 || y >= m) return 0;
	if(G[x][y] >= 0 || map[x][y] == '#') return 0;
	if(map[x][y] == 'x' || map[x][y] == 'X'){
		List[L].x = x; List[L].y = y; L++; return 0;
	}
	if(map[x][y] == 'r'){
		cout << preLen+1 << endl;
		return 1;
	}
	G[x][y] = preLen+1;
	++tail;
	Q[tail].x = x;
	Q[tail].y = y;
	return 0;
}

void solve(){
	memset(G , 255 , sizeof(G));
	G[x0][y0] = 0;
	Q[0].x = x0; Q[0].y = y0;
	head = tail = 0;
	
	int x , y;
	int i;
	L = 0;
	while(head <= tail){
		x = Q[head].x; y = Q[head].y; head++;
		if( step(x-1 , y , G[x][y]) ) return;
		if( step(x+1 , y , G[x][y]) ) return;
		if( step(x , y-1 , G[x][y]) ) return;
		if( step(x , y+1 , G[x][y]) ) return;
		if (head > tail || G[x][y] != G[Q[head].x][Q[head].y]){	
			for(i=0; i<L; i++){
				if(G[ List[i].x ][ List[i].y ] >= 0) continue;
				if (map[List[i].x ][ List[i].y] == 'r'){
					cout << G[x][y]+2 << endl; return;
				}
				Q[++tail] = List[i];
				G[ List[i].x ][ List[i].y ] = G[x][y] + 2;
			}
			L = 0;
		}
	}	
	
	cout << "Poor ANGEL has to stay in the prison all his life." <<endl;
}

int main(){
	//freopen("1001.in","r",stdin);	
	int i , j;
	while(cin >> n >> m){
		for(i=0; i<n; i++)				
			for(j=0; j<m; j++){			
				cin >> map[i][j];
				if(map[i][j] == 'a'){
					x0 = i; y0 = j;
				}			
			}

		solve();
		
	}
	
	return 0;
}
