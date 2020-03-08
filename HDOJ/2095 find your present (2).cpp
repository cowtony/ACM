/*
一堆数，只有一个是唯一的，其他数字出现的次数都是偶数，求那个唯一的数字

用set模拟一遍就可以了

关键词：STL，简单题 
*/
#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n;
    while(cin>>n && n!=0)
    {
	    set<int> s;
	    for(int i=0;i<n;i++)
	    {
		    int a;
	        scanf("%d",&a);
	        if(s.find(a)==s.end())s.insert(a);
	        else s.erase(a);
		}
		cout<<*s.begin()<<endl;
	}
}
