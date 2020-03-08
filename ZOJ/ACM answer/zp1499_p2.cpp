//#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define N 100
using namespace std;

double cmpt(char * segment,int begin,int end);

int main() {
	//ifstream in("Icrease_sequence.in");
	//ofstream out("is.out");
	double v[N][N],f[N],g[N],value;
	int mark[N],i,j,length,n,end;//,top;
	char s[N];//,stk[N];
    
	while(1) {
		cin>>s + 1;
		n = strlen(s + 1);
		if(s[1] == '0' && n < 2) break;
		for(j = 1; j <= n; j++) {
			for(i = j; i <= n; i++) {
				v[j][i] = v[i][j] = -1;
			}
		}
		f[0] = 0;
		for(j = 1; j <= n; j++) {
			for(i = 1; ; i++) {
				if(v[j - i + 1][j] < 0) v[j- i + 1][j] = value = cmpt(s,j - i + 1,j);
				else value = v[j - i + 1][j];
				if(value > f[j - i]) break;
			}
			f[j] = value;
			mark[j] = j - i;
		}
//////////////////////////////////////////////////// the mark[] record position ',' following 
		length = n - (end = mark[n]);
		g[end + 1] = f[n];
		mark[end + 1] = n;
		for(j = end; j > 0; j--) {
			if(s[j] == '0') {
				g[j] = g[j + 1];
				mark[j] = mark[j + 1];
				continue;
			}
			for(length > end - j + 1 ? i = end - j + 1 : i = length; i > 0; i--) {
				if(v[j][j + i - 1] < 0) v[j][j + i - 1] = value = cmpt(s,j,j + i - 1);
				else value = v[j][j + i - 1];
				if(value < g[j + i]) break;
			}
			g[j] = value;
			mark[j] = j + i - 1;//////// ',' is after mark[j];
		}
		j = mark[1];
		for(i = 1; i <= n; i++) {
			cout<<s[i];		
			if(i == j && j <= end) {
				cout<<',';
				j = mark[j + 1];
			}
		}
		cout<<endl;
	}
	return 0;
}
double cmpt(char * segment,int begin,int end) {
	int i = 0;
	char work[N];
	for(; begin <= end; begin++) work[i++] = segment[begin];
	work[i] = '\0';
	return atof(work);
}

/*		j = mark[n];
		top = 0;
		for(i = n; i > 0; i--) {
			if(i == j) {
				stk[top++] = ',';
				j = mark[j];
			}
			stk[top++] = s[i];
		}
		for(i = top - 1; i >=0; i--) cout<<stk[i];
		cout<<endl;
*/

