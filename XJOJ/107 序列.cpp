/*
一串数，每次把相邻两个换为较大的那个数，花费为较大的那个的值，求整个数列只剩一个元素的最小花费

贪心，每次合并找到满足下列条件的两个点合并：
找到i,满足a[i-1]>=a[i]<=a[i+1]
if a[i-1]<a[i+1] 合并a[i-1]和a[i],否则合并a[i]和a[i+1]
循环n-1次即可达到目标。
为了更方便的实现，在数列两端加上“无限大”的两个数
用栈的思想实现，程序很简洁，很有思想

关键词：贪心，巧算法，有思想 
*/
#include<iostream>
#include<vector>
#define MAX_N 1000000
#define INF 1000000001
using namespace std;

int n,a[MAX_N+2];
vector<int> stack;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
       
    a[0]=a[n+1]=INF;
   
    long long result=0;
   
    stack.push_back(a[0]);
    for(int i=1;i<=n+1;i++)
    {
        while(a[i]>=stack.back())
        {
            int change=min(stack[stack.size()-2],a[i]);
            if(change==INF)break;
            result+=change;
            stack.pop_back();
        }
        stack.push_back(a[i]);
    }
    cout<<result<<endl;
   
    return 0;
}
