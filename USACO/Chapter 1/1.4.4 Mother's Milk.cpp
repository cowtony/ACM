/*
ID:cowtony1
PROG:milk3
LANG:C++
����A,B,C�����ݻ���Ͱ���տ�ʼA��B�ǿյģ�C������
�������Ժ���A�ǿյ������C����װ�����̣�������п��ܣ�������������ʧ�� 

������ΪC����tf[i][j]��¼Aװi����Bװj���������������������ж��ظ�
Ȼ����ȣ��ݹ飩������ÿ��ö�����ֵ�����A��B��A��C��B��A��B��C��C��A��C��B
����������tf[0][j]==true��C-j

�ؼ��ʣ�ģ�⣬��������������ݹ� 
*/
#include<iostream>
#include<fstream>
using namespace std;

int A,B,C;
bool tf[21][21]={false};//����
 
void dfs(int i,int j)//i����AͰ��j����BͰ 
{
    int k=C-i-j;//CͰװ���� 
    if(tf[i][j]==true)return;
    else tf[i][j]=true;
    
    dfs(0,j);//��A����C�����ﲻ�ü��ж�����ΪC�϶�����������Ϊ��ʼʱC�����ı���ǿյ� 
    dfs(i,0);//��B����C 
    if(i>=B-j)dfs(i-B+j,B);//A��B������ 
    else dfs(0,i+j);//Aȫ����B 
    if(j>=A-i)dfs(A,j-A+i);//B��A������ 
    else dfs(i+j,0);//Bȫ����A 
    if(k>=A-i)dfs(A,j);//C��A������ 
    else dfs(i+k,j);//Cȫ����A 
    if(k>=B-j)dfs(i,B);//C��B������ 
    else dfs(i,j+k);//Cȫ����B
}
 
int main()
{
    ifstream cin("milk3.in");
    ofstream cout("milk3.out");
    
    cin>>A>>B>>C;
    dfs(0,0);
    
    int i;
    for(i=20;i>=0;i--)
        if(tf[0][i]==true){cout<<C-i;break;}
    for(i--;i>=0;i--)
        if(tf[0][i]==true)cout<<" "<<C-i;
    cout<<endl;//��� 
}
