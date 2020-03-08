/*
如题，逆序输入两个数字，逆序输出他们的和

是高精度加法的原理，这道题正好让字符串的第一位是个位，第二位是十位。。。
所以读入并相加
省掉前面的零再输出就可以了

关键词：高精度加法
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    
    int n;
    cin>>n;
    
    while(n--)
    {
        char a[100]={0},b[100]={0};
        cin>>a>>b;

        int length_a=strlen(a),length_b=strlen(b);
        
        for(int i=0;i<length_a;i++)
            a[i]-='0';
        for(int i=0;i<length_b;i++)
            b[i]-='0';
        for(int i=0;i<100;i++)
            a[i]+=b[i];//把b加到a 

        for(int i=0;i<99;i++)
            if(a[i]>=10)
            {
                a[i]-=10;
                a[i+1]++;
            }//进位 
        
        int length;
        for(int i=99;i>=0;i--)
            if(a[i]!=0){length=i+1;break;}
        for(int i=0;i<length;i++)
            if(a[i]!=0)
            {
                for(int j=i;j<length;j++)
                    cout<<char(a[j]+'0');
                cout<<endl;
                break;
            }//输出 
    }
    return 0;
}
