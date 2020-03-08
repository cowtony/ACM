#include <iostream>
#include <cstdio>
#include <string>
#include <math.h>
using namespace std;

const double pi = 2 * acos(0);
struct persondat{
	string name;
	double speed , ac;
	double area  , p;
};

/*
The keeper stands on the ground, at middle of the gate, and can be assumed as a particle. As soon as the ball is kicked off, he jumps to the shoot point on the gate plane at a constant speed of 5 (m/s). If he reaches the point later than the ball does, it's a goal! Otherwise the ball would be caught.
Therefore the gate plane is divided into Goal-area (Ga) and Lost-area (La). 
 percentage of 1-(shoot-accuracy*5) of the player will shoot out off the target, and (shoot-accuracy*5)% will be on target. Shoot on target means each point inside the gate is equally likelyto be taken as the shoot point. The speed of the ball is shoot-power (m/s), and you can ignore the gravity. 

The keeper stands on the ground, at middle of the gate, and can be assumed as a particle. As soon as the ball is kicked off, he jumps to the shoot point on the gate plane at a constant speed of 5 (m/s). If he reaches the point later than the ball does, it's a goal! Otherwise the ball would be caught. Therefore the gate plane is divided into Goal-area (Ga) and Lost-area (La). 

You need to calculate the probability of a goal, that is, P=S(Ga)/(S(Ga)+S(La)), where of course, S(Ga)+S(La)=S(Gate). And more, please choose the players with the top 5 of the P's -- they are the best penalty kickers of the team. If two players' probabilities are equal, choose the alphabetically smaller name. Assume that there will never be two players with the same name.

A few tips of the football game: 
> the height of the gate, H=2.5 (m);
> the width of the gate, W=7.5 (m);
> the distance from the penalty spot to the gate, D=11 (m). 
*/

persondat List[20];

double calc(persondat A){
	//double L = 11 / A.speed * 5;
	double L=sqrt(25.0 * 121.0/(A.speed * A.speed - 25.0));
	if(L <= 2.5){
		return pi * L * L / 2;
	}
	if(L >= sqrt(2.5 * 2.5 + 3.75 * 3.75)){
		return 2.5 * 7.5;
	}
	if(L <= 3.75){
		double sita = acos(2.5 / L) * 2;
		return L * L / 2 * (pi - sita) + sqrt(L * L - 2.5 * 2.5) * 2.5;
	}
	double alpha = acos(2.5 / L);
	double beta = acos(3.75 / L);
	double sita = pi / 2  - alpha - beta;
	return L * L * sita + sqrt(L * L - 2.5 * 2.5) * 2.5 + sqrt(L * L - 3.75 * 3.75) * 3.75 ;
}

int main(){
	//freopen("in.txt" , "r" , stdin);
	int CaseNo = 0;
	string str;
	int i , j;
	persondat tmp;
	while(true){
		cin >> str;
		if (str == "END") break;
		List[0].name = str;
		cin >> List[0].speed >> List[0].ac;		
		for(i = 1; i < 11; i++)
			cin >> List[i].name >> List[i].speed >> List[i].ac;
		for(i = 0; i < 11; i++){
			List[i].area = calc(List[i]);
			List[i].p =(1 - (List[i].area / 2.5 / 7.5)) * List[i].ac * 5;
			
		}	
		/*
		          if (s[i]<=5||25.0*121.0>=(s[i]*s[i]-25.0)*(w*w+h*h)) break;
            double r=sqrt(25.0*121.0/(s[i]*s[i]-25.0));
            if (r<=h) sum[i]=r*r*pi/2;
            else if (r<=w) {
                double theta=pi/2-acos(h/r);
                sum[i]=r*r*theta+h*sqrt(r*r-h*h);
            }
            else {
                double theta=pi/2-acos(h/r)-acos(w/r);
                sum[i]=r*r*theta+h*sqrt(r*r-h*h)+w*sqrt(r*r-w*w);
            }
            sum[i]=1-sum[i]/(w*h*2);
            sum[i]*=a[i]*5;
            if (sum[i]<0) sum[i]=0;
        }
		*/
		//            sum[i]=1-sum[i]/(w*h*2);            sum[i]*=a[i]*5;
		for(i = 0; i < 5; i++)
			for(j = i+1; j < 11; j++)
				if((List[j].p > List[i].p) ||  (fabs(List[j].p - List[i].p) < 1e-10 && List[j].name < List[i].name)){
					tmp = List[i]; List[i] = List[j]; List[j] = tmp;
				}
		cout << "Case " << ++CaseNo << ":" << endl;
		cout.setf(ios::floatfield,ios::fixed);
		cout.precision(2);
		for(i = 0; i < 5; i++)
			cout << List[i].name << " " << List[i].p << "%" << endl;
		cout << endl;
	}

	
	return 0;
}
