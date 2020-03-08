/*
判断所给小写字符串是否符合要求，一：要求有元音字母，二：不能有三个元音或辅音字母相连，三：除"ee","oo"外不能有双写字母

编一个判断元音字母的函数，然后依题意做既可

关键词：字符串 
*/
#include<iostream>
#include<cstring>
using namespace std;

bool vowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
    else return false;
}
 
int main()
{
    string word;
    bool judge;
    
    while(cin>>word)
    {
        if(word=="end")return 0;
        
        judge=false;
        for(int i=0;i<word.length();i++)
            if(vowel(word[i])==true)judge=true;

        if(word.length()>2)
        for(int i=0;i<word.length()-2;i++)
        {
            if(vowel(word[i])==true &&vowel(word[i+1])==true &&vowel(word[i+2])==true )judge=false;
            if(vowel(word[i])==false&&vowel(word[i+1])==false&&vowel(word[i+2])==false)judge=false;
        }

        if(word.length()>1)
        for(int i=0;i<word.length()-1;i++)
        {
            if(word[i]==word[i+1]&&word[i]!='e'&&word[i]!='o')judge=false;
        }

        if(judge==true)cout<<"<"<<word<<"> is acceptable."<<endl;
            else cout<<"<"<<word<<"> is not acceptable."<<endl;
    }
}
