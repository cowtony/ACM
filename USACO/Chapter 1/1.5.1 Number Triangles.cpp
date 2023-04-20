/*
ID:cowtony1
PROG:numtri
LANG:C++
����һ�����ֽ��������ҳ�һ��·��ʹ�ú����������ֵ

�򵥵Ķ�̬�滮
״̬ת�Ʒ��̣�number[i][j]+=max(number[i-1][j-1],number[i-1][j]);
����˵��ǰ���ӵ����ֵ�������������ֵ�нϴ��һ�������Լ�
����������һ���ҳ����ֵ������

�ؼ��ʣ���̬�滮������ 
*/
#include<iostream>
#include<fstream>
using namespace std;

int number[1001][1001]={0};

int main()
{
    ifstream cin("numtri.in");
    ofstream cout("numtri.out");
    
    int R;
    cin>>R;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=i;j++)
            cin>>number[i][j];
    
    for(int i=2;i<=R;i++)
        for(int j=1;j<=i;j++)
            number[i][j]+=max(number[i-1][j-1],number[i-1][j]);
    
    int max_value=0;
    for(int j=1;j<=R;j++)
        max_value=max(max_value,number[R][j]);
    
    cout<<max_value<<endl;
}
