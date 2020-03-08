/*
输入一个字符串，输出该字符串是由这几个字符排列组合出来的第几大

用排列组合计算，如BANANA
第一位是B，所以比B小的是A，也就是说比BANANA小的有A?????，后面五个字符是AABNN，共5!/(2!*1!*2!)种结果
再看第二位是A，没有比他小的，第三位是N，有BAA???-BAM???这些方案，对每一种算出排列组合数
最后把他们加起来就可以了

关键词：排列组合 
*/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    long long f[21]={1};
    for(int i=1;i<=20;i++)
        f[i]=f[i-1]*i;
    
    int T;
    cin>>T;
    while(T--)
    {    
        char str[21];
        cin>>str;
        int times[26]={0};
        for(int i=0;i<strlen(str);i++)
            times[str[i]-'A']++;
            
        long long sum=0;
        for(int idx=0;idx<strlen(str);idx++)
        {
            long long X=f[strlen(str)-idx-1],Y;
            for(int i=0;i<str[idx]-'A';i++)
            {
                if(times[i]>0)
                {
                    times[i]--;
                    Y=1;
                    for(int j=0;j<26;j++)Y*=f[times[j]];
                    sum+=X/Y;
                    times[i]++;
                }
            }
            times[str[idx]-'A']--;
        }
        cout<<sum<<endl;
    }
}
