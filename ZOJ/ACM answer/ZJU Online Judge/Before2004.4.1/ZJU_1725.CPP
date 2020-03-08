#include <iostream.h>

int n;
int List[30];
char op[30];
char x[20];

int W(char ch){
	if(ch == '+' || ch == '-') return 1;
	return 10;
}

void print(){
	cout << List[0];
	for(int i=1; i<n; i++)
		cout << " " << op[i] << " " << List[i];
	cout << " = " << x << endl;
}

void solve(){
	print();
	int k , w , i;
	while(n > 1){
		w = 0;
		for(i=1; i<n; i++)
			if(W(op[i]) > w){
				w = W(op[i]);
				k = i;
			}
		switch (op[k]){
		case '+':{ List[k-1] += List[k]; break; }
		case '-':{ List[k-1] -= List[k]; break; }
		case '*':{ List[k-1] *= List[k]; break; }
		case '/':{ List[k-1] /= List[k]; break; }
		}

		for(i=k; i<n-1; i++){
			List[i] = List[i+1];
			op[i] = op[i+1];
		}
		n--;

		print();
	}
}

int main(){
	char ch;
	bool first = true;
	while(cin >> List[0]){
		n = 1;
		while(cin >> ch){
			if(ch == '=') break;
			op[n] = ch;
			cin >> List[n++];
		}
		cin >> x;
		if(first) first = false; else cout << endl;
		solve();
	}	
	return 0;
}
