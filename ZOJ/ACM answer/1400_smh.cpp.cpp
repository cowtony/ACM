#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<math.h>

struct team{char name[30]; int time[7]; int solve, total, geo;}tm[21];
int cmp(team& t1, team& t2)
{
	if (t1.solve==t2.solve){
		if (t1.total==t2.total){
			if (t1.geo==t2.geo) return 0;
			else if (t1.geo>t2.geo) return 1;
			return -1;
		} else {
			if (t1.total>t2.total) return 1;
			return -1;
		}
	} else {
		if (t1.solve<t2.solve) return 1;
		return -1;
	}
}
int cmpwithname(team& t1, team& t2)
{
	if (t1.solve==t2.solve){
		if (t1.total==t2.total){
			if (t1.geo==t2.geo){
				if (strcmp(t1.name, t2.name)>0) return 1;
				return -1;
			}else if (t1.geo>t2.geo) return 1;
			return -1;
		} else {
			if (t1.total>t2.total) return 1;
			return -1;
		}
	} else {
		if (t1.solve<t2.solve) return 1;
		return -1;
	}
}
void out(team& t, int rank)
{
	if (rank<10) cout<<"0";
	cout<<rank<<" ";
	cout.unsetf(ios::right);
	cout.setf(ios::left);cout.fill(' ');
	cout<<setw(10)<<t.name;
	cout.unsetf(ios::left); cout.setf(ios::right);
	cout<<" "<<t.solve;
	cout<<setw(5)<<t.total;
	cout<<setw(4)<<t.geo;
	for (int i=0; i<7; i++)
		cout<<setw(4)<<t.time[i];
	cout<<endl;
}

int main()
{
	int cnt=1, sum, i, j;
	double acc;
	while(cin>>sum){
		if (sum==0) break;
		for (i=0; i<sum; i++){
			cin>>tm[i].name;
			tm[i].solve=0; tm[i].geo=0; acc=0.0; tm[i].total=0;
			for (j=0; j<7; j++){
				cin>>tm[i].time[j];
				tm[i].total+=tm[i].time[j];
				if (tm[i].time[j]>0){
					tm[i].solve++;
					acc+=log(tm[i].time[j]);
				}
			}
			if (tm[i].solve!=0) tm[i].geo=exp(acc/(float)tm[i].solve)+0.5;
		}
		cout<<"CONTEST "<<cnt<<endl;
		team temp;
		for (i=0; i<sum; i++){
			for (j=sum-1; j>i; j--){
				if (cmpwithname(tm[j], tm[j-1])<0){
					temp=tm[j]; tm[j]=tm[j-1]; tm[j-1]=temp;
				}
			}
		}
		int rank=1;
		out(tm[0], rank);
		for (i=1; i<sum; i++){
			if (cmp(tm[i], tm[i-1])!=0) rank=i+1;
			out(tm[i], rank);
		}
	}
	return 0;
}

