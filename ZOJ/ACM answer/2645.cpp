#include <iostream>
using namespace std;

int main()
{
	int flag[32][2];
	int a, b, c, d;
	int n, t;
	int i, j, index;
	int temp[] = {128, 64, 32, 16, 8, 4, 2, 1};
	while(scanf("%d",&n) != EOF)
	{
		memset(flag, -1, sizeof(flag));
		for(i=0; i<n; i++)
		{
			scanf("%d.%d.%d.%d",&a, &b, &c, &d);
			index = 0;
			t = 0;
			for(j=0; j<8; j++)
			{
				if(a >= temp[index])
				{
					a -= temp[index];
					if(flag[j][0] == -1) {flag[j][0] = 1; flag[j][1] = 1;}
					else if(flag[j][0] != 1 || t)
					{
						flag[j][1] = 0;
						t = 1;
					}
				}
				else
				{
					if(flag[j][0] == -1) {flag[j][0] = 0;flag[j][1] = 1;}
					else if(flag[j][0] != 0 || t)
					{
						flag[j][1] = 0;
						t = 1;
					}
				}
				index++;
			}
			index = 0;
			for(j=8; j<16; j++)
			{
				if(b >= temp[index])
				{
					b -= temp[index];
					if(flag[j][0] == -1) {flag[j][0] = 1; flag[j][1] = 1;}
					else if(flag[j][0] != 1 || t)
					{
						flag[j][1] = 0;
						t = 1;
					}
				}
				else
				{
					if(flag[j][0] == -1) {flag[j][0] = 0;flag[j][1] = 1;}
					else if(flag[j][0] != 0 || t)
					{
						flag[j][1] = 0;
						t = 1;
					}
				}
				index++;
			}
			index = 0;
			for(j=16; j<24; j++)
			{
				if(c >= temp[index])
				{
					c -= temp[index];
					if(flag[j][0] == -1) {flag[j][0] = 1; flag[j][1] = 1;}
					else if(flag[j][0] != 1 || t)
					{
						flag[j][1] = 0;
						t = 1;
					}
				}
				else
				{
					if(flag[j][0] == -1) {flag[j][0] = 0;flag[j][1] = 1;}
					else if(flag[j][0] != 0 || t)
					{
						flag[j][1] = 0;
						t = 1;

					}
				}
				index++;
			}
			index = 0;
			for(j=24; j<32; j++)
			{
				if(d >= temp[index])
				{
					d -= temp[index];
					if(flag[j][0] == -1) {flag[j][0] = 1; flag[j][1] = 1;}
					else if(flag[j][0] != 1 || t)
					{
						flag[j][1] = 0;
						t = 1;
					}
				}
				else
				{
					if(flag[j][0] == -1) {flag[j][0] = 0;flag[j][1] = 1;}
					else if(flag[j][0] != 0 || t)
					{
						flag[j][1] = 0;
						t = 1;
					}
				}
				index++;
			}
		}
		//for(i=0; i<32; i++) cout << flag[i][0] << " ";cout<<endl;
		//for(i=0; i<32; i++) cout << flag[i][1] << " ";cout << endl;
		index = 0;
		int ip[4] = {0};
		int ipmask[4] = {0};
		t = 0;
		for(i=0; i<8; i++)
		{
			if(flag[i][1])
			{
				ip[0] += temp[index] * flag[i][0];
				ipmask[0] += temp[index];
			}
			else { t = 1; break;}
			index++;
		}
		index = 0;
		if(!t)
		{
			for(i=8; i<16; i++)
			{
				if(flag[i][1])
				{
					ip[1] += temp[index] * flag[i][0];
					ipmask[1] += temp[index];
				}
				else {t=1; break;}
				index++;
			}
		}
		index = 0;
		if(!t)
		{
			for(i=16; i<24; i++)
			{
				if(flag[i][1])
				{
					ip[2] += temp[index] * flag[i][0];
					ipmask[2] += temp[index];
				}
				else {t=1; break;}
				index++;
			}
		}
		index = 0;
		if(!t)
		{
			for(i=24; i<32; i++)
			{
				if(flag[i][1])
				{
					ip[3] += temp[index] * flag[i][0];
					ipmask[3] += temp[index];
				}
				else {t=1; break;}
				index++;
			}
		}
		for(i=0; i<4; i++)
		{
			printf("%d",ip[i]);
			if(i==3) printf("\n");
			else printf(".");
		}
		for(i=0; i<4; i++)
		{
			printf("%d",ipmask[i]);
			if(i==3) printf("\n");
			else printf(".");
		}
	}
	return 0;
}
