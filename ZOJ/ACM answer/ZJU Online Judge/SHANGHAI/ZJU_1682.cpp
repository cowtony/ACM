#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int n;

struct person_info
{
    int in , out;
};
map<string , person_info> person;
struct obj_info
{
    int low , high , tot , cnt;
};
map<string , obj_info> obj;

int curt;
struct event
{
    int type;
    string person , obj;
    int price;
    int mark;
} list[1010];

string pe , oj , tmp;
int p , type;

person_info empty_person;
obj_info empty_obj;

map<string , person_info>::iterator p_person;
map<string , obj_info>::iterator p_obj;

void renew(int seller , int buyer)
{
    list[seller].mark = list[buyer].mark = 1;
    int pp = (list[seller].price + list[buyer].price) / 2;
    person[list[seller].person].out += pp;
    person[list[buyer].person].in += pp;
    p_obj = obj.find(list[seller].obj);
    p_obj->second.tot += pp;
    p_obj->second.cnt ++;
    if(p_obj->second.low == 0 || p_obj->second.low > pp)
    {
        p_obj->second.low = pp;
    }
    if(p_obj->second.high == 0 || p_obj->second.high < pp)
    {
        p_obj->second.high = pp;
    }
}

void process_line()
{
    cin >> pe >> tmp >> oj >> p;
    if(tmp == "SELL") type = -1;
    else type = 1;

    if(person.find(pe) == person.end())
    {
        person.insert(make_pair(pe , empty_person));
    }
    if(obj.find(oj) == obj.end())
    {
        obj.insert(make_pair(oj , empty_obj));
    }

    list[curt].type = type;
    list[curt].person = pe;
    list[curt].obj = oj;
    list[curt].price = p;

    if(type < 0)
    {
        // sell
        int highest , k;
        highest = p - 1; k = -1;

        for(int i=0; i<curt; i++)
        {
            if(! list[i].mark && list[i].person != pe && list[i].obj == oj)
            {
                if(list[i].type > 0 && list[i].price > highest)
                {
                    highest = list[i].price;
                    k = i;
                }
            }
        }
        if(k < 0) list[curt].mark = 0;
        else  renew(curt , k);
    }
    else
    {
        // buy
        int lowest , k;
        lowest = p + 1; k = -1;
        for(int i=0; i<curt; i++)
        {
            if(! list[i].mark && list[i].person != pe && list[i].obj == oj)
            {
                if(list[i].type < 0 && list[i].price < lowest)
                {
                    lowest = list[i].price;
                    k = i;
                }
            } 
        }
        if(k < 0) list[curt].mark = 0;
        else  renew(k , curt);
    }
}

int main()
{
    freopen("in.txt" , "r" , stdin);    
    freopen("myout.txt" , "w" , stdout);

    empty_person.in = empty_person.out = 0;
    empty_obj.low = empty_obj.high = empty_obj.tot = empty_obj.cnt = 0;

    while(cin >> n , n)
    {
        person.clear();
        obj.clear();

        for(curt=0; curt<n; curt++)
        {
            process_line();
        }

        for(p_obj=obj.begin(); p_obj != obj.end(); p_obj++)
        {
            if(p_obj->second.cnt == 0) continue;
            cout << p_obj->first << " " << p_obj->second.low
            << " " << p_obj->second.tot / p_obj->second.cnt
            << " " << p_obj->second.high << endl;

        }
        cout << "--" << endl;

        for(p_person = person.begin(); p_person != person.end(); p_person++)
        {
            cout << p_person->first
            << " " << p_person->second.in
            << " " << p_person->second.out
            << endl;
        }
    
        cout << "----------" << endl;
    }    

    return 0;
}