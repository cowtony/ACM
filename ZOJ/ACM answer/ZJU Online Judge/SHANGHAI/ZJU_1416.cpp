#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int n;
struct state
{
    int type;
    int delta;
    int lab;
    char variable;
} list[30];

bool cmp(const string& a , const string& b)
{
    if(a.length() != b.length()) return 0;
    for(int i=0; i<a.length(); i++)
    {
        if(tolower(a[i]) != b[i]) return 0;
    }
    return 1;
}

int str2int(const string& a)
{
    int ret = 0;
    for(int i=0; i<a.length(); i++)
    {
        ret = ret * 10 + a[i] - '0';
    }
    return ret;        
}

void init()
{
    string Line , tmp , a;
    cin >> n;
    getline(cin , Line);

    for(int i=0; i<n; i++)
    {
        getline(cin , Line);
        istringstream strin(Line);

        strin >> tmp;

        if(cmp(tmp , "dcl"))
        {
            list[i].type = 0;
            strin >> list[i].variable;
        }
        else if(cmp(tmp , "end"))
        {
            list[i].type = -1;            
        }        
        else if(cmp(tmp , "goto"))
        {
            strin >> a;
            if(strin >> tmp)
            {
                list[i].type = 5;
                list[i].variable = a[0];
                list[i].lab = str2int(tmp);
            }
            else
            {
                list[i].type = 55;
                list[i].lab = str2int(a);                
            }        
        }
        else if(cmp(tmp , "inc"))
        {
            list[i].type = 1;
            list[i].delta = 1;
            strin >> list[i].variable;
        }
        else if(cmp(tmp , "dec"))
        {
            list[i].type = 1;
            list[i].delta = -1;
            strin >> list[i].variable;
        }
        else
        {
            list[i].type = 10;
            list[i].variable = tmp[0];
            strin >> tmp;
            strin >> list[i].delta;
        }
    }
}

int stat[256];
// undefine -1
// define unused 0
// used 1
int value[256];

void solve()
{    
    int i;
    for(i=0; i<256; i++)
    {
        stat[i] = -1;
    }
    for(i=0; i<n; )
    {
        if(list[i].type == -1) break;
        if(list[i].type == 0)
        {
            if(stat[list[i].variable] == 0)
            {
                cout << i + 1 << " " << 1 << endl;
            }
            else
            {
                stat[list[i].variable] = 0;
                value[list[i].variable] = 0;        
            }
            i++;
            continue;
        }
        if(list[i].type ==55)
        {
            i = list[i].lab - 1;
            continue;
        }
        if(stat[list[i].variable] < 0)
        {
            cout << i + 1 << " " << 2 << endl;
            i++;
            continue;
        }
        if(list[i].type == 1)
        {
            value[list[i].variable] += list[i].delta;
			stat[list[i].variable] = 1;
            i++;
            continue;
        }
        if(list[i].type == 10)
        {
            value[list[i].variable] = list[i].delta;
			stat[list[i].variable] = 1;
            i++;
            continue;
        }
        if(value[list[i].variable] > 0)
        {
            i = list[i].lab - 1;
        }
        else i++;
    }
}

int main()
{
  //  freopen("in.txt" , "r" , stdin);
    int T , t;
    cin >> T;

    for(t=1; t<=T; t++)
    {
        cout << t << endl;
        init();
        solve(); 
    }

    return 0;
} 
