/*
输入数N，求由1-N按顺序插入加号或减号能求得表达式值为0的所有解 

第一步，遍历所有可能的符号组合（用了一个递归remount()，很简便）
第二步，对每个组合，求出它相应的表达式值（有些麻烦）
第三步，如果表达式值为0，加入答案列表set
输出

关键词：字符串，表达式求值，回溯，搜索 
*/
#include<iostream>
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
    //while(1);
}
