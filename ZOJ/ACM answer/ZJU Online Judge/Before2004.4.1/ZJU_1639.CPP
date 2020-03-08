#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;


int n,m;
struct dat{
	string name;
	int p;
};
dat List[20];
int check[1025];
int tot[20];

string tmp,tmp2;
int best;

bool datcomp(dat a, dat b){
	return (a.p >= b.p);
}

void Search(int k,int sum,int L){
	if (k == n){
		if ( sum > best ) best = sum;
		return;
	}
	if (sum + tot[k] < best) return;
	int i,tL = L + (1 << k);
	for (i=0; i<m; i++)
		if ((tL & check[i]) == check[i]) {
			tL = -1;
			break;
		}
	if (tL > 0) Search(k + 1,sum + List[k].p,tL);
	Search(k + 1, sum, L);
}

int main(){
	int i,j;
	int CaseNo = 0;

	freopen("in.txt","r",stdin);
	while (cin >> n, n){
		for(i=0; i<n; i++){
			cin >> List[i].name >> List[i].p;
		}
		sort(&List[0],&List[n],datcomp);
		tot[n-1] = List[n-1].p;

		for(i=n-2; i>=0; i--)
			tot[i] = tot[i+1] + List[i].p;

		cin >> m;

		getline(cin,tmp);
		memset(check,0,sizeof(check));

		for(i=0; i<m; i++){
			getline(cin,tmp);
			istringstream strin(tmp);	

			while (strin >> tmp2){
				for(j=0; j<n; j++)
				if (List[j].name == tmp2){
					check[i] += 1 << j;
					break;
				}
			}
		}

		best = List[0].p;
		Search(0,0,0);

		cout << "System " << ++CaseNo << ": " << best << endl;
	}
	return 0;
}