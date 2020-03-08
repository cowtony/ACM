#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n;
int L[30],tL[30];

int root[30];
int Count;

bool check( int x ){
	int ret = 0,power = 1;
	for(int i=0; i<=n; i++){
		ret += power * L[i];
		power *= x;
	}
	return (ret == 0);
}

void DIV(int c){
	int i;
	for (i=n; i>0; i--){
		tL[i-1] = L[i];
		L[i-1] += (c * L[i]);
	}
	memcpy(L,tL,sizeof(L));
	n--;	
}

int main(){
	//freopen("in.txt","r",stdin);
	int CaseNO;
	int i,x,tx;
	cin >> CaseNO;
	while (CaseNO--){
		cin >> n;
		for(i=n; i>=0; i--){
			cin >> L[i];
		}
		
		Count = 0;
		while(true){
			if(L[0] == 0){			
				root[Count++] = 0;
				for(i=0; i<n; i++)
					L[i] = L[i+1];
			}
			bool tmp = false;
			for(x=1; x<=sqrt(abs(L[0])); x++)
			if(abs(L[0]) % x == 0){
				if (check(x)){
					root[Count++]=x;
					DIV(x); tmp = true; break;
				};
				tx = abs(L[0]) / x;
				if (check(tx)){
					root[Count++]=tx;
					DIV(tx); tmp = true;break; 
				};
				tx = -x;
				if (check(tx)){
					root[Count++]=tx;
					DIV(tx);tmp = true;break; 
				};
				tx = -abs(L[0]) / x;
				if (check(tx)){
					root[Count++]=tx;
					DIV(tx);tmp = true; break; 
				};
			}
			if (!tmp) break;
			if (n == 0) break;
		}
		if (Count==0) cout << "NIR" << endl;
		else{
			sort(&root[0],&root[Count]);
			for(i=0; i<Count-1; i++) cout << root[i] << " ";
			cout << root[Count-1] << endl;
		}
	}

	return 0;
}