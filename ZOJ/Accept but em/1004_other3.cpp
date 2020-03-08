#include<iostream.h>
#include<string.h>
#include<conio.h>
const int max=5;
static int q1,q2;
char str[max][2][20];
int solve[max][10][20];
static int flag[20];
static int total[max];
int po[20];
void doing(int p,int wh,int len){
  if(p==len){
	int tt;int t_flag2=q2,t_flag1=q1;
	for( tt=p;tt<=len-q2-1;tt++){
	  if(str[wh][1][q1-1]!=str[wh][2][q2]) break;
	  else{ po[p++]=1;
			q1--;q2++;}}
	if(tt==len-q2){total[wh]++; for(int pp=0;pp<len;pp++) solve[wh][total[wh]][pp]=po[pp];return;}
	else{q1=t_flag1;q2=t_flag2;return;}
	}
	int temp_f=0;
   for(int ee=1;ee<=2;ee++){
  if(flag[p]==1){
	if(str[wh][1][q1]==str[wh][2][q2]){temp_f=1; po[p]=1;q2++;}}
  else{ po[p]=0;q1++;}
  flag[p]=1;
  cout<<p<<"\t"<<po[p]<<"\t"<< q1<<"\t"<<q2<<endl;
  getch();
  doing(p+1,wh,len);
  if(temp_f==1) {q2--;temp_f=0;}
  else q1--;
  }
}


int main(){
  int k=1;
  int len1[max];int len2;
   while(cin>>str[k][1]>>str[k][2])k++;
  int i;

  for(i=1;i<k;i++){
  cout<<i<<str[i][1]<<"\t"<<str[i][2]<<endl;
   total[i]=0;
   len1[i]=strlen(str[i][1]);      len2=strlen(str[i][2]);
   cout<<len1[i]<<len2<<endl;
  if(len1[i]==len2) doing(0,i,len1[i]);
  }
 for(int tt=1;tt<k;tt++){
  cout<<"[\n";
 for(int qq=1;qq<=total[tt];qq++){
 for(int pp=0;pp<len1[i];pp++){
  if(solve[tt][qq][pp]==1) cout<<"o  ";
  else cout<<"i  "; }
 cout<<endl;}
 cout<<"]\n";}
 return 1;
}