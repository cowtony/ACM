#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct info{
	string name;
	int HP, Power, Amount, Cool, Armor,Inter;
};

info a,b;

int Fight(){ 
	a.Inter = b.Inter = 0;
	int hit1 = (a.Power - b.Armor) * a.Amount;
	if (hit1 < 1) hit1 = 1;

	int hit2 = (b.Power - a.Armor) * b.Amount;
	if (hit2 < 1) hit2 = 1;

	while(true){
		a.Inter = (a.Inter + 1) % a.Cool;
		if (a.Inter == 0){
			b.HP -= hit1;
		}
		b.Inter = (b.Inter + 1) % b.Cool;
		if (b.Inter == 0){
			a.HP -= hit2;
		}

		if (a.HP <= 0 && b.HP <= 0) return 0;
		if (a.HP <= 0) return 2;
		if (b.HP <= 0) return 1;		
	}
}

int main(){
	int ret;
	while (cin >> a.name >> a.HP >> a.Armor >> a.Cool >> a.Amount >> a.Power){
		cin >> b.name >> b.HP >> b.Armor >> b.Cool >> b.Amount >> b.Power;		

		ret = Fight();
		if (ret == 1)
			cout << a.name << " Survive!" << endl;
		else if (ret == 2)
			cout << b.name << " Survive!" << endl;
		else cout << "All Die!" << endl;
	}

	return 0;
}
