/*
求出满足a^3=b^3+c^3+d^3且a<=200,b,c,d>1的所有整数解，按a,b,c,d升序排列

用四个for循环穷举，为了省时间，先用数组存下1至200的立方值

关键词：数学题，简单题
*/
#include<iostream>
using namespace std;

int main()
{
    int cube[201];
    int a,b,c,d;
    
    for(int i=1;i<=200;i++)
        cube[i]=i*i*i;         //事先存下立方的值

    for(a=2;a<=200;a++)        //a是2到200
        for(b=2;b<a;b++)       //b,c,d<a且b<=c<=d
            for(c=b;c<a;c++)
                for(d=c;d<a;d++)
                    if(cube[a]==cube[b]+cube[c]+cube[d])printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);

    //while(1);
    return 0;
}
