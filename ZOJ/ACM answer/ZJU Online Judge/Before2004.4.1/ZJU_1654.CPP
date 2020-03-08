#include <iostream.h>
#include <stdio.h>
int n , m;
char G[51][51];

int test(int x0 , int y0){
	int x , y;
	int ret = -3;
	x = x0 , y = y0;
	while(x < n && G[x][y] != '#'){		
		if(G[x][y] =='o') ret++;
		x++;
	}
	x = x0 , y = y0;
	while(x >= 0 && G[x][y] != '#'){		
		if(G[x][y] =='o') ret++;
		x--;
	}
	x = x0 , y = y0;
	while(y >= 0 && G[x][y] != '#'){		
		if(G[x][y] =='o') ret++;
		y--;
	}
	x = x0 , y = y0;
	while(y < m && G[x][y] != '#'){		
		if(G[x][y] =='o') ret++;
		y++;
	}
	return ret;
}

void paint(int x0 , int y0){
	int x , y;
	x = x0 , y = y0;
	while(x < n && G[x][y] != '#'){		
		G[x][y] = 'X';
		x++;
	}
	x = x0 , y = y0;
	while(x >= 0 && G[x][y] != '#'){		
		G[x][y] = 'X';
		x--;
	}
	x = x0 , y = y0;
	while(y >= 0 && G[x][y] != '#'){		
		G[x][y] = 'X';
		y--;
	}
	x = x0 , y = y0;
	while(y < m && G[x][y] != '#'){		
		G[x][y] = 'X';
		y++;
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	int T , CaseNo;
	int Count;

	int i , j , min , x , y , ret;
	cin >> CaseNo;
	for(T = 1; T <= CaseNo; T++){
		cout << "Case :" << T << endl;
		cin >> n >> m;
		for(i=0; i<n; i++)
			cin >> G[i];
		Count = 0;
		// '#', '*', or 'o' which represent Wall, Grass, and Empty
		while(true){
			min = 1000000;
			for(i=0; i<n; i++)
				for(j=0; j<n; j++)
					if(G[i][j] == 'o'){
						ret = test(i , j);
						if (ret < min)
						{
							min = ret;
							x = i ;  y = j;
						}
					}
			if(min == 1000000) break;
			paint( x , y );
			Count++;
		}
		cout << Count << endl;

	}
	
	
	return 0;
}
