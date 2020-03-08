#include<iostream>
#include<math.h>
using namespace std;

int main(){
int color_set[16][3];
int color_mapped[100][3];
int result[100][3];
double d=0;
int x=0;
for(int i=0; i<16; i++)
    cin>>color_set[i][0]>>color_set[i][1]>>color_set[i][2];
  
int count=0;
while(cin>>color_mapped[count][0]>>color_mapped[count][1]>>color_mapped[count][2]&&color_mapped[count][0]!=-1&&color_mapped[count][1]!=-1&&color_mapped[count][2]!=-1)
   count++;

for(int i=0; i<count; i++)
{
   double min=65535;
   for(int j=0; j<16; j++)
   {
    d = sqrt((double)((color_mapped[i][0]-color_set[j][0])*(color_mapped[i][0]-color_set[j][0])+(color_mapped[i][1]-color_set[j][1])*(color_mapped[i][1]-color_set[j][1])+(color_mapped[i][2]-color_set[j][2])*(color_mapped[i][2]-color_set[j][2])));
    if(d<min)
    {
     min = d;
     x = j;
    }
   } 
   result[i][0] = color_set[x][0];
   result[i][1] = color_set[x][1];
   result[i][2] = color_set[x][2];

}
for(int j=0; j<count; j++)
{
   cout<<"("<<color_mapped[j][0]<<","<<color_mapped[j][1]<<","<<color_mapped[j][2]<<") maps to ("<<result[j][0]<<","<<result[j][1]<<","<<result[j][2]<<")"<<endl;
}

   


}
