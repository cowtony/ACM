/*
读入两个矩阵，可以交换两列，或者把某一行取反
问这两个矩阵可不可以互相转换

枚举每一列在在第一列的情况，把第一列换的和目标第一列一样
对其后的列排序，也对原来的排序，看是否一样
用string实现排序很有思想 

关键词：好题，有思想 
*/ 
#include<iostream>
#include<string>
#include<algorithm>
#define MAX 100
using namespace std;

int n,m;

string solve(string a[],string b[])
{
    sort(b+1,b+m);//排列弟二列到第m列 
    string c[MAX];
    
    for(int column=0;column<m;column++)//枚举column列 
    {
        for(int i=0;i<m;i++)
            c[i]=a[i];//让c=a 
            
        swap(c[0],c[column]);//把第column列换到头列 
        
        for(int i=0;i<n;i++)
            if(c[0][i]!=b[0][i]) 
                for(int j=1;j<m;j++)
                    if(c[j][i]=='0')c[j][i]='1';
                    else c[j][i]='0';//行变换，使第一列与a的第一列相同 
                    
        sort(c+1,c+m);//排列c的弟二列到第m列  
        
        bool flag=true;
        for (int i=1;i<m;i++)
            if(c[i]!=b[i])flag=false;
        if(flag==true)return "YES";//看和b一样不 
    }
    return "NO";
}

int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
        cin>>n>>m;
        string a[MAX],b[MAX];
        
        char c;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) 
            {
                cin>>c;
                a[j].push_back(c);//注意是按列存取 
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) 
            {
                cin>>c;
                b[j].push_back(c);
            }
            
        cout<<solve(a,b)<<endl;
    }
    return 0;
}
