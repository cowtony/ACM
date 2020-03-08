#include <iostream>
#include <cmath>
using namespace std;
int a[32768];

int main()
{
	int i, j, k, l;
	int n;
	int sq[182];
	for(i=0; i<182; i++)
	{
		sq[i] = i*i;
		a[i*i]++;
	}
	for(i=1; i<182; i++)
	{
		for(j=i; j<182; j++)
		{
			if(sq[i] + sq[j] > 32767) break;
			a[sq[i]+sq[j]]++;
			for(k=j; k<182; k++)
			{
				if(sq[i] + sq[j] + sq[k] > 32767) break;
				a[sq[i]+sq[j] + sq[k]]++;
				for(l=k; l<182; l++)
				{
					if(sq[i] + sq[j] + sq[k] + sq[l] > 32767) break;
					a[sq[i]+sq[j]+sq[k]+sq[l]]++;
				}
			}
		}
	}
	while(cin >> n && n)
	{
		cout << a[n] << endl;
	}
	return 0;
}