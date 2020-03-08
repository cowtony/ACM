/*
读入两个字符串，求他们的并集，交集，补交集，差集（详情见原题）

用两个布尔数组判断这两个字符串中哪些字符出现过
然后用逻辑判断输出
第三问用异或

关键词：逻辑运算，字符串 
*/ 
#include<iostream>
using namespace std;

int main()
{
    char a[256],b[256];
    cin>>a>>b;
    
    bool judgeA[62]={0},judgeB[62]={0},solution;
    
    for(int i=0;i<strlen(a);i++)
        if(a[i]>='A' && a[i]<='Z')judgeA[a[i]-'A']=true;
        else if(a[i]>='a' && a[i]<='z')judgeA[a[i]-'a'+26]=true;
        else if(a[i]>='0' && a[i]<='9')judgeA[a[i]-'0'+52]=true;
        
    for(int i=0;i<strlen(b);i++)
        if(b[i]>='A' && b[i]<='Z')judgeB[b[i]-'A']=true;
        else if(b[i]>='a' && b[i]<='z')judgeB[b[i]-'a'+26]=true;
        else if(b[i]>='0' && b[i]<='9')judgeB[b[i]-'0'+52]=true;
    
    solution=false;    
    for(int i=0;i<26;i++)
        if((judgeA[i]||judgeB[i])==true)cout<<char('A'+i),solution=true;
    for(int i=26;i<52;i++)
        if((judgeA[i]||judgeB[i])==true)cout<<char('a'+i-26),solution=true;
    for(int i=52;i<62;i++)
        if((judgeA[i]||judgeB[i])==true)cout<<char('0'+i-52),solution=true;
    if(solution==true)cout<<endl;
    else cout<<"NO!"<<endl;

    solution=false;
    for(int i=0;i<26;i++)
        if((judgeA[i]&&judgeB[i])==true)cout<<char('A'+i),solution=true;
    for(int i=26;i<52;i++)
        if((judgeA[i]&&judgeB[i])==true)cout<<char('a'+i-26),solution=true;
    for(int i=52;i<62;i++)
        if((judgeA[i]&&judgeB[i])==true)cout<<char('0'+i-52),solution=true;
    if(solution==true)cout<<endl;
    else cout<<"NO!"<<endl;
    
    solution=false;
    for(int i=0;i<26;i++)
        if((judgeA[i]^judgeB[i])==true)cout<<char('A'+i),solution=true;
    for(int i=26;i<52;i++)
        if((judgeA[i]^judgeB[i])==true)cout<<char('a'+i-26),solution=true;
    for(int i=52;i<62;i++)
        if((judgeA[i]^judgeB[i])==true)cout<<char('0'+i-52),solution=true;
    if(solution==true)cout<<endl;
    else cout<<"NO!"<<endl;
    
    solution=false;
    for(int i=0;i<26;i++)
        if((judgeA[i]||judgeB[i])==false)cout<<char('A'+i),solution=true;
    for(int i=26;i<52;i++)
        if((judgeA[i]||judgeB[i])==false)cout<<char('a'+i-26),solution=true;
    for(int i=52;i<62;i++)
        if((judgeA[i]||judgeB[i])==false)cout<<char('0'+i-52),solution=true;
    if(solution==true)cout<<endl;
    else cout<<"NO!"<<endl;
    
    //while(1);
    return 0;
}
