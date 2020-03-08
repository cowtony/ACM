//Counterfeit Dollar
#include<iostream.h>
#include<string.h>

int judge[3][13];
int weight[13];         	//weight of each coin    weight[0] no uesd
int p[2]={0,2};			//lighter=0 Normal=1 heaver=2
char ballance[3][5];
void ini()
{
	int i,k;
	char ch; char str[5];
	memset(judge,0,sizeof(judge));
	for(i=0; i<3; i++){
		for (k=0; k<4; k++){	//left side ----->  -1
			cin>>ch;
			judge[i][ch-64]=-1;
		}
		for (k=0; k<4; k++){	//right side----->   1
			cin>>ch;
			judge[i][ch-64]=1;
		}
		cin>>str;		//up(-1) even(0) or down(1)
		for (k=0; k<3; k++){
			if (!strcmp(ballance[k],str)) {
				judge[i][0]=k-1;
				break;
			}
		}
	}
}

int found()
{
	int left, right;
	int t,i;
	for (t=0; t<3; t++){
		left=0; right=0;
		for (i=1; i<13;i++){		//accumulate weight of each
			if (judge[t][i]==-1) left+=weight[i];
			if (judge[t][i]== 1) right+=weight[i];
		}
		i=right-left;			//delta
		if (i>0&&judge[t][0]>0) continue;
		if (i==0&&judge[t][0]==0) continue;
		if (i<0&&judge[t][0]<0) continue;
		return 0;
	}
	return 1;
}
void print(int id, int stat)
{
	cout<<char(id+64)<<" is the counterfeit coin and it is ";
	if (stat==0) cout<<"light."<<endl;
	else         cout<<"heavy."<<endl;
}
int main()
{
	int total, i, j, k;
	strcpy(ballance[0],"up\0");
	strcpy(ballance[1],"even\0");
	strcpy(ballance[2],"down\0");
	cin>>total;
	for(int qq=0;qq<3;qq++)
	for(int tt=0;tt<13;tt++)
		judge[qq][tt]=0;
   for (k=0; k<total; k++){
	ini();
	for (i=0; i<13; i++) weight[i]=1;
	for (i=1; i<13; i++) {
		for (j=0; j<2; j++){
			weight[i]=p[j];	 //when j==0 weight=0, means lighter
			if (found()) print(i,j);
			weight[i]=1;
		}

	}


   }
	return 0;
}