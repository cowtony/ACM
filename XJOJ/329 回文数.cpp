/*
输入1<=i<=2000000000，输出第i个十进制回文数

将回文数列出一些：
1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9
11,22,33,44,55,66,77,88,99
101,111,121,...,979,989,999
1001,1111,1221,...,9779,9889,9999
既然是回文数，就写出前一半：
1,2,3,4,5,6,7,8,9
1,2,3,4,5,6,7,8,9       18项 
10,11,12,...,97,98,99
10,11,12,...,97,98,99   180项
100,101,...,998,999
100,101,...,998,999     1800项，以此类推，每一组项数加起来是2*(10^k-1) 
所以只要找出i与这里数字n对应的关系，先输出i，再逆序输出即可
但在输出i的时候要判断是否要重复输出那个个位
代码中k的值会超过long，所以用long long 

关键词：数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    int i,n;
    long long k;
    
    cin>>i;
    
        if(i==0)return 0;
        
        for(k=18;k<i;k*=10)
            i-=k; 

        if(i>k/2)
        {
            i-=k/2;
            n=i+k/18-1;
            cout<<n;//正序输出 
            while(n>0)
            {
                cout<<n%10;
                n/=10;
            }//倒序输出 
            cout<<endl;
        }
        else
        {
            n=i+k/18-1;
            cout<<n;
            n/=10;
            while(n>0)
            {
                cout<<n%10;
                n/=10;
            }
            cout<<endl;
        }
    //while(1);
    return 0;
}
