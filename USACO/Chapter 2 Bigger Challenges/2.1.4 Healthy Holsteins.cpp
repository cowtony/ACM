/*
ID:cowtony1
PROG:holstein
LANG:C++
��һͷţ��Ҫv��ά������ÿ����Ҫ������������
������g��ҩ��ÿ��ҩ���е�v��ά��������Ҳ�����ˣ������ٳ��ļ���ҩ���Բ���ţ��ά����

ʵ���Ͼ���ö�����п��ܵ�ҩ��ϣ��ҳ��ܲ���ά�����������������������
����DFSʵ�� 

�ؼ��ʣ������������������ 
*/
#include<iostream>
#include<fstream>
using namespace std;

int v,g;
int present[25]={0};//��ǰ��ά���� 
int require[25];//��Ҫ��ά���� 
int method[25];//��¼��ǰ����� 
int min_method[25];//��С������ 
int vitamin[15][25];//��������ҩ����Ϣ 
int min_length=100;//��¼��С���� 

bool full()
{
    for(int i=0;i<v;i++)
        if(present[i]<require[i])return false;
    return true;
}//�жϵ�ǰ�Թ���ҩ�Ƿ��������� 

void dfs(int front,int length)
{
    if(full()==true)//������������� 
    {
        if(length<min_length)//������һ����С�Ľ� 
        {
            min_length=length;
            for(int i=0;i<length;i++)
                min_method[i]=method[i];//������С�Ľ� 
        }
        return;
    }
    //���� 
    for(int i=front+1;i<g;i++)
    {
        method[length]=i;//��ȥ��һ��ҩ 
        for(int j=0;j<v;j++)
            present[j]+=vitamin[i][j];//�ѳԵ�ά�������� 
        dfs(i,length+1);//�ݹ����� 
        for(int j=0;j<v;j++)
            present[j]-=vitamin[i][j];//�ٰѸղųԵ�ҩ�³��� 
    }
}

int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    
    cin>>v;
    for(int i=0;i<v;i++)
        cin>>require[i];
    
    cin>>g;
    for(int i=0;i<g;i++)
        for(int j=0;j<v;j++)
            cin>>vitamin[i][j];
            
    dfs(-1,0);
    
    cout<<min_length;
    for(int i=0;i<min_length;i++)
        cout<<' '<<min_method[i]+1;
    cout<<endl;
}
