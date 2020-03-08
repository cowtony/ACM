#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[1005];
	int ai[2][1001];
	int cas=1;
	while(scanf("%s", str) != EOF)
	{
		int a=0;
		int b=0;
		int i=0;
		int len = strlen(str);
		do{
			ai[0][i] = a;
			ai[1][i] = b;
			if(i==len)
				break;
			if(str[i] == 'a')
				a++;
			else b++;
			i++;
		}while(1);
		printf("AB Circle #%d:\n", cas++);
		for(int i=0; i<len-1; i++)
		{
			int indexx=i+1;
			int aa=ai[0][indexx]-ai[0][i];
			int bb=ai[1][indexx]-ai[1][i];
			int right1=b-bb;
			int right2=a-aa;
			do{
				if(aa==right1 || bb==right2)
				{
					printf("%d,%d\n", i, indexx);
				}
				if(aa>=right1 && bb>=right2)
					break;
				int num=100000;
				if(right1>aa && (right1-aa)<num)
					num = right1-aa;
				if(right2>bb && (right2-bb)<num)
					num = right2-bb;
				if(indexx+num>=len)
					break;
				indexx+=num;
				aa = ai[0][indexx]-ai[0][i];
				bb = ai[1][indexx]-ai[1][i];
				right1 = b-bb;
				right2=a-aa;
			}while(1);
		}
		printf("\n");
	}
	return 0;
}