/*
输入时间和所在的时区，求GMT+0的时间。由于表坏了有的字显示不出来，所以输出可能的最小的那个时间

用六个for循环枚举出所有的时间及时区可能排列
然后循环中判断这个解是否正确（如小时数大于24，没有GMT-0）
如果正确的话计算GMT+0的时间，把它存为string类加入set中
最后输出set的第一个解

关键词：模拟，麻烦题 
*/
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    string s;
    while(getline(cin,s))
    {
        set<string> result;
        char H_2,H_1,M_2,M_1,SIGNE,ZONE;
        H_2=s[0];
        H_1=s[1];
        M_2=s[3];
        M_1=s[4];
        SIGNE=s[9];
        ZONE=s[10];

        for(int h2=0;h2<=2;h2++)
            if(H_2=='?' || H_2==h2+'0')
                for(int h1=0;h1<10;h1++)
                    if(H_1=='?' || H_1==h1+'0')
                        for(char m2='0';m2<'6';m2++)
                            if(M_2=='?' || M_2==m2)
                                for(char m1='0';m1<='9';m1++)
                                    if(M_1=='?' || M_1==m1)
                                        for(char signe='-';signe>='+';signe-=2)
                                            if(SIGNE=='?' || SIGNE==signe)
                                                for(int zone=0;zone<=9;zone++)
                                                    if(ZONE=='?' || ZONE==zone+'0')
                                                    {
                                                        int hour=h2*10+h1;
                                                        if(hour>=24)continue;//判断小时的值是否超出23
                                                        if(signe=='-' && zone==0)continue;//不会出现GMT-0 
                                                    
                                                        if(signe=='-')hour=(hour+zone)%24;
                                                        else hour=(hour-zone+24)%24;
                                                        
                                                        string time;
                                                        time.push_back(hour/10+'0');
                                                        time.push_back(hour%10+'0');
                                                        time.push_back(':');
                                                        time.push_back(m2);
                                                        time.push_back(m1);

                                                        result.insert(time);
                                                    }
    cout<<*result.begin()<<endl;
    }
    
    //while(1);
} 
