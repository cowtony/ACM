#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{

vector<string> tabby;
string input;
int count=1;
bool status = false;
while(cin >> input)
{
if(input=="9")
{
   if(status==false)
    cout << "Set " << count << " is immediately decodable" << endl;
   else
    cout << "Set " << count << " is not immediately decodable" << endl;
   tabby.clear();
   count++;
   status = false;
}
else
{
   if(status==false)
   {
    for(int i=0; i<tabby.size(); i++)
    {
     if(input.find(tabby[i])==0)
     {
      status = true;
      break;
     }
    }
    tabby.push_back(input);
   }
}
}

}
