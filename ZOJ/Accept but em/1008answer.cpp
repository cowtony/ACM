#include <stdio.h>

int g=0;         //Game index 
int n=0;         //Puzzle size 
int q=0;         //How many different types of squares 
int square[25][4];   //Source squares 
int count[25];      //Quantity of a certain type of squares 
int table[25];      //Solution

int place(int pos) 
{ 
 int i; 
 if(pos==n*n) 
  return 1; 
 for(i=0; i<q; i++) 
 { 
  if(count[i]==0) 
   continue; 
  if(pos%n!=0) 
   if(square[table[pos-1]][1]!=square[i][3]) 
    continue; 
  if(pos/n!=0) 
   if(square[table[pos-n]][2]!=square[i][0]) 
    continue; 
  table[pos]=i; 
  count[i]--; //!!!
  if(place(pos+1)==1) 
   return 1; 
  count[i]++; ///!!!!
 }


 return 0; 
}

int main() 
{ 
 int i, j; 
 int t, r, b, l;   //Temporary variables for input (top, right, bottom, left)

 g=0; 
 q=0;

 while(1) 
 { 
  g++; 
  scanf("%d", &n); 
  if(n==0) 
   break; 
  q=0; 
  for(i=0; i<n*n; i++) 
  { 
   scanf("%d %d %d %d", &t, &r, &b, &l); 
   j=0; 
   while(j<q) 
   { 
    if(square[j][0]==t && square[j][1]==r && square[j][2]==b && square[j][3]==l) 
    { 
     count[j]++; 
     break; 
    } 
    j++; 
   } 
   if(j==q) 
   { 
    square[j][0]=t; 
    square[j][1]=r; 
    square[j][2]=b; 
    square[j][3]=l;

    count[j]=1; 
    q++; 
   } 
  }

  if(g>1) 
   printf("\n");

  if(place(0)==1) 
   printf("Game %d: Possible\n", g); 
  else 
   printf("Game %d: Impossible\n", g); 
 }

 return 0; 
} 