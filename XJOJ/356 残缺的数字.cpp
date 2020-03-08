/*
1~n中少了一个数，现在知道0~9这些数位在前面出现的次数，求n和少了的那个数

先根据所给数位求出n的最小值
因为少的那个数不会大于1000，所以遍历到它加三就行了
假设好了n以后，求出1~n的0~9数位，和题目所给相减
再遍历1~n看有没有数字可以构成这个差，有则输出

关键词：数学题 
*/
#include<iostream>
using namespace std;

int num(int x)
{
    if(x<10)return x;
    else if(x<190)return (x-9)/2+10;
    else if(x<2890)return (x-189)/3+100;
    else return (x-2889)/4+1000;
}

void count(int x,int p[])
{
    int t;
    memset(p,0,10*sizeof(p[0]));
    
    for(int i=1;i<=x;i++)
    {
        t=i;
        while(t>0)
            p[t%10]++,t/=10;
    }
} 

bool judge(int x,int p[])
{
    int q[10]={0};
    
    while(x>0)
    {
        q[x%10]++;
        x/=10;
    }
    for(int i=0;i<10;i++)
        if(p[i]!=q[i])return false;

    return true;
}//判断x的各位是否和p数组一样 

int main()
{   
    int digit[10],real[10],sum=0;
    bool solution=false;
    for(int i=0;i<10;i++)
    {
        cin>>digit[i];
        sum+=digit[i];
    }//输入 
    
    for(int i=num(sum);i<num(sum)+3;i++)
    {
        count(i,real);
        for(int j=0;j<10;j++)
        {
            real[j]-=digit[j];
            if(real[j]<0)goto end;
        }
        
        for(int j=1;j<=i;j++)
            if(judge(j,real)==true)
            {
                cout<<i<<' '<<j<<endl;
                solution=true;
            }
        end:;
    }
    if(solution==false)cout<<"NO ANSWER";
    //while(1);
}
