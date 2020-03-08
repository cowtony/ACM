/*
输入区间[L,U]<=1000000，输出区间内距离最近的一组素数和距离最远的一组素数
若有多组解，输出较小的

用筛法存下1000000以内的素数表
再根据区间找出最近和最远的即可
这道题做麻烦了，本来直接初始化好1000000内的素数表就可以了，
但是这道题是对每次读入的数据都初始化好一个相应的素数表，不仅麻烦还慢，懒得改了 

关键词：数论 
*/
#include<iostream>
using namespace std;

long long prime[5000];//4792=pi(sqrt(2^31))
bool sieve[1000000];

void getprime(long max)
{
    long n=0;
    prime[n++]=2;
    for(long i=3;i<=max;i+=2)
    {
        for(long j=0;prime[j]*prime[j]<=i;j++)
            if(i%prime[j]==0)goto end;
        prime[n++]=i;
        end:;
    }
}//得到前4792的素数表 

long long get_start(long long left,long long prime)
{
    long long j=(prime-left%prime)%prime;//得到j的最先起始位置
    //while(j+left<prime*prime)j+=prime;//考虑起始真实值等于素数本身或为零的情况 
    if(j+left<prime*prime)return prime*prime-left;
    return j;
}

void init_sieve(long long left,long long right)
{
    memset(sieve,true,sizeof(sieve));//初始化筛 
    
    if(left==1)sieve[0]=false;//把0和1置为非素数  
    
    for(long i=0;prime[i]*prime[i]<=right;i++)//要筛的素数 
    {
        for(long j=get_start(left,prime[i]);j<=right-left;j+=prime[i])
            sieve[j]=false;//划掉prime[i]的倍数 
    }
}

bool find(long long size,long long &min1,long long &min2,long long &max1,long long &max2)
{
    long long max=0,min=200000000;
    long long temp,i;
    bool flag=false;
    
    for(i=0;i<=size;i++)if(sieve[i]==true){temp=i++;break;}//找到筛中的第一个素数 
    for(;i<=size;i++)
        if(sieve[i]==true)
        {
            if(i-temp<min){min=i-temp;min1=temp;min2=i;flag=true;}//找到更小的距离 
            if(i-temp>max){max=i-temp;max1=temp;max2=i;flag=true;}//找到更大的距离
            temp=i; 
        }
    
    return flag;
}

int main()
{
    getprime(47000);//46340=sqrt(2^31)

    long long l,u;
    while(cin>>l>>u)
    {
        init_sieve(l,u);//把l与u之间的素数筛出来 

        long long min1,min2,max1,max2;
        if(find(u-l,min1,min2,max1,max2)==true)//找出最小相邻和最大相邻 
            cout<<min1+l<<","<<min2+l<<" are closest, "<<max1+l<<","<<max2+l<<" are most distant."<< endl;
        else cout<<"There are no adjacent primes."<<endl;
    }
    
    return 0;
}
