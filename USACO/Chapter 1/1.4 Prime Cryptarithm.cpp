/*
ID:cowtony1
PROG:crypt1
LANG:C++
����һ���˷���ʽ�ĸ�ʽ��Ҫ��ֻ����������������������ж������ 

������д���forѭ��ö�ٳ�������������λ
Ȼ���жϺ���Ľ���Ƿ����Ҫ�󣬷��ϵĻ���������һ 

�ؼ��ʣ�ö��
*/
#include<iostream>
#include<fstream>
using namespace std;

int N;
int digit[9];
bool d[10]={0};

bool test(int x)
{
    while(x)
    {
        if(d[x%10]==false)return false;
        x/=10;
    }
    return true;
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);

    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>digit[i];
        d[digit[i]]=true;
    }
        
    int count=0;
    for(int a1=0;a1<N;a1++)
        for(int a2=0;a2<N;a2++)
            for(int a3=0;a3<N;a3++)
                for(int b1=0;b1<N;b1++)
                    for(int b2=0;b2<N;b2++)
                    {
                        int a=digit[a1]*100+digit[a2]*10+digit[a3];
                        if(test(a*digit[b1])==false || a*digit[b1]>999)continue;
                        if(test(a*digit[b2])==false || a*digit[b2]>999)continue;
                        
                        int b=digit[b1]*10+digit[b2];
                        if(test(a*b)==false || a*b>9999)continue;
                        
                        count++;
                    }
    cout<<count<<endl;
}
