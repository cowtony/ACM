#include <iostream>
#include <string>
using namespace std;

string name[70];
struct Ratio{
	int a , b;
} G[70][70];
int Len = 0;

Ratio f[70];
short color[70];

int findname(const string& str){
	for(int i=0; i<Len; i++)
		if(name[i] == str) return i;
	name[Len++] = str;
	return Len - 1;
}

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b , a % b);
}

void bfs(int s , int t){
	memset(f , 0 , sizeof(f));
	f[s].a = f[s].b = 1;
	memset(color , 0 , sizeof(color));
	color[s] = 1;

	int i , j , k;
	bool modify = true;
	while(modify){
		modify = false;
		for(i = 0; i < Len; i ++)
			if(color[i] == 1){
				color[i] = 2;
				for(j = 0; j < Len; j++)
					if ( color[j] == 0 && G[i][j].a > 0 ){
						color[j] = 1; modify = true;
						k = gcd(f[i].b , G[i][j].a);
						f[j].a = f[i].a * (G[i][j].a / k);
						f[j].b = G[i][j].b * (f[i].b / k);
						if(j == t){
							k = gcd(f[t].a , f[t].b);
							cout << f[t].a / k << " " << name[s] << " = " << f[t].b / k << " " <<  name[t] << endl;
							return;
						}
					}				
			}
	}		
	cout << "? " << name[s] << " = ? " << name[t] << endl;
}

int main(){
	//freopen("q1705.in" , "r" , stdin );
	//freopen("out.txt" , "w" , stdout );
	char mark;
	int m , n;
	int a , b , k;
	string A , B;	
	while(cin >> mark , mark != '.'){
		if(mark == '?'){
			cin >> A >> mark >> B;
			if(A == B){
				cout << "1 " << A << " = 1 " << B << endl;		
			}
			else{
				m = findname(A); n = findname(B);			
				bfs(m , n);
			}
		}
		else{
			cin >> a >> A >> mark >> b >> B;
			k = gcd(a , b);
			a /= k; b /= k;
			m = findname(A); n = findname(B);
			G[m][n].a = G[n][m].b = a;
			G[n][m].a = G[m][n].b = b;
		}
	}
	
	return 0;
}
