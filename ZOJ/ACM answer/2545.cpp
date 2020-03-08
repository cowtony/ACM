#include <iostream>
#include <cmath>
using namespace std;

//pro1
int main()
{
	int n;
	//freopen("D:\\in.txt", "r", stdin);
	//freopen("D:\\out.txt","w", stdout);
	while(cin >> n && n)
	{
		double times = (double)((n-1960)/10 + 2);
		times = pow(2.0, times);
		double pk = 0;
		double i;
		for(i=1.0; ; i++)
		{
			pk += log(i)/log(2.0);
			if(pk>times)
				break;
		}
		int ans = i-1;
		cout << ans << endl;
	}
	return 0;
}

//pro2
int main()
{
	int a[] = {3,5,8,12,20,34,57,98,170,300,536,966,1754,3210,5910,10944,20366,38064,71421,134480,254016};
	int n;
	while(scanf("%d", &n) && n)
	{
		int times = (n-1960)/10;
		printf("%d\n", a[times]);
	}
	return 0;
}
