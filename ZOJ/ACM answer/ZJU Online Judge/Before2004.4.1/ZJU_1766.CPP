#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> List;
string buf;

inline char lower(char k){
	return k + 'a' - 'A';
}

void doit(){
	string tmp = "";
	int l = buf.length();
	for(int i=0; i<l; i++){
		if((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z') || (buf[i] >= '0' && buf[i] <= '9') ){
			
			if(buf[i] >= 'A' && buf[i] <= 'Z')
				tmp = tmp + lower(buf[i]);
			else tmp = tmp + buf[i];
		}
		else{
			if(tmp != ""){
				List.push_back(tmp);
				tmp = "";
			}			
		}
	}
	if(tmp != "") List.push_back(tmp);
}

void solve(){
	int best = 1;
	int cur = 1;
	int i;
	for(i = 1; i < List.size(); i ++){
		if(List[i] == List[i-1]){
			cur++;
			if(cur > best) best = cur;
		}
		else{
			cur = 1;
		}
	}
	if(best == 1){
		cout << "1 occurrences" << endl;
		for(i=0; i<List.size(); i++) cout << List[i] << endl;
		return;
	}
	cout << best << " occurrences" << endl;
	cur = 1;
	for(i = 1; i < List.size(); i++){
		if(List[i] == List[i-1]){
			cur++;
			if(cur == best){
				cout << List[i] << endl;
			}
		}
		else{
			cur = 1;
		}
	}
}

int main(){		
	List.clear();
	while(cin >> buf){
		doit();		
	}
	sort(&List[0] , &List[List.size()]);
	solve();

	return 0;
}