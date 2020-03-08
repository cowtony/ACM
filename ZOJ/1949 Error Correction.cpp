/*
读入一个布尔矩阵,如果每行每列的和都为偶数则输出OK
若改变其中一个值可以达成上述条件则输出该值的行和列,都不行则输出Corrupt

读入判断,最后如果仅有一列和仅有一行为奇数
则改变他们的交叉点的值即可

关键词:简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        
        bool matrix[100][100];
        int sum_row[100]={0};
        int sum_column[100]={0};
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin>>matrix[i][j];
                sum_row[i]+=matrix[i][j];
                sum_column[j]+=matrix[i][j];
            }
            
        int odd_row=0,row,odd_column=0,column;
        for(int i=0;i<n;i++)
        {
            if(sum_row[i]%2==1){odd_row++;row=i;}
            if(sum_column[i]%2==1){odd_column++;column=i;}
        }
        
        if(odd_row==0 && odd_column==0)
            cout<<"OK"<<endl;
        else if(odd_row==1 && odd_column==1)
            cout<<"Change bit ("<<row+1<<","<<column+1<<")"<<endl;
        else 
            cout<<"Corrupt"<<endl;
    }
} 
