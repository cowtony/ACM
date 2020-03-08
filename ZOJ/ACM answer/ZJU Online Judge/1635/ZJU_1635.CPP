#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string pre1 = "        ";
string pre2 = "|       ";
string tmp;
string name[1001];
int c[1001];
int son[1001][11];
int size[1001];
int n;

void Init(int v){	
	c[v] = 0;
	if (name[v][0] != '*') return;
	char ch; cin >> ch;
	while(true){
		cin >> tmp;		
		if (tmp == ")") break;
		name[++n] = tmp;
		son[v][c[v]++] = n;
		cin >> size[n];
	}	
}
int Calc(int v){	
	for (int i=0; i < c[v]; i++)
		size[v] += Calc(son[v][i]);
	return size[v];
}

void print(int v,string pre,bool IsTail){
	cout << pre << "|_" << name[v] << "[" << size[v] << "]" << endl;
	for (int i=0; i < c[v]; i++){
		if (IsTail) print(son[v][i],pre + pre1,(i == c[v] - 1));
		else print(son[v][i],pre + pre2,(i == c[v] - 1));
	}
}

int main(){	
	int i;
	//freopen("in.txt","r",stdin);
	while(n=0,cin >> name[n] >> size[n]){				
		for(i=0; i<=n; i++)
			Init(i);
		Calc(0);
		cout << "|_" << name[0] << "[" << size[0] << "]" << endl;
		for (i=0; i < c[0]; i++)
			print(son[0][i],pre1,(i == c[0] - 1));		
	}

	return 0;
}
