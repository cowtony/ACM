/*题意：

给出两个字符串，第一个是输入，第二个是输出，以栈的方式输入输出，i表示输入，o表示输出，输出所有io解，参照题目例子。
思路：

这并不能算是一道字符串题，准确是一道栈的回溯题，第一次尝试用了STL函数，果然很好很强大，按照题目要求，知道题目是优先输入的，所以优先进栈，当栈进完后再看是否符合出栈条件，不行就回溯到上一步，继续验证，直到输入输出全部到字符串的长度时输出，然后还原上次操作，继续。。。
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string s1,s2;
stack<char> cs;
vector<char> io;
int l;
void prints()
{
 for (int i=0;i<io.size();i++)
  cout<<io[i]<<" ";
 cout<<endl;
}
void dfs(int i,int o)
{
 if (i==l&&o==l)
  prints();
 if (i<l)
 {
  cs.push(s1[i]);
  io.push_back('i');
  dfs(i+1,o);
  cs.pop();
  io.pop_back();
 }
 if (o<i&&o<l&&cs.top()==s2[o])
 {
  char t=cs.top();
  cs.pop();
  io.push_back('o');
  dfs(i,o+1);
  cs.push(t);
  io.pop_back();
 }
}
int main()
{
 while (cin>>s1>>s2)
 {
  l=s1.length();
  string t1=s1,t2=s2;
  sort(t1.begin(),t1.end());
  sort(t2.begin(),t2.end());
  cout<<"[\n";
  if (t1==t2)
   dfs(0,0);
  cout<<"]\n";
 }
 return 0;
}