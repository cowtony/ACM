/*
如题，逆序输入两个数字，逆序输出他们的和

是高精度加法的原理，这道题正好让字符串的第一位是个位，第二位是十位。。。
所以读入并相加
省掉前面的零再输出就可以了

关键词：高精度加法，简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char a[6]={0},b[5]={0};
    
    cin>>a>>b;
    
    for(int i=0;i<strlen(b);i++)
        a[i]+=b[i]-'0';//把b加到a 
    
    for(int i=0;i<strlen(a);i++)
        if(a[i]>'9')
        {
            a[i]-=10;
            if(a[i+1]==0)a[i+1]='1';
            else a[i+1]++;
        }//进位 
        
    for(int i=0;i<strlen(a);i++)
        if(a[i]!='0'){cout<<a+i;break;}//输出 
    
    //while(1);
    return 0;
}
