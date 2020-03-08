#include<iostream>//循环取模，得到的所有模数正好是一到模减一的所有数救输出Good Choice，否则Bad Choice
#include<cstdio>
using namespace std;
int main()
{
	int step,mod;
	int i,h,x,seek;
	int flag[100001];//标志数组这是我没有想到的
	while(scanf("%d%d",&step,&mod)!=EOF)
	{	
		x=0;
	
		for(i=0;i<mod;i++)
			flag[i]=0;//首先将一到模减一的标志置为0
		h=step%mod;//第一次取模先记录下来最为循环结束的标志
		flag[h]=1;//得到的模数标志为1
		seek=h;//赋值给第一个模数
		while((seek+step)%mod!=h)//开始循环
		{
			flag[(seek+step)%mod]=1;//得到的模数标志为一
			seek=(seek+step)%mod;
		} 
		for(i=0;i<mod;i++)
		{
			if(flag[i]!=1)//判断如果全部标志为1就满足条件，否则不满足
			{
				x=1;	
				break;
			}		
		}
		printf("%10d%10d",step,mod);//注意输出格式
		if(x==1)
			printf("    Bad Choice\n\n");
		else
			printf("    Good Choice\n\n");
	}
	return 0;
}
