/*
统计输入的一段话中的空格，连续奇数个空格记为0，连续偶数个空格记为1，最后得到的二进制表五个一组对应明文字母输出

直接做，需要点技巧，用getchar读入

关键词：字符串，密码转换 
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    char input,space=0;
    vector<int> code;
    
    while(input=getchar())
    {
        if(input=='#')break;
        
        if(input==' ')space++;
        else
        {
            if(space>0)
            {
                if(space%2==0)code.push_back(1);
                else code.push_back(0);
            }
            space=0;
        }
        if(input=='*')
        {
            int least=(code.size()+4)/5*5-code.size();
            for(int i=0;i<least;i++)
                code.push_back(0);
                
            string s;
            for(int i=0;i<code.size();i+=5)
            {
                int c=code[i]*16+code[i+1]*8+code[i+2]*4+code[i+3]*2+code[i+4];
                switch(c)
                {
                    case 0 :s+=' ';break;
                    case 27:s+='\'';break;
                    case 28:s+=',';break;
                    case 29:s+='-';break;
                    case 30:s+='.';break;
                    case 31:s+='?';break;
                    default:s+='A'+c-1;
                }
            }
            cout<<s<<endl;
            code.clear();
        }
    }
    
    //while(1);
}
