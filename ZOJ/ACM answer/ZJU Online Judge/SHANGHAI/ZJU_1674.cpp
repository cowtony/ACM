#include <iostream>
#include <string>
#include <map>
using namespace std;

int n , m;
string name[1000];
int father[1000] , level[1000];

map<string , int> Map;

void Init()
{
    getline(cin , name[0]);
    father[0] = -1; level[0] = 0;
    
    Map[name[0]] = 0;
        
    int p = 0;
    int i , k;
    
    for(i=1; i<n; i++)
    {
        getline(cin , name[i]);
        for(k = 0; name[i][0] == ' '; k++)
        {
            name[i].erase(0 , 1);
        }
        Map[name[i]] = i;
        while(level[p] + 1 != k)
        {
            p = father[p];
        }
        level[i] = k;
        father[i] = p;
        p = i;
    }
}

string a , b , relation , tmp;
int ida , idb;

bool check(int a , int b)
{
    while(a >= 0)
    {
        if(a == b) return 1;
        a = father[a];
    }
    return 0;
}

void Solve()
{
    bool flag;
    while(m--)
    {       
        cin >> a >> tmp >> tmp >> relation >> tmp >> b;
        b.erase(b.length() - 1 , 1);   
        
        ida = Map[a]; idb = Map[b];
    
        if(relation == "child")
        {
            flag = (father[ida] == idb);
        }
        else if(relation == "parent")
        {
            flag = (father[idb] == ida);
        }
        else if(relation == "sibling")
        {
            flag = (father[ida] == father[idb]);
        }
        else if(relation == "descendant")
        {
            flag = check(ida , idb);
        }
        else flag = check(idb , ida);
        
        if(flag) cout << "True" << endl;
        else cout << "False" << endl;
    }
}

int main()
{
    while(1)
    {
        cin >> n >> m;
        if(!n) break;
        Map.clear();        
        cin.get();
        
        Init();
        Solve();
        
        cout << endl;
    }
    
    return 0;
}
