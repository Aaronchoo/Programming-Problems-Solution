//https://dmoj.ca/problem/cco14p4
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, planeton,fuel,howmany=0;
    cin >> n >> planeton;
    //note to self: the first int is the cost and the second is the fuel they get
    vector<pair<int,int> > planets;
    int a,b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(i == planeton-1)  fuel = a;
        else if(a >= b){ planets.push_back(make_pair(b,a)); howmany+=1;}
    }
    std::sort(planets.begin(),planets.begin()+howmany);
    int s=1;
    for(int i = 0; i < howmany; i++)
    {
        if(fuel - planets[i].first < 0) break;
        else
        {
            s= s+1;
            fuel = planets[i].second - planets[i].first+fuel;
        }
    }
    cout << fuel << '\n' << s << '\n';
    return 0;
}