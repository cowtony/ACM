#include <iostream.h>
#include <string.h>

char str[81];
bool prevComma[81],Comma[81],availableComma[81];

long long prevArray[81],Array[81],availableArray[81];

//none: temparory,prev: new sequence, available: old sequence
int i,len,pos,prevLen,availableLen;

long long power,last,test;

bool flag;

bool cmpArray(long long *c,long long *d,int lenC,int lenD)
{
  int i=lenC-1;
  int j=lenD-1;
  while (i>=0&&power>=0)
  {
    if (c[i]>d[j])
      return true;
    else if (c[i]<d[j])
      return false;
    i--;
    j--;
  }
  return false;
}
//compare arrays from the first value
void createSequence(long long test,int pos,int arrayLen)
{
  if (pos<0&&cmpArray(Array,prevArray,arrayLen,prevLen))
  {
    flag=true;
    for (int i=0;i<81;i++)
    {
      prevComma[i]=Comma[i];
      prevArray[i]=Array[i];
    }
    prevLen=arrayLen;
    return ;
  }

  long long power=1;
  long long make=0;
  for (int i=pos;i>=0;i--)
  {
    if (make+(str[i]-48)*power>=test)
      return;
    make+=(str[i]-48)*power;
    Comma[i]=1;
    Array[arrayLen]=make;

    createSequence(make,i-1,arrayLen+1);

    Array[arrayLen]=0;
    Comma[i]=0;
    power*=10;
  }
}//create the sequence
int main()
{
  cin>>str;
  while (strlen(str)!=1 || str[0]!='0')
  {
    flag=false;
    len=strlen(str);
    pos=len-1;
    prevLen=1;
    test=last=0;
    power=1;
    availableLen=1;
    for (i=0;i<81;i++)
    {
      availableArray[i]=0;
      availableComma[i]=0;
    }//initialize
    while (pos)
    {
      test+=power*(str[pos]-48);
      if (flag&&test>last)
        break;
      for (i=0;i<81;i++)
      {
        prevComma[i]=0;
        prevArray[i]=Array[i]=0;
      }
      last=test;
      Comma[pos+1]=0;
      Comma[pos]=1;
      createSequence(test,pos-1,0);
      if (flag&&cmpArray(prevArray,availableArray,prevLen,availableLen))
      {
        for (i=0;i<81;i++)
        {
          availableArray[i]=prevArray[i];
          availableComma[i]=prevComma[i];
        }
        availableLen=prevLen;
      }//choose the better from the new sequence and the old one
      pos--;
      power*=10;
    }
    for (i=0;i<len;i++)
    {
      if (availableComma[i]&&i)
        cout<<",";
      cout<<str[i];
    }
    cout<<endl;
    cin>>str;
  }
  return 0;
}
//-------------------------------------------------

