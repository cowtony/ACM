/*
ID:cowtony1
PROG:milk3
LANG:C++
输入A,B,C三个容积的桶，刚开始A，B是空的，C是满的
反复倒以后求当A是空的情况下C可以装多少奶，输出所有可能（不允许奶有流失） 

总奶量为C，用tf[i][j]记录A装i升，B装j升的情况，这个数组用来判定重复
然后深度（递归）搜索，每次枚举六种倒法：A倒B，A倒C，B倒A，B倒C，C倒A，C倒B
最后输出所有tf[0][j]==true的C-j

关键词：模拟，深度优先搜索，递归 
*/
#include<iostream>
#include<fstream>
using namespace std;

int A,B,C;
bool tf[21][21]={false};//判重
 
void dfs(int i,int j)//i代表A桶，j代表B桶 
{
    int k=C-i-j;//C桶装奶量 
    if(tf[i][j]==true)return;
    else tf[i][j]=true;
    
    dfs(0,j);//把A倒入C，这里不用加判断是因为C肯定倒不满，因为初始时C是满的别的是空的 
    dfs(i,0);//把B倒入C 
    if(i>=B-j)dfs(i-B+j,B);//A把B倒满了 
    else dfs(0,i+j);//A全倒进B 
    if(j>=A-i)dfs(A,j-A+i);//B把A倒满了 
    else dfs(i+j,0);//B全倒进A 
    if(k>=A-i)dfs(A,j);//C把A倒满了 
    else dfs(i+k,j);//C全倒进A 
    if(k>=B-j)dfs(i,B);//C把B倒满了 
    else dfs(i,j+k);//C全倒进B
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
    cout<<endl;//输出 
}
