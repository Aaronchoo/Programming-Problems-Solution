//https://dmoj.ca/problem/gfssoc16s1
#include <iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
vector<vector<pair<int,int>> > loo(1002);
int distanc[1002];
bool visited[1002]={false};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
        memset(distanc, 0x3f3f3f3f, sizeof(distanc));
    int number,tran;
    cin >> number >> tran;
    string stops[1000];
    cin.ignore();
    for(int i = 0; i < number; i++)
    {
        getline(cin, stops[i]);
    }
        string make;
    for(int i = 0; i < tran; i++)
    {
        getline(cin,make);
        std::size_t found = make.find("-");
        std::string one, two;
        one = make.substr(0,found);
        int sj,jk;
        two = make.substr(found+1, make.length());
        if(one == "Waterloo GO") sj =1000;
        else if( one == "home") sj = 1001;
        else
        {
            for(int j = 0; j < number; j++)
            {
                if(one == stops[j]) {sj = j;j = number;}
            }
        }
        if(two == "Waterloo GO") {jk  =1000;}
        else if(two == "home") jk= 1001;
        else
        {
            for(int j = 0; j < number; j++)
            {
                if(two == stops[j]) {jk = j; j = number;}
            }
        }
        loo[sj].push_back(make_pair(jk,1));
        loo[jk].push_back(make_pair(sj,1));

    }
    priority_queue<pair<int,int>> que;
    distanc[1001] = 0;
    que.push(make_pair(0,1001));
    while(!que.empty())
    {
            int k = que.top().second;
            que.pop();
            visited[k] = true;
            for(int i = 0; i < loo[k].size(); i++)
            {
                if(!visited[loo[k][i].first])
                {

                    int w = distanc[k] + loo[k][i].second; if(w < distanc[loo[k][i].first])
                    {
                        distanc[loo[k][i].first] = w;
                        que.push(make_pair(-w, loo[k][i].first));
                    }
                }
            }
    }
    if(distanc[1000] != 1061109567)cout << distanc[1000];
    else cout << "RIP ACE";

    return 0;
}
