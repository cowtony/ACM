/*
把AA，Z等Excel中列的表示法与十进制数相互装换

Excel中列的表示法其实是权为1~26的26进制
与普通的0~25不同
具体的算法体现在取模和整除时
0~25：取模得0~25的值
1~26：取模得1~26的值
0~25：整除是舍尾取整
1~26：整除是四舍五入
知道了方法实现就不难了

关键词：进制转换 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    while(n--)
    {
        string number;
        cin>>number;
        
        if(number[0]>='A' && number[0]<='Z')
        {
            int result=0;
            unsigned long base=1;
            for(int i=number.length()-1;i>=0;i--)
            {
                result+=base*(number[i]-('A'-1));
                base*=26;
            }//字母化为十进制值 
            cout<<result<<endl;
        }
        else
        {
            int dec=0;
            unsigned long base=1;
            for(int i=number.length()-1;i>=0;i--)
            {
                dec+=base*(number[i]-'0');
                base*=10;
            }//十进制字符串化为十进制数字 
            
            char result[20]={0};
            int point=0;
            while(dec>0)
            {
                result[point]=dec%26;
                if(result[point]==0)result[point]+=26;
                dec-=result[point];
                dec/=26;
                result[point]+='A'-1;
                point++;
            }
            for(int i=strlen(result)-1;i>=0;i--)
                cout<<result[i];
            cout<<endl;
        }
    }
    return 0;
}
