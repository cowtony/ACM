#include <stdio.h>

struct teamdat{
	char name[100];
	int prob , time;
} List[100];

int n;

bool comp(const teamdat& a , const teamdat& b){
	if(a.prob == b.prob) return a.time < b.time;
	return a.prob > b.prob;
}

int main(){
	scanf("%d" , &n);
	int s , t , i , j;
	for(i = 0; i<n; i++){
		scanf("%s" , List[i].name);
		List[i].prob = List[i].time = 0;
		for(j = 0; j < 4; j++){
			scanf("%d%d" , &s , &t);
			if(t > 0){
				List[i].prob ++;
				List[i].time += t + (s - 1) * 20;
			}
		}
	}

	int k = 0;
	for(i = 1; i < n; i++){
		if(comp(List[i] , List[k])) k = i;
	}

	printf("%s %d %d\n" , List[k].name , List[k].prob , List[k].time);	

	return 0;
}