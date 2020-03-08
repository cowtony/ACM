/*
把输入的八进制小数转化为十进制小数输出

例0.7543[8]=7/8+5/8^2+4/8^3+3/8^4=(7+(5+(4+3/8)/8)/8)/8
先将八进制小数各位存进数组，再用循环从最后一位开始除以八，再加前一位，再除以八。。。
除以八的操作要用高精度

关键词：高精度，进制转换
*/
#include<iostream>
#include<string>
using namespace std; 

int main()
{ 
    char number[100];
    int answer[300],len,lenth;
    int divide_8(int *,int);

    while(cin>>number)
    {
        len=strlen(number);
        
        for(int i=0;i<300;i++)
            answer[i]=0;
            
        lenth=1;
        for(int i=len-1;i>1;i--)
        {
            answer[0]=number[i]-'0';
            lenth=divide_8(answer,lenth);            
        }
        
        cout<<number<<" [8] = 0.";
        for(int i=1;i<lenth;i++)
            cout<<answer[i];
        cout<<" [10]"<<endl;
    }

    return 0; 
} 

int divide_8(int *answer,int lenth)
{
    int i;
    for(i=0;i<lenth;i++)
    {
        answer[i+1]+=answer[i]%8*10;
        answer[i]/=8;
    }
    while(answer[i])
    {
        answer[i+1]+=answer[i]%8*10;
        answer[i]/=8;
        i++;
    }
    return i;
}
