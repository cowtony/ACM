#include <iostream>
#include <deque>
using namespace std;
int a[63][63][63];
int ans;

struct node
{
	int k2;
	int m2;
	int n2;
}p,q;

void solve(int k, int m, int n)
{
	deque <node> deq;
	p.k2 = 0;
	p.m2 = 0;
	p.n2 = 0;
	deq.push_back(p);
	a[0][0][0] = 2;
	while(!deq.empty())
	{
		p = deq.front();
		if(p.k2 >0)
		{
			q.k2 = p.k2 - 1;
			q.m2 = p.m2;
			q.n2 = p.n2;
			if(a[q.k2][q.m2][q.n2] == 0)
			{
				deq.push_back(q);
				a[q.k2][q.m2][q.n2] = 2;
			}
			else if(a[q.k2][q.m2][q.n2] == 1)
			{
				ans++;
			}
		}
		if(p.k2 < k-1)
		{
			q.k2 = p.k2 + 1;
			q.m2 = p.m2;
			q.n2 = p.n2;
			if(a[q.k2][q.m2][q.n2] == 0)
			{
				deq.push_back(q);
				a[q.k2][q.m2][q.n2] = 2;
			}
			else if(a[q.k2][q.m2][q.n2] == 1)
			{
				ans ++;
			}
		}
		if(p.m2 >0)
		{
			q.k2 = p.k2;
			q.m2 = p.m2 - 1;
			q.n2 = p.n2;
			if(a[q.k2][q.m2][q.n2] == 0)
			{
				deq.push_back(q);
				a[q.k2][q.m2][q.n2] = 2;
			}
			else if(a[q.k2][q.m2][q.n2] == 1)
			{
				ans ++;
			}
		}
		if(p.m2 < m-1)
		{
			q.k2 = p.k2;
			q.m2 = p.m2 + 1;
			q.n2 = p.n2;
			if(a[q.k2][q.m2][q.n2] == 0)
			{
				deq.push_back(q);
				a[q.k2][q.m2][q.n2] = 2;
			}
			else if(a[q.k2][q.m2][q.n2] == 1)
			{
				ans ++;
			}
		}
		if(p.n2 > 0)
		{
			q.k2 = p.k2;
			q.m2 = p.m2;
			q.n2 = p.n2 - 1;
			if(a[q.k2][q.m2][q.n2] == 0)
			{
				deq.push_back(q);
				a[q.k2][q.m2][q.n2] = 2;
			}
			else if(a[q.k2][q.m2][q.n2] == 1)
			{
				ans ++;
			}
		}
		if(p.n2 < n - 1)
		{
			q.k2 = p.k2;
			q.m2 = p.m2;
			q.n2 = p.n2 + 1;
			if(a[q.k2][q.m2][q.n2] == 0)
			{
				deq.push_back(q);
				a[q.k2][q.m2][q.n2] = 2;
			}
			else if(a[q.k2][q.m2][q.n2] == 1)
			{
				ans ++;
			}
		}
		deq.pop_front();
	}
}

int main()
{
	int k, m, n, l;
	int ACM;
	int ix, jx, kx;
	while( cin >> n >> m >> k >> l)
	{
		if(!n && !m && !k && !l) break;
		ans = 0;
		for(ix=0; ix<k+2; ix++)
		{
			for(jx=0; jx<m+2; jx++)
			{
				for(kx=0; kx<n+2; kx++)
				{
					a[ix][jx][kx] = 0;
				}
			}
		}
		for(ix=0; ix<l; ix++)
		{
			cin >> ACM;
			int k1, m1, n1;
			k1 = ACM/(m*n);
			ACM %= m*n;
			m1 = ACM / n;
			ACM %= n;
			n1 = ACM;
			a[k1+1][m1+1][n1+1] = 1;
		}
		solve(k+2, m+2, n+2);
		cout << "The number of faces needing shielding is " << ans << "." << endl;
	}
	return 0;
}