/*
ID:cowtony1
PROG:runround
LANG:C++
Runaround���Ķ����ǣ�ÿ����λ�����ظ�����û���㡣
����81362����һ����8������ѭ����8������6��������ѭ����6������2�����ȫ�������ֻص�8
����M���ҳ���M�����С��Runaround��

д�������ж�һ�����ǲ���Runaround����ö�� 

�ؼ��ʣ�ö�٣�ģ�⣬�߾��� 
*/
#include<iostream>
#include<fstream>
using namespace std;

bool Runaround(int n)
{
    int digit[10]={0};
    bool map[10]={0};
    bool used[10]={0};
    
    int length=0;
    while(n)
    {
        digit[length]=n%10;
        if(used[digit[length]]==false)used[digit[length]]=true;//���ĳһλ�ظ����־ʹ��� 
        else return false;
        
        if(digit[length]==0)return false;//����0Ҳ���� 
        length++;
        n/=10;
    }//��n��λ������� 
    
    int l=length-1;
    int t=0;
    while(map[l]==false)
    {
        map[l]=true;
        l=((l-digit[l])%length+length)%length;//ѭ������������Ϊ�Ƿ��Ŵ�����Է����� 
        t++;
    }
    if(t==length && l==length-1)return true;
    else return false;
}

int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    int M;
    cin>>M;
    
    for(int i=M+1;i<=987654321;i++)
        if(Runaround(i)==true)
        {
            cout<<i<<endl;
            break;
        }
}
