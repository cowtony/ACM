#include <iostream>
using namespace std;


int main()
{
	char ch[100][100];
	int ai[12][12];
	int n;
	int cas=1;
	while(cin >> n && n)
	{
		if(cas!=1)
			cout << endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin >> ai[i][j];
			}
		}
		cout << "Case " << cas++ << ":" << endl << endl;
		memset(ch, '0', sizeof(ch));
		for(int i=0; i<n; i++)
		{
			if(ai[0][i] == 0)
			{
				ch[0][i*4+2] = 'O';
				ch[1][i*4+2] = '|';
				ch[2][i*4+2] = 'H';
				if(i*4>=0 && ch[0][i*4] == '0')
				{
					ch[0][i*4+1] = '-';
					ch[0][i*4] = 'H';
				}
				else
				{
					ch[0][i*4+3] = '-';
					ch[0][i*4+4] = 'H';
				}
			}
			else if(ai[0][i] == 1)
			{
				ch[0][i*4+2] = 'O';
				ch[0][i*4+1] = '-';
				ch[0][i*4+3] = '-';
				ch[0][i*4] = 'H';
				ch[0][i*4+4] = 'H';
			}
		}
		for(int i=1; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(ai[i][j] == 1)
				{
					ch[i*4][j*4+2] = 'O';
					ch[i*4][j*4+1] = '-';
					ch[i*4][j*4+3] = '-';
					ch[i*4][j*4] = 'H';
					ch[i*4][j*4+4] = 'H';
				}
				else if(ai[i][j] == -1)
				{
					ch[i*4][j*4+2] = 'O';
					ch[i*4-1][j*4+2] = '|';
					ch[i*4+1][j*4+2] = '|';
					ch[i*4-2][j*4+2] = 'H';
					ch[i*4+2][j*4+2] = 'H';
				}
				else
				{
					ch[i*4][j*4+2] = 'O';
					if(ch[i*4][j*4] == '0')
					{
						ch[i*4][j*4+1] = '-';
						ch[i*4][j*4] = 'H';
					}
					else
					{
						ch[i*4][j*4+3] = '-';
						ch[i*4][j*4+4] = 'H';
					}
					if(ch[i*4-2][j*4+2] == '0')
					{
						ch[i*4-1][j*4+2] = '|';
						ch[i*4-2][j*4+2] = 'H';
					}
					else
					{
						ch[i*4+1][j*4+2] = '|';
						ch[i*4+2][j*4+2] = 'H';
					}
				}
			}
		}
		for(int i=0; i<4*n+3; i++)
		{
			cout << "*";
		}
		cout << endl;
		for(int i=0; i<4*(n-1)+1; i++)
		{
			cout << "*";
			for(int j=0; j<4*n+1; j++ )
			{
				if(ch[i][j] != '0') cout << ch[i][j];
				else cout << " ";
			}
			cout << "*" << endl;
		}
		for(int i=0; i<4*n+3; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}