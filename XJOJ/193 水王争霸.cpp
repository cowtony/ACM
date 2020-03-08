/*
输入每个人的ID和他的一个值，先按值降序排序，如果值相同按ID的字典顺序排
输出ID最后的序列

结构体定义一下，就是两个关键字冒泡排序

关键词：简单题，排序
*/
#include<iostream>
#include<string>
using namespace std;

struct Data
{
    string ID;
    string acount;
    
    friend bool operator <(Data &a,Data &b);
};

bool operator <(Data &a,Data &b)
{
    if(a.acount.length()!=b.acount.length())
        return a.acount.length()<b.acount.length();
    else if(a.acount!=b.acount)
        return a.acount<b.acount;
    else 
        return a.ID>b.ID;
}

void swap(Data &a,Data &b)
{
    Data temp=a;
    a=b;
    b=temp;
}

int main()
{
    Data people[1000];
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>people[i].ID>>people[i].acount;

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(people[i]<people[j])swap(people[i],people[j]);
            
    for(int i=0;i<n;i++)
        cout<<people[i].ID<<endl;
        
    //while(1);
    return 0;
}
