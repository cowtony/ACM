/*
ID:cowtony1
PROG:fact4
LANG:C++

���n!�����һ������λ

һ����һ�����ĳˣ���Ȼֻ�ü����һλ������Ҫ��ĩβ����Ҫ��ʱ����
Ϊ�˲��ô洢����ı��������ÿ����ģһ��1000000�������Ҫ��n��

�ؼ��ʣ����⣬��ѧ�� 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    
    int n;
    cin>>n;
    int result=1;
    
    for(int i=1;i<=n;i++)
    {
        result*=i;
        while(result%10==0)
            result/=10;
        result%=100000;//����ģʮ 
    }
    cout<<result%10<<endl;
}
