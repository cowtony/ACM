#include <iostream>
#include <algorithm>
using namespace std;

char map[10][10];
int x1,y1,x2,y2;

bool check(){
	if (   x1 < 1 || x2 < 1 || y1 < 1 || y2 < 1
		|| x1 > 8 || x2 > 8 || y1 > 8 || y2 > 8) return 0;
	if(abs(x1-x2)+abs(y1-y2)!=1) return 0; 
	swap(map[--x1][--y1],map[--x2][--y2]);
	int i,j;
	for(i=1; i<=6; i++)
		for(j=0; j<8; j++)
			if (map[i-1][j] == map[i][j] && map[i][j] == map[i+1][j]) return 1;
	
	for(i=0; i<8; i++)
		for(j=1; j<=6; j++)
			if (map[i][j-1] == map[i][j] && map[i][j] == map[i][j+1]) return 1;
	return 0;	
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	
	while (cin >> map[0][0]){
		for(i=1; i<8; i++) cin >> map[0][i];
		for(i=1; i<8; i++)
			for(j=0; j<8; j++)
				cin >> map[i][j];
		cin >> x1 >> y1 >> x2 >> y2;				
		if (check()) cout << "Ok!" << endl;
		else cout << "Illegal move!" << endl;
	}
	return 0;
}