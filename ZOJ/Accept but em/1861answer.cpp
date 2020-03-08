#include<iostream>
#include<string>
using namespace std;

#define MAX 40

char s[MAX];

void init()
{//数组初始化
 int i;
 for(i=0;i<MAX;i++)
  s[i]=0;
}

int IsDscending(int tag)
{//判断s[MAX]是否是降序,从后向前长度逐渐增大判断,如果发现不是降序,返回最小长度
 int i,j,temp,length;
  for(i=tag;i>=0;i--)
  {
   if(s[i]=='2' || s[i]=='6')
   {
    length=tag-i+1;
    return length;
   }
   temp=i;
   if(s[temp]=='.')
    temp--;
   j=i-1;
   if( s[j]=='.')
    j--;
   if(j>=0 && s[i]>s[j])
    {
     length=tag-j+1;
     return length;
    }
  }
 return 0;
}

void sort(int tag,int length)
{//找到该排列的下一个位置
 int i,j,record=tag-length+1;
 char rec,temp;
 if(length==1)
 {
  if(s[tag]=='2')
   s[tag]='5';
  else if(s[tag]=='6')
   s[tag]='9';
  return;
 }
 rec='z';temp=s[record];
 for(i=tag;i>=tag-length+1;i--)
 {
  if(s[i]=='2' || s[i]=='5')
  {
   if('2'>temp)
    s[i]='2';
   else if('5'>temp)
    s[i]='5';
  }
  if(s[i]=='6' || s[i]=='9')
  {
   if('6'>temp)
    s[i]='6';
   else if('9'>temp)
    s[i]='9';
  }
  if(s[i]<rec && s[i]>temp && s[i]!='.' )
  {record=i;rec=s[i];}
 }
 rec=s[tag-length+1];
 s[tag-length+1]=s[record];
 s[record]=rec;
 if(length==2)
 {
  if(s[tag]=='9')
   s[tag]='6';
  else if(s[tag]=='5')
   s[tag]='2';
  return;
 }
 for(i=tag;i>tag-length+2;i--)
  for(j=i-1;j>tag-length+1;j--)
  {
   if(s[j]=='9')
    s[j]='6';
   else if(s[j]=='5')
    s[j]='2';
   if(s[i]=='9')
    s[i]='6';
   else if(s[i]=='5')
    s[i]='2';
   if(s[i]<s[j] && s[i]!='.' && s[j]!='.')
   {rec=s[i];s[i]=s[j];s[j]=rec;}
  }
  return;
}

int main()
{
 int i,tag,length;
 init();
 while(cin>>s)
 {
  if(s[0]=='.')
   return 0;
  tag=0;
  tag=strlen(s)-1;
  length=IsDscending(tag);
  if(length!=0)
  {
   sort(tag,length);
   for(i=0;i<=tag;i++)
    cout<<s[i];
    cout<<endl;
  }
  else 
   cout<<"The price cannot be raised."<<endl;
  init();
 }
 return 0;
}