/*
输入多组J和F表示交换的比例，以及现在拥有的F，求最多能交换到多少J，题意比较复杂但题不难

用vector存下各数据并直接排列好
然后一个一个的模拟交换直到换完即可
输出有小要求

关键词：简单题，STL，贪心 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct FatMouse
{
    double J;//java bean
    double F;//cat food
    double a;
};

bool compare(FatMouse m,FatMouse n)
{
    return m.a>n.a;
}

int main()
{
    int M,N;
    while(cin>>M>>N)
    {
        if(M==-1 && N==-1)break;
                    
        vector<FatMouse> v;
        FatMouse temp;
        for(int i=0;i<N;i++)
        {
            cin>>temp.J>>temp.F;
            temp.a=temp.J/temp.F;
            v.push_back(temp);
        }
        sort(v.begin(),v.end(),compare);
        
        double total=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].F>M)
            {
                total+=M*v[i].a;
                break;
            }
            else
            {
                total+=v[i].J;
                M-=v[i].F;
            }
        }
        cout.precision(3);
        cout<<fixed<<total<<endl;
    }
}
