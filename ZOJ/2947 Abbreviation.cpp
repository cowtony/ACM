/*
将由不大于5个单词的词组缩写为首字母，判断所给的两个词组缩写是否相同

就那样做吧

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    char name_1[5][11];
    char name_2[5][11];
    int t,a,b;
    bool judge;
    
    cin>>t;
    while(t--)
    {
        cin>>a;
        for(int i=0;i<a;i++)cin>>name_1[i];
        cin>>b;
        for(int i=0;i<b;i++)cin>>name_2[i];
        
        if(a!=b){cout<<"DIFFERENT"<<endl;continue;}
        
        judge=true;
        for(int i=0;i<a;i++)
            if(name_1[i][0]!=name_2[i][0])judge=false;
        
        if(judge==true)cout<<"SAME"<<endl;
        else cout<<"DIFFERENT"<<endl;
    }
    
    return 0;
}
