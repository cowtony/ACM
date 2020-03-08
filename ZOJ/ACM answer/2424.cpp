#include <iostream>
using namespace std;

int ans[101][70];
int mul[70];

void multi(int  i, int j)
{
	memset(mul, 0, sizeof(mul));
	int bit;
	int k;
	for(k=1; k<=ans[i][0]; k++)
	{
		int carry = 0;
		bit = k;
		for(int l=1; l<=ans[j][0]; l++)
		{
			mul[bit++] += ans[i][k] * ans[j][l];
		}
	}
	int carry = 0;
	for(k=1; k<bit; k++)
	{
		carry = mul[k] + carry;
		mul[k] = carry % 10;
		carry /= 10;
	}
	while(carry)
	{
		mul[k++] = carry % 10;
		carry /= 10;
	}
	mul[0] = k-1;
}

int main()
{
	int i, j, k;
	int n;
	memset(ans, 0, sizeof(ans));
	ans[0][0] = ans[0][1] = 1;
	ans[1][0] = ans[1][1] = 1;
	ans[2][0] = 1;
	ans[2][1] = 2;
	for(i=3; i<=100; i++)
	{
		for(j=0; j<i; j++)
		{
			multi(j, i-j-1);
			int temp = mul[0] > ans[i][0] ? mul[0] : ans[i][0];
			int carry = 0;
			for(k=1; k<=temp; k++)
			{
				carry = carry + mul[k] + ans[i][k];
				ans[i][k] = carry % 10;
				carry /= 10;
			}
			if(carry) ans[i][k++] = carry;
			ans[i][0] = k-1;
		}
	}
	while( cin >> n && n != -1)
	{
		for(i=ans[n][0]; i>0; i--)
		{
			cout << ans[n][i];
		}
		cout << endl;
	}
	return 0;
}