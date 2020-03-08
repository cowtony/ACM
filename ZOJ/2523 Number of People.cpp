/*
输入n，输出包含1和n本身有n个因数的最小数字。用质因数的幂的表示法

把题意化为上述题目是一个小难点
然后要明白，假设n=12，那么2^11这个数就仅有12个因数(2^0到2^11)
但是它不是最小的，2^2*3^1*5^1是更小的一个解（他们的幂的组合有3*2*2种，正好是12个因数）
也就是说，把n分解成几个数的乘积，然后分别减1作为一堆底数的指数
需要注意的是底数必须是质数，而且越大的指数应该给越小的底数，比如2^2*3^1*5^1<5^2*3^1*2^1
但是也不一定完全把n分解后得到的数字最小，比如n=8=2*2*2=4*2，但是2^3*3^1<2^1*3^1*5^1
所以只能遍历n的所有相乘可能，然后找出值最小的一组解
对它取ln是求值的简单方法，比如n=8时，有ln(2^3*3^1)=3ln2+ln3或ln(2^1*3^1*5^1)=ln2+ln3+ln5比较这两个值就可以知道前者小于后者
遍历n的所有相乘的方法用了一个递归（分治），从最初的n开始用for循环将n拆成所有可能的两个数的乘积，再对这两个数执行相同操作

在递归函数里其实用multiset比vector方便一些，但是multiset删一个数就把所有那个值的书全删了，这就不行了。。。 

关键词：难题，递归，STL，数论，数学题，分治 
*/
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

map<double,vector<int> > m;//存下可能的分解方法，和他对应的数值 
int prime[40]={2};//存一些质数 

void add_map(vector<int> factor)
{
    double value=0;
    int i=0;
    sort(factor.begin(),factor.end(),greater<int>());
    
    vector<int>::iterator it;
    for(it=factor.begin();it!=factor.end();it++)
        value+=log(prime[i++])*(*it-1);//要减1 
        
    m[value]=factor;
}//这个函数是把找到的一个分解方法vector存入map中，主要用来是计算该方法的值 

void separate(vector<int> factor,int n)//n代表这次运行分解vector中的第n个数 
{
    add_map(factor);//把当前这一组解加到map中 

    for(int i=2;i*i<=factor[n];i++)
        if(factor[n]%i==0)//如果找到了第n个数的一个可分解方案 
        {
            vector<int> t=factor;
            t.insert(t.end(),i);
            t.insert(t.end(),factor[n]/i);
            t.erase(t.begin()+n);//删除掉第n个元素，增加它分解后的两个元素 
            separate(t,t.size()-1);
            separate(t,t.size()-2);//对那两个元素递归操作 
        }
}//这个是核心的递归搜索函数，找出所有可能的分解方法 

void init_prime(void)
{
    int n=1;
    for(int i=3;n<40;i+=2)
    {
        for(int j=3;j*j<=i;j+=2)
            if(i%j==0)goto end;
        prime[n++]=i;
        end:;
    }
}//初始化质数数组 

int main()
{
    init_prime();
    
    int n;
    while(cin>>n)
    {
        m.clear();
        vector<int> t;
        t.insert(t.begin(),n);
        separate(t,0);//对输入的数开始递归分解 
        
        vector<int> result=(*m.begin()).second;
        //把map的第一个元素提取出来，因为map已经把最小的键值放到第一个元素了，第一个就是所需要的 
        
        cout<<prime[0]<<"^"<<result[0]-1;
        for(int i=1;i<result.size();i++)
            cout<<" * "<<prime[i]<<"^"<<result[i]-1;
        cout<<endl;//输出 
    }
}
