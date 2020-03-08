#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str[8];
	char s[10];
	int i, j, k, l;
	char c;
	int sp, cz, zx, yx;
	int p = 0;
	while(cin >> str[0])
	{
		if(p==0) p=1;
		else cout <<endl;
		deque <string> hello;
		for(i=1; i<8; i++)
		{
			cin >> str[i];
		}
		while(cin >> c)
		{
			if(c=='X' || c=='O') break;
		}
		for(i=0; i<8; i++)
		{
			for(j=0; j<8; j++)
			{
				if(str[i][j] == c)
				{
					sp = cz = zx = yx = 0;
					for(k=0; k<8; k++)
					{
						if(str[k][j] == 'X' || str[k][j] == 'O') 
						{
							cz++;
						}
					}
					for(k=0; k<8; k++)
					{
						if(str[i][k] == 'X' || str[i][k] == 'O')
						{
							sp++;
						}
					}
					for(k=i, l=j; k>=0&&l>=0; k--, l--)
					{
						if(str[k][l] == 'X' || str[k][l] == 'O') yx++;
					}
					for(k=i, l=j; k<8&&l<8; k++, l++)
					{
						if(str[k][l] == 'X' || str[k][l] == 'O') yx++;
					}
					yx--;
					for(k=i, l=j; k>=0&&l<8; k--, l++)
					{
						if(str[k][l] == 'X' || str[k][l] == 'O') zx++;
					}
					for(k=i, l=j; k<8&&l>=0; k++, l--)
					{
						if(str[k][l] == 'X' || str[k][l] == 'O') zx++;
					}
					zx--;
					int count = -1;
					for(k=i, l=j; k>=0&&l>=0; k--,l--)
					{
						count++;
						if(count == yx && str[k][l] != c)
						{
							s[0] = i+65;
							s[1] = j+49;
							s[2] = '-';
							s[3] = k+65;
							s[4] = l+49;
							s[5] = '\0';
							string ss(s);
							hello.push_back(ss);
						}
						else if(str[k][l] != c && str[k][l] != '.')  break;
					}
					count = -1;
					for(k=i; k>=0; k--)
					{
						count++;
						if(count == cz && str[k][j] != c)
						{
							s[0] = i+65;
							s[1] = j+49;
							s[2] = '-';
							s[3] = k+65;
							s[4] = j+49;
							s[5] = '\0';
							string ss(s);
							hello.push_back(ss);
						}
						else if(str[k][j] != c && str[k][j] != '.') break;
					}
					count = -1;
					for(k=i, l=j; k>=0&&l<8; k--, l++)
					{
						count++;
						if(count == zx && str[k][l] != c)
						{
							s[0] = i+65;
							s[1] = j+49;
							s[2] = '-';
							s[3] = k+65;
							s[4] = l+49;
							s[5] = '\0';
							string ss(s);
							hello.push_back(ss);
						}
						else if(str[k][l] != c && str[k][l] != '.')  break;
					}
					count = -1;
					for(k=j; k>=0; k--)
					{
						count++;
						if(count == sp && str[i][k] != c)
						{
							s[0] = i+65;
							s[1] = j+49;
							s[2] = '-';
							s[3] = i+65;
							s[4] = k+49;
							s[5] = '\0';
							string ss(s);
							hello.push_back(ss);
						}
						else if(str[i][k] != c && str[i][k] != '.') break;
					}
					count = -1;
					for(k=j; k<8; k++)
					{
						count++;
						if(count == sp && str[i][k] != c)
						{
							s[0] = i+65;
							s[1] = j+49;
							s[2] = '-';
							s[3] = i+65;
							s[4] = k+49;
							s[5] = '\0';
							string ss(s);
							hello.push_back(ss);
						}
						else if(str[i][k] != c && str[i][k] != '.') break;
					}
					count = -1;
					for(k=i, l=j; k<8&&l>=0; k++, l--)
					{
						count++;
						if(count == zx && str[k][l] != c)
						{
							s[0] = i+65;
							s[1] = j+49;
							s[2] = '-';
							s[3] = k+65;
							s[4] = l+49;
							s[5] = '\0';
							string ss(s);
							hello.push_back(ss);
						}
						else if(str[k][l] != c && str[k][l] != '.') break;
					}
					count = -1;
					for(k=i; k<8; k++)
					{
						count++;
						if(count == cz && str[k][j] != c)
						{
							s[0] = i+65;
							s[1] = j+49;
							s[2] = '-';
							s[3] = k+65;
							s[4] = j+49;
							s[5] = '\0';
							string ss(s);
							hello.push_back(ss);
						}
						else if(str[k][j] != c && str[k][j] != '.') break;
					}
					count = -1;
					for(k=i, l=j; k<8&&l<8; k++, l++)
					{
						count ++;
						if(count == yx && str[k][l] != c)
						{
							s[0] = i+65;
							s[1] = j+49;
							s[2] = '-';
							s[3] = k+65;
							s[4] = l+49;
							s[5] = '\0';
							string ss(s);
							hello.push_back(ss);
						}
						else if(str[k][l] != c && str[k][l] != '.') break;
					}
				}
			}
		}
		if(hello.empty())
		{
			cout << "No moves are possible" << endl;
			continue;
		}
		sort(hello.begin(), hello.end());
		for(i=0; i<hello.size(); i++)
		{
			cout << hello[i] << endl;
		}
	}
	return 0;
}