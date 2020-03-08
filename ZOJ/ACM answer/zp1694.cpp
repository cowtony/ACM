//#define fin cin 
#include <fstream> 
#include <iostream>
#include <string>

using namespace std;
char st[20];

int icpy( int r, int h )
{
  int ta, t = 0, k = 1;
  for ( int i = h; i > r; i-- )
  {
    ta = st[i - 1] - '0';
    t += ta * k;
    k *= 10;
  }
  return t;
}

int main()
{
  //ifstream fin("c:\\in1694.txt");
  int mx, l, s, i, sum, max, ty, r, h;
  int p[10], q[10];
  cin >> mx;
  cin >> st;
  while ( mx != 0 || st[0] != '0' )
  {
    l = strlen( st );
    s = 0;
    for ( i = 0; i < l; i++ )
    s += st[i] - '0';
    if ( s > mx )
      cout << "error" << endl;
    else
    if (l==1)
      cout<<s<<' '<<s<<endl;
    else
    {
      for ( i = 0; i <= l; i++ ) p[i] = 1;
      p[1] ++;
      max = 0; ty = 0;
      while ( 1 )
      {
        p[1] --;
        i = 1;
        while ( 1 )
        {
          if ( p[i] < 0 && i < l )
          { p[i + 1] --; p[i] = 1; i++; }
          else
            break;
        }
        if ( i < l )
        {
          p[l] = 1;
          r = 0; h = 1; sum = 0;
          while ( h <= l )
          {
            while ( !p[h] ) h++;
            sum += icpy( r, h );
            if ( sum > mx ) break;
            r = h; h++;
          }
          if ( sum <= mx )
            if ( sum == max )
              ty = 1;
            else if ( sum > max )
            {
              max = sum; ty = 0;
              for ( i = 0; i <= l; i++ )
                q[i] = p[i];
            }
        }
        else
          break;
      }
      if ( ty )
        cout << "rejected" << endl;
      else
      {
        cout << max;
        r = 0; h = 1;
        while ( h <= l )
        {
          while ( !q[h] ) h++;
          cout << ' ';
          for ( i = r; i < h; i++ )
            cout << st[i];
          r = h; h++;
        }
        cout << endl;
      }
    }
    cin >> mx;
    cin >> st;
  }
  return 0;
}

