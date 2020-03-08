/*
定义一个EKG数列，它里面的元素不重复，并且后一项是当前可用的最小的不与前一项互素的数
输入元素n<=300000，输出他在第几项

假设有一项是6，他的素因子有2和3，所以他的后一项是2的倍数或3的倍数
定义一个数组multiple，multiple[i]表示当前可用的最小的i的倍数，初始时multiple[i]=i 
所以对于6，他的下一项就是multiple[2]和multiple[3]中最小的一个

找到了下一项以后，因为新增了元素，所以需要对multiple做一些改变
假设6的下一项是3，所以multiple[3]不能再等于3，要往上加3，但也不能等于6，因为6已经出现过，所以最后multiple[3]=9
同样，如果是12，就要分别改变multiple[2]和multiple[3]，具体的改变方法看程序

把下一项的值加入EKG数组中，注意角标是数列某一项的值，而EKG[i]表示i在第几项
这样不仅最后输出方便，在前面判断某一项i是否已经出现在数列中也很方便

最后一个问题就是怎样快速遍历某一个数的所有素因数，因为前面的解法中两次都用到了（比如6就找出了2和3）
用vector<int> factor[MAX]并且筛法存下factor[i]做为i的素因数列表，这样比较快但vector费内存，会内存溢出
现在定义一个prime[i]表示i的最小的素因数（筛法构造），注意prime[p]=p
然后for(int i=prime[top];i>1;i=prime[top/=i])这句话就很好的遍历了top的所有素因数

关键词：数学题，数论，难题，难题，难题 
*/
#include<iostream>
#define MAX 1000001
using namespace std;

int multiple[MAX]={0};//表示i目前可用的最小倍数  
int EKG[MAX]={0};//EKG[i]表示数列中i这个数的序号 
int prime[MAX]={0};//i的最小的素因数（有可能是i本身） 
    
int main()
{
    multiple[2]=4;
    EKG[1]=1;
    EKG[2]=2;
    
    for(int i=3;i<MAX;i++)
        multiple[i]=i;
    
    for(int i=2;i<MAX;i++)
        if(prime[i]==0)
            for(int j=i;j<MAX;j+=i)
                if(prime[j]==0)prime[j]=i;//筛法构造prime[i] 

    int top=2,n=3;//top是目前最高项的值，n是下一项的角标 
    while(top<MAX)//核心计算，一项一项的算出值 
    {
        int min=MAX;
        for(int i=prime[top];i>1;i=prime[top/=i])
            if(min>multiple[i])
                min=multiple[i];//找出下一项的值 
        
        top=min;
        EKG[top]=n++;
        
        for(int i=prime[min];i>1;i=prime[min/=i])
            if(multiple[i]==top)
            {
                multiple[i]+=i;
                while(multiple[i]<MAX && EKG[multiple[i]]!=0)
                    multiple[i]+=i;
            }//把multiple中的一些倍数再往上加 
    }

    while(cin>>n)
    {
        if(n==0)break;
        cout<<"The number "<<n<<" appears in location "<<EKG[n]<<"."<<endl;
    }
}
