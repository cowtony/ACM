/*
ID:cowtony1
PROG:milk
LANG:C++

Ҫ��N����ţ�̣���M��ũ��ÿ�˶���һ�����ۺ�һ������ţ�̣������ٻ�����Ǯ������N����ţ��

����ֱ�Ӱ���Ǯ����Ȼ��̰��
������Ǯ�ķ�Χ��һǧ�����Կ����ø�����price[i]��ʾ����Ϊi���̿��������
ע���п�������ũ��ļ�Ǯһ�������Զ����ʱ����дprice[p]=a,Ҫдprice[p]+=a; 

�ؼ��ʣ�̰�ģ����� 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    
    int N,M;
    cin>>N>>M;
    int P,A;
    int price[1001]={0};
    for(int i=0;i<M;i++)
    {
        cin>>P>>A;
        price[P]+=A;
    }
    
    int total=0,money=0;
    for(int i=0;i<1001;i++)
        if(total+price[i]<=N)
        {
            total+=price[i];
            money+=i*price[i];
        }
        else
        {
            money+=i*(N-total);
            break;
        }
    cout<<money<<endl;
}
