/*
输入n，在1到n组成的圈中，由1开始每隔m剃掉一个数（包括1），要求最后一个被剃掉的是2，求满足此要求的最小m

首先m>1，对于给定的n，从二开始依次试即可
但是对于判断某一个m是否符合要求，网上有更简单的算法，我怎么想也想不明白。
以下就是那个不用数组的办法
若有人看到这个文件并且看懂了那个诡异的的for循环，一定要告诉我！！！
我的手机号是13572929215，在弄懂他之前我是不会换号的！
我不是抄答案的小人！！！ 
约瑟夫环？

关键词：巧算法，模拟 
*/
#include<iostream>
using namespace std;

bool judge_CGB(int n,int m)
{
    int r=0;
    
    for(int i=2;i<n;i++)
        r=(r+m)%i;//这就是最诡异的for！！！ 
        
    if(r==0)return true;
    else return false;
}

int main()
{ 
    int n,m;

    while(cin>>n)
    {
        if(n==0)return 0;         
    
        for(m=2;;m++)
            if(judge_CGB(n,m)==true)break;
        
        cout<<m<<endl;
    }
}
