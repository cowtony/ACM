#include <iostream.h> 
int main(int argc, char* argv[]) 
{ 
  int n,k,s; 
  while (cin>>n) 
  { 
    k=1; 
    s=0; 
    while (1) 
    { 
      k%=n;s++; 
      if (k==0) 
        break; 
      k*=10; 
      k++; 
    } 
    cout<<s<<endl; 
  } 
  return 0; 
} 
