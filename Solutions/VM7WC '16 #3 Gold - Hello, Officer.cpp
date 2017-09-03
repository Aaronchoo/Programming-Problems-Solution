//https://dmoj.ca/problem/vmss7wc16c3p3
#include <iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
vector<vector<pair<int,int>> > route(2001);
int dist[2001];
bool visited[2001] ={};
int main()
{
    int NumberHouses, NumberRoads,Shahir, Queries;

    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin >> NumberHouses >> NumberRoads >> Shahir >> Queries;
    for(int i = 0; i< NumberRoads; i++)
    {

        memset(dist, 0x3f3f3f3f, sizeof(dist));
        memset(visited, false,sizeof(visited));
        cin >> a >> b >> c;
        route[a].push_back(make_pair(b,c));
        route[b].push_back(make_pair(a,c));
    }

        a=Shahir;
        priority_queue<pair<int,int> > que;
        que.push(make_pair(0,a));
        dist[a] = 0;
        while(!que.empty())
        {
            int hold = que.top().second;
            que.pop();
            visited[hold] = true;
            for(int j = 0; j <route[hold].size() ; j++)
            {
                if(!visited[route[hold][j].first])
                {
                    int weight = dist[hold] + route[hold][j].second;
                    if(weight < dist[route[hold][j].first])
                    {
                         dist[route[hold][j].first] = weight;
                         que.push(make_pair(-weight,route[hold][j].first));
                    }
                }
            }



        }
    for(int i = 0; i < Queries; i++)
    {
        cin >> a;
        if(dist[a] == 0x3f3f3f3f) cout << -1 << '\n';
        else cout << dist[a] << '\n';
    }


    return 0;
}