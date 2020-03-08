#include <iostream>
#include <string>
using namespace std;


int main(){
char set[28];
char plaintext[100][70] = {0};
int k;
int ciphercode[70] ={0};
int count[100] = {0};
int count2 = 0;
char* ciphertext = new char[70];

set[0] = '_';
set[27] = '.';
set[1] = 'a';
for(int i=2; i<27; i++)
{
   set[i] = set[i-1]+1;
}
for(int i=0; i<70; i++)
   ciphertext[i] = 0;


while(cin>>k&&k!=0)
{  
   cin>>ciphertext;
   for(int i=0; i<70; i++)
   {
    if(ciphertext[i]!=0)
     count[count2]++;
    else break;
   }
   for(int j=0; j<count[count2]; j++)
   {
    if(ciphertext[j]=='.')
     ciphercode[j] = 27;
    if(ciphertext[j]=='_')
     ciphercode[j] = 0;
    if(ciphertext[j]=='a')
     ciphercode[j] = 1;
    else if(ciphertext[j]>'a'&&ciphertext[j]<='z')
     ciphercode[j] = 1+ciphertext[j]-'a';
    int tmp = (ciphercode[j]+j)%28;
    
    plaintext[count2][k*j%count[count2]] = set[tmp];
   }
   count2++;
  
  
}
for(int i=0; i<count2;i++)
{
   for(int j=0; j<count[i]; j++)
    cout<<plaintext[i][j];
   cout<<endl;
}


}
