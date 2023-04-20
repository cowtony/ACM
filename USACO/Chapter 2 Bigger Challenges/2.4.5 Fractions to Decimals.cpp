/*
ID:cowtony1
PROG:fracdec
LANG:C++

����a,b�����a����b��ֵ��С����ʾ��ѭ���������Ŵ���

�ж�ѭ�������ж�һ��һ�γ���ʱ��������ǰ�Ƿ���ֹ�
�ò�������Ϳ���ʵ��
���Ƕ��ڸ�ʽ������鷳��Ҫ�ж��ǲ�������ѭ��С��������������ǲ����㣩
���һ�Ҫ��ÿ76���ַ��س�һ��

�ؼ��ʣ��߾��ȳ�������ѧ��
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{    
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    
    int n,d;
    cin>>n>>d;
    
    int character=0;
    if(n>=d)character+=log(double(n)/d)/log(10)+2;
    else character+=2;
    
    cout<<n/d<<'.';
    n%=d;//����������ֺ�С����,��ԭ������Ϊ����� 
    
    if(n==0){cout<<0<<endl;return 0;}
    
    int remainder[100001]={0};
    int result[100000],length=0;
    
    while(remainder[n]==0)
    {
        remainder[n]=length+1;
        n*=10;
        result[length++]=n/d;
        n%=d;
    }

    if(n!=0)
    {
        for(int i=0;i<length;i++)
        {
            if(i+1==remainder[n])
            {
                cout<<'(';
                character++;
                if(character%76==0)cout<<endl;
            }
            cout<<result[i];
            character++;
            if(character%76==0)cout<<endl;
        }
        cout<<')'<<endl;
        character++;
        if(character%76==0)cout<<endl;
    }
    else
    {
        for(int i=0;i<length-1;i++)
        {
            cout<<result[i];
            character++;
            if(character%76==0)cout<<endl;
        }
        if(result[length-1]!=0)cout<<result[length-1];
        cout<<endl;
    }
    //while(1);
    return 0;
}
