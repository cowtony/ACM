/*
输入n<=1000，以及n个username和password，将password中的'1'换成'@'，'l'换成'L'，'O'换成'o'，'0'换成'%' 
输出换了几组，并依次列出，如果都没有换，则输出No account is modified.

要预先存下n组数据
然后就按题意做

关键词：字符 
*/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n;
    string username[1000];
    string password[1000];
    
    while(cin>>n)
    {
        if(n==0)return 0;
        
        int count=0;
        bool flag[1000]={false};

        for(int i=0;i<n;i++)
        {
            cin>>username[i]>>password[i];
            
            for(int j=0;j<password[i].length();j++)
            {
                switch(password[i][j])
                {
                    case '1':password[i][j]='@';flag[i]=true;break;
                    case 'l':password[i][j]='L';flag[i]=true;break;
                    case 'O':password[i][j]='o';flag[i]=true;break;
                    case '0':password[i][j]='%';flag[i]=true;break;
                }
            }
            if(flag[i]==true)count++;
        }
        
        if(count>0)
        {
            cout<<count<<endl;
            for(int i=0;i<n;i++)
                if(flag[i]==true)cout<<username[i]<<' '<<password[i]<<endl;
        }
        else cout<<"No account is modified."<<endl;
    }
}
