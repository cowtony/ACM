/*
两人一人发n<=20张牌，每次比较一张，若一人的牌的点数比另一人大一以上，则此人得分加大牌的点数，若一人的牌比另一人小一，则他得分加上两张牌点数的总和。但对于1和2，拿1的人得6分而不是3分。

用if判断，一张一张算

关键词：简单题
*/
#include<iostream>
using namespace std;

int main()
{
    int card_a[20],card_b[20],score_a,score_b,n,end=0;
    
    while(cin>>n)
    {
        if(n==0)break;
        if(end==1)cout<<endl;
        
        for(int i=0;i<n;i++)
            cin>>card_a[i];          //读入牌的点数
        for(int i=0;i<n;i++)
            cin>>card_b[i];          //读入牌的点数
          
        score_a=score_b=0;  
            
        for(int i=0;i<n;i++)
        {
            if(card_a[i]==card_b[i])continue;      //点数一样都不得分
            if(card_a[i]>card_b[i])
            {
                if(card_a[i]-card_b[i]==1)       
                {
                    if(card_b[i]==1)score_b+=6;    
                               else score_b+=card_a[i]+card_b[i];    
                }
                if(card_a[i]-card_b[i]>1)score_a+=card_a[i];  
            }
            else
            {
                if(card_b[i]-card_a[i]==1)
                {
                    if(card_a[i]==1)score_a+=6;
                               else score_a+=card_a[i]+card_b[i];
                }
                if(card_b[i]-card_a[i]>1)score_b+=card_b[i];  
            }
        }
        cout<<"A has "<<score_a<<" points. B has "<<score_b<<" points."<<endl;
        end=1;
    }
    
    return 0;
}

