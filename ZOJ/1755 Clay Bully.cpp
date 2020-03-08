/*
老师给每个人发一样体积的粘土让他们捏长方体，有个人抢别人的粘土
老师通过量每个人长方体的尺寸确定谁抢谁的

直接模拟做，可以先算出平均每人的粘土，再看谁比平均多，谁比平均少
也可以按每个人的体积排序，最大的抢最小的

关键词：简单题 
*/
#include<iostream>
using namespace std;

struct Student
{
    int a,b,c;
    int v;
    string name;
    
    void input()
    {
        cin>>a>>b>>c;
        cin>>name;
        v=a*b*c;
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==-1)break;
        
        Student s[10];
        for(int i=0;i<n;i++)
            s[i].input();
            
        double average=0;
        for(int i=0;i<n;i++)
            average+=s[i].v;
        average/=double(n);
        
        Student s1,s2;
        for(int i=0;i<n;i++)
        {
            if(s[i].v>average)s1=s[i];
            if(s[i].v<average)s2=s[i];
        }
        cout<<s1.name<<" took clay from "<<s2.name<<"."<<endl;
    }
}
