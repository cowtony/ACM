/*
ID:cowtony1
PROG:zerosum
LANG:C++

����n����1 2 ... n���üӺŻ���Ż�ո���ϳ�����ʽ��ʹ���Ϊ�� 

��һ�����������п��ܵķ�����ϣ�����һ���ݹ�remount()���ܼ�㣩
�ڶ�������ÿ����ϣ��������Ӧ�ı��ʽֵ����Щ�鷳��
��������������ʽֵΪ0��������б�set
���

�ؼ��ʣ��ַ��������ʽ��ֵ������ 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<vector>
using namespace std;

int n;
set<string> result;

int value(string operators)
{
    vector<int> number;
    int present=0;
    for(int i=1;i<=n;i++)
    {
        present+=i;
        if(operators[i-1]==' ')present*=10;
        else 
        {
            number.push_back(present);
            present=0;
        }
    }

    for(int i=0;i<operators.length();i++)
        if(operators[i]==' ')
        {
            operators.erase(operators.begin()+i);
            i--;
        }
        
    int result=number[0];   
    for(int i=1;i<number.size();i++)
    {
        if(operators[i-1]=='+')
            result+=number[i];
        else result-=number[i];
    }    
    return result; 
}

void remount(string operators="")
{
    if(operators.length()<n-1)
    {
        remount(operators+ '+');
        remount(operators+ '-');
        remount(operators+ ' ');
    }
    else if(value(operators)==0)
        result.insert(operators);
}


int main()
{
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    
    cin>>n;
    remount();
    
    set<string>::iterator it;
    for(it=result.begin();it!=result.end();it++)
    {
        cout<<1;
        for(int i=2;i<=n;i++)
            cout<<(*it)[i-2]<<i;
        cout<<endl;
    }
}
