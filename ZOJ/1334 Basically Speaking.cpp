/*
输入一个七位以内的a进制数，要求转换成b进制输出，若大于七位输出ERROR，2<=a,b<=16

用字符串读取数字，再转化为变量r，最后转化为所求进制

关键词：进制转换
*/
#include <iostream> 
#include <string> 
using namespace std; 

int main()
{ 
    int base_1,base_2; 
    int r=0; 
    string num; 
    
    while(cin>>num>>base_1>>base_2)
    { 
        for(int i=0;i<num.size();i++)
            if(num[i]>='0'&&num[i]<='9')r=r*base_1+num[i]-'0'; 
                                   else r=r*base_1+num[i]-'A'+10;    //转化的r为输入的数字
        string strr;
        
        while(r!=0)
        { 
            int temp=r%base_2;
            if(temp<=9)strr=(char)(temp+'0')+strr; 
                  else strr=(char)(temp+'A'-10)+strr; 
            r/=base_2;                                               //把r转化成base_2进制，存在strr
        } 
        
        cout.width(7);
        if(strr.size()<=7)cout<<strr<<endl;
                     else cout<<"ERROR"<<endl; 
    } 
    return 0; 
} 
