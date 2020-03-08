#include <iostream>
#include <string>
using namespace std;

struct node
{
	int p;
	long long val;
	string s;
}a[9];

void init()
{
	a[0].p = 11;  a[0].val = 2047;  a[0].s = "23 * 89";
	a[1].p = 23;  a[1].val = 8388607; a[1].s = "47 * 178481";
	a[2].p = 29; a[2].val = 536870911; a[2].s = "233 * 1103 * 2089";
	a[3].p = 37; a[3].val = 137438953471; a[3].s = "223 * 616318177";
	a[4].p = 41; a[4].val = 2199023255551; a[4].s = "13367 * 164511353";
	a[5].p = 43; a[5].val = 8796093022207; a[5].s = "431 * 9719 * 2099863";
	a[6].p = 47; a[6].val = 140737488355327; a[6].s = "2351 * 4513 * 13264529";
	a[7].p = 53; a[7].val = 9007199254740991; a[7].s = "6361 * 69431 * 20394401";
	a[8].p = 59; a[8].val = 576460752303423487; a[8].s = "179951 * 3203431780337";
}

int main()
{
	int n;
	int i, j;
	init();
	while(cin >> n)
	{
		for(i=8; i>=0; i--)
		{
			if(a[i].p <= n) break;
		}
		for(j=0; j<=i; j++)
		{
			cout << a[j].s << " = " << a[j].val << " = " << "( 2 ^ " << a[j].p << " ) - 1" << endl;
		}
	}
	return 0;
}