//https://dmoj.ca/problem/ccc13s4
#include <iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<vector<int> > tall(1000001);
    bool taller[1000001]={false};
bool talle(int boy, int boo)
{
    taller[boy] = true;
    if(boy == boo) return true;
    int counter=0;
    for(int i = 0; i < tall[boy].size(); i++)
    {
         if(taller[tall[boy][i]] == false)
         {
             if(talle(tall[boy][i],boo) == true)
             {
                 counter+=1;
             }

        }
    }
    if(countmysins == 0)return false;
    else return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie();
    int n,m;
    cin >> n>>m;
    for( int i = 0; i < m; i++)
    {
        int s,d;
        cin >> s >> d;
        tall[s].push_back(d);
    }
    int tallPerson,shortPerson;
    cin >> tallPerson >> shortPerson;
    if(talle(tallPerson,shortPerson) == true ) {cout << "yes";}
    else {
            memset(taller,false,1000001);
    if(talle(shortPerson,tallPerson)==true) cout << "no";
    else cout << "unknown";
    }
        return 0;
}
