/*
n个人，每隔一个杀死一个，求最后剩下哪个人

利用递归的思想，lucky(n)表示n个人最后剩下几号
假如一开始n为偶数，1,2,3,4,5,6，删掉2,4,6还剩1,3,5
对于1,3,5这样的lucky(3)来说返回的是第二个人，但是这里确是3号，所以要返回2*lucky(3)-1
如果n是奇数，1,2,3,4,5,6,7，先删掉2,4,6还剩下1,3,5,7，注意这时候不能调用lucky(4)
如果调用lucky(4)意义上删掉的就是3和7，实际上应该删1和5，因为上一轮还剩了最后一个数字，所以这一轮要从第一个开始删
正确的想法是先不看第一个要被删掉的元素，就和前面返回2*lucky(3)-1一样了，只不过由于去掉了第一个元素
所以每个数字都大了2，把减一改成加一
数据上用sscanf方便些 

关键词：递归 
*/
#include<iostream>
#include<cmath>
using namespace std;

int lucky(int n)
{
    if(n<=2)return 1;
    
    if(n%2==0)return 2*lucky(n/2)-1;
    else return 2*lucky(n/2)+1;
}

int main()
{
    char expression[5];
    while(cin>>expression)
    {
        int a,b;
        sscanf(expression,"%de%d",&a,&b);
        if(a==0 && b==0)break;
        
        cout<<lucky(a*pow(10.0,b))<<endl;
    }
}
