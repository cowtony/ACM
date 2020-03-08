/*
一种游戏四人玩，两人一组。已知其中三人的输赢次数，求第四人的

因为每次玩都有两人输两人赢，所以每个人的输赢次数之和相等，为玩的局数
且四个人赢得次数等于输的次数
d1+d2=a1+a2;
a1+b1+c1+d1=a2+b2+c2+d2;
解出d1,d2即可

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int a1,a2,b1,b2,c1,c2,d1,d2;
    while(cin>>a1>>a2>>b1>>b2>>c1>>c2)
    {
        if(a1==0 && a2==0 && b1==0 && b2==0 && c1==0 && c2==0)break;
        
        int total=a1+a2;
        int minus=a2-a1+b2-b1+c2-c1;
        d1=(total+minus)/2;
        d2=(total-minus)/2;
        
        printf("Anna's won-loss record is %d-%d.\n",d1,d2);
    }
}
