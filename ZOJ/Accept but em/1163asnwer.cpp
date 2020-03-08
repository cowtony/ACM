#include<iostream>
#define MAX 501
using namespace std;

int main()
{
    long long f[MAX][MAX]; 
    int n;
    
    //freopen("aaa.txt","r",stdin);

    f[0][0]=1; 
    for(int i=0;i<MAX;++i)
    { 
        for(int j=1;j<=i;++j)
            f[i][j]=f[i][j-1]+f[i-j][j-1];
            
        for(int j=i+1;j<MAX;++j)
            f[i][j]=f[i][i]; 
    } 
    
    while(cin>>n&&n!=0)
        cout<<f[n][n]-1<<endl; 


    //while(1);
    return 0;
}

