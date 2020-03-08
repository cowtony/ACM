#include <iostream.h>
#include <stdio.h>
#include <string.h>
const int len = 2001;
char s1[len],s2[len];
int l1,l2;

int f[len][len];
int n;int value[256];

void dp(){
	memset(f,0,sizeof(f));
	int i,j;
	for(i=0; i<l1; i++)
		if (s1[i] == s2[0])
			f[i][0] = value[s2[0]];
	for(i=0; i<l2; i++)
		if (s1[0] == s2[i])
			f[0][i] = value[s1[0]];
	for(i=1; i<l1; i++)
		for(j=1; j<l2; j++){
			if (s1[i] == s2[j]) f[i][j] = f[i-1][j-1] + value[s1[i]];
			if (f[i-1][j] > f[i][j]) f[i][j] = f[i-1][j];
			if (f[i][j-1] > f[i][j]) f[i][j] = f[i][j-1];			
		}
	cout <<f[l1-1][l2-1] << endl;
}

int main(){
	int i,k;
	char ch;
	while(cin >> n){
		memset(value,0,sizeof(value));
		for(i=1; i<=n; i++){
			cin >> ch >> k;
			value[ch] = k;
		}
		cin >> s1; l1 = strlen(s1);
		cin >> s2; l2 = strlen(s2);
		
		dp();
	}

	return 0;
}