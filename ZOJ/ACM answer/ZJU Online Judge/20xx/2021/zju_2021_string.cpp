#include <iostream>
#include <string>
using namespace std;

string s;

int right(string s , int i)
{
	int cnt = 0;
	for(;;i++)
	{
		if(s[i] == '(') cnt++;
		if(s[i] == ')') cnt--;
		if(cnt==0) return i;
	}
}

int find_mid(string s)
{
	int k , i;
	k = -1;
	for(i=0; i<s.length();)
	{
		if(s[i] == '+' || s[i] == '-') k=i;
		if(s[i] == '(') i = right(s , i);
		if((s[i] == '*' || s[i] == '/') && (k<0 || (s[k]=='*' || s[k] == '/'))) k=i;
		i++;
	}
	return k;
}

string solve(string s , char& op)
{
	if(s.length() == 1){ op = '#'; return s; }
	if(s[0] == '(' && right(s , 0) + 1 == s.length())
	{
		return solve(s.substr(1,s.length()-2) , op);
	}
	char p , r;
	int k;
	k = find_mid(s); op = s[k];
	string left = solve(s.substr(0,k) , p);
	string right = solve(s.substr(k+1,s.length()-1-k) , r);
	if((op=='*'||op=='/') && (p=='+'||p=='-')) left = '('+left+')';
	if((op=='*'||op=='-') && (r=='+'||r=='-')) right = '('+right+')';
	else if(op == '/' && r != '#') right = '('+right+')';
	return left + op + right;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		cin >> s;
		char op;
		cout << solve(s , op) << endl;
	}

	return 0;
}