#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string str1, str2;
    int matrix[500][500];
    int len1,len2;
    
    while(cin>>str1>>str2)
    {
        len1=str1.length();
        len2=str2.length();
        //memset(matrix,0,sizeof(matrix));
        
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
                if(str1[i-1]==str2[j-1])matrix[i][j]=matrix[i-1][j-1]+1;
                else matrix[i][j]=matrix[i-1][j]>matrix[i][j-1]?matrix[i-1][j]:matrix[i][j-1];
    
   
        cout<<matrix[len1][len2]<<endl;
    }
}
