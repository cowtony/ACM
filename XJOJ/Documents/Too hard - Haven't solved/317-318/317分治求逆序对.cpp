#include<iostream>
using namespace std;

void sort(int data[],int n)
{
    int length=n/2;
    int temp[250000];
    int k=0;
    int i=0,j=length;
    while(i<length && j<n)
    {
        if(data[i]<data[j])
            temp[k++]=data[i++];
        else
            temp[k++]=data[j++];
    }
    while(i<length)
        temp[k++]=data[i++];
    while(j<n)
        temp[k++]=data[j++];
    
    memcpy(data,temp,sizeof(int)*n);
}

int couple(int data[],int n)
{
    if(n<2)return 0;
    
    int length=n/2;
    int B1=couple(data,length);
    int B2=couple(data+length,n-length);
        
    int B1B2=0;
    int j=length;
    for(int i=0;i<length;i++)
    {
        while(data[i]>data[j] && j<n)j++;
        B1B2=(B1B2+j-length)%1000000;
    }
    sort(data,n);

    return (B1+B2+B1B2)%1000000;
}

int main()
{    
    int n;
    int v[250000];
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d %d",v+i,v+i);
        
    printf("%d",couple(v,n));
    
    //while(1);
}
