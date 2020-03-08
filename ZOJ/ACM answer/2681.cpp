#include <iostream>
#include <cmath>
#include <deque>
#define le 10e-6
using namespace std;


int main()
{
	double p, q;
	int i;
	double x1, y1, x2, y2;
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		deque <int> cici;
		scanf("%lf%lf", &p, &q);
		x1 = y1 = 2.0;
		int t = 0;
		int flag = 0;
		int goal=0;
		while(1)
		{
			if(fabs(x1) < le && fabs(y1) < le) {goal = 1; break;}
			if(fabs(x1) < le && fabs(y1-1) < le) {goal = 4; break;}
			if(fabs(x1-1) < le && fabs(y1) < le) {goal = 2; break;}
			if(fabs(x1-1) < le && fabs(y1-1) < le) {goal = 3; break;}
			if(flag == 0) {flag = 1; x1=y1=0;}
			if(!t)
			{
				t=1;
				double b = q*y1 - p*x1;
				x2 = 0;
				y2 = b/q;
				if(y2 > -10e-6 && y2 < 1.0+le && (fabs(x2-x1) > le || fabs(y2-y1) > le))
				{
					x1 = x2;
					y1 = y2;

					cici.push_back(4);
					continue;
				}
				x2 = 1;
				y2 = (p+b)/q;
				if(y2 > -10e-6 && y2 < 1.0+le && (fabs(x2-x1) > le || fabs(y2-y1) > le))
				{
					x1 = x2;
					y1 = y2;
					cici.push_back(2);
					continue;
				}
				y2 = 0;
				x2 = -(b/p);
				if(x2 > -10e-6 && x2 < 1.0+le && (fabs(x2-x1) > le || fabs(y2-y1) > le))
				{
					x1 = x2;
					y1 = y2;
					cici.push_back(1);
					continue;
				}
				y2 = 1;
				x2 = (q-b)/p;
				if(x2 > -10e-6 && x2 < 1.0+le && (fabs(x2-x1) > le || fabs(y2-y1) > le))
				{
					x1 = x2;
					y1 = y2;
					cici.push_back(3);
					continue;
				}
			}
			else
			{
				t = 0;
				double b = q*y1 + p*x1;
				x2 = 0;
				y2 = b/q;
				if(y2 > -10e-6 && y2 < 1.0+le && (fabs(x2-x1) > le || fabs(y2-y1) > le))
				{
					x1 = x2;
					y1 = y2;
					cici.push_back(4);
					continue;
				}
				x2 = 1;
				y2 = (b-p)/q;
				if(y2 > -10e-6 && y2 < 1.0+le && (fabs(x2-x1) > le || fabs(y2-y1) > le))
				{
					x1 = x2;
					y1 = y2;
					cici.push_back(2);
					continue;
				}
				y2 = 0;
				x2 = b/p;
				if(x2 > -10e-6 && x2 < 1.0+le && (fabs(x2-x1) > le || fabs(y2-y1) > le))
				{
					x1 = x2;
					y1 = y2;
					cici.push_back(1);
					continue;
				}
				y2 = 1;
				x2 = (b-q)/p;
				if(x2 > -10e-6 && x2 < 1.0+le && (fabs(x2-x1) > le || fabs(y2-y1) > le))
				{
					x1 = x2;
					y1 = y2;
					cici.push_back(3);
					continue;
				}
			}
		}
		if(cici.size() == 1)
		{
			cout << 0 << endl << 3 << endl;
		}
		else
		{
			cout << cici.size()-1 << endl;
			for(i=0; i<cici.size()-1; i++)
			{
				if(cici[i] == 1) cout << "S ";
				else if(cici[i] == 2) cout << "E ";
				else if(cici[i] == 3) cout << "N ";
				else cout << "W ";
			}
			cout << goal << endl;
		}
	}
	return 0;
}


