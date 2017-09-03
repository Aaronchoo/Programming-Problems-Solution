//https://dmoj.ca/problem/vmss15c1p4
#include <iostream>
#include<utility>
#include<cstring>
#include<vector>

#include<queue>
using namespace std;
vector<vector<pair <int,int >> > road(2001);
int dist[2001];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int frank,buildings,raods,food;
    //Just go w/ the spelling error
    cin >> frank >> buildings >> raods >> food;
    int foodBasic[food];
    memset(dist,0x3f3f3f3f,sizeof(dist));
    for(int i = 0; i < food; i++)
    {
        cin >> foodBasic[i];
    }
    for(int i = 0; i < raods; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        road[a].push_back(make_pair(b,c));
    }
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    dist[0] = 0;
    while(!q.empty())
    {
        int s = q.top().second;
        q.pop();
        for(int i = 0; i < road[s].size(); i++)
        {
            int weig = dist[s] + road[s][i].second;
            if(weig < dist[road[s][i].first])
            {
                dist[road[s][i].first] = weig;
                q.push(make_pair(-weig,road[s][i].first));
            }
        }

    }
    int counter=0;
    for(int i = 0; i < food; i++)
    {
        if(dist[foodBasic[i]] <= frank) counter +=1;
    }
    cout << counter << '\n';
    return 0;
}