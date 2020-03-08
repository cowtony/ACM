/*
给一个大写字符串，每个字母换成它下一个字母，Z换成A

Z换成A实际上是一个循环，用%26可以做到

关键词：字符串，简单题
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,len;
    char s[50];
    
    //freopen("aaa.txt","r",stdin);
    
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {   
        cin>>s;
        len=strlen(s);
        
        cout<<"String #"<<i<<endl;
        
        for (int j=0;j<len;j++)
            cout<<char((s[j]+1-'A')%26+'A');//关键的循环
            
        cout<<endl<<endl;
    }
    
    //while(1);
    return 0;
}
