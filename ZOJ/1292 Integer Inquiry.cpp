/*
输入最多100个数，每一个数最大为100位十进制，输出他们的和。

普通的高精度计算，用数组就行了

关键词:高精度计算，简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char number[100];
    int sum[105],m,i;
    void add(int *,char *);

    cin>>m;
    while(m--)
    {
        for(i=0;i<105;i++)
            sum[i]=0;
              
        while(cin>>number)
        {
            if(number[0]=='0'&&number[1]=='\0')break;
            add(sum,number);
        }
        
        for(i=104;i>0;i--)
            if(sum[i]!=0)break;
        for(;i>=0;i--)
            cout<<sum[i];
        cout<<endl;
        if(m)cout<<endl;
    }

    return 0;
}

void add(int *sum,char *number)
{
    int n=0; 
    int len=strlen(number);
    for(int i=len-1;i>=0;i--)
    {
        sum[n]+=number[i]-'0';
        if(sum[n]>9){sum[n]-=10;sum[n+1]++;}
        n++;
    }
}
