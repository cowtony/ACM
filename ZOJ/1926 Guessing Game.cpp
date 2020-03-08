/*
猜一个1至10的数字，告诉你大了还是小了的游戏。现在给你一个猜的过程，判断主持人是否作假

定义一个容量为10的布尔数组，依据过程划掉否定的数字，最后如果正确答案为已被否定的数字则说明作假了

关键词：
*/
#include<iostream>
using namespace std;

int main()
{
    char response[20];
    int a,dim[11];
    
    //freopen("aaa.txt","r",stdin);

    while(1)
    {
        memset(dim,0,sizeof(dim));
        
        do
        {
            cin>>a;
            if(a==0)return 0;
            cin>>response>>response+10;
            
            if(response[10]=='h')
                for(int i=a;i<=10;i++)dim[i]=1;    //划掉否定的数字
            if(response[10]=='l')
                for(int i=a;i>=1;i--)dim[i]=1;     //划掉否定的数字
        }
        while(response[0]=='t');
        
        if(dim[a]==0)cout<<"Stan may be honest"<<endl;
                     else cout<<"Stan is dishonest"<<endl;
    }

}

