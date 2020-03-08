#include <iostream> 
#include <string> 
//#include <fstream> 
using namespace std; 
string word; 
int word_l,poi; 
int main() 
{//ifstream cin("input.txt"); 
//ofstream cout("output.txt"); 
poi=0;word=""; 
while(cin>>word) 
{word_l=word.length(); 
if(word=="<br>"){cout<<endl;poi=0;} 
if(word=="<hr>") 
{if(poi!=0)cout<<endl; 
for(int i=1;i<=80;i++)cout<<"-"; 
cout<<endl; 
poi=0; 
} 
if(word!="<br>" && word!="<hr>") 
{if(poi==0){cout<<word;poi=word_l;} 
else 
if(poi>0 && poi+word_l+1<=80){cout<<" "<<word;poi+=word_l+1;} 
else 
if(poi>0 && poi+word_l+1> 80){cout<<endl<<word;poi=word_l;} 
} 
} 
cout<<endl; 
}