//https://dmoj.ca/problem/hci16taxi
#include <iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<queue>
using namespace std;
vector<vector<pair<int,int>> > routine(100001);
int distances[100001];
bool visited[100001] = {false};
int main()
{
    memset(distances,0x3f3f3f3f, sizeof(distances));
    cin.sync_with_stdio(0);
    cin.tie(0);
    int nodes,edges,party,rar,cat;
    cin >> nodes >> edges >> party >> rar>>cat;
    for(int i = 0; i < edges; i++)
    {
        int a,b,c;
        cin >> a>>b>>c;
        routine[a].push_back(make_pair(b,c));
        routine[b].push_back(make_pair(a,c));
    }
    priority_queue<pair<int,int> > correct;
    correct.push(make_pair(0,party));
    distances[party] = 0;
    int cost = 3;
    while(!correct.empty())
    {
        int hold = correct.top().second;
        correct.pop();
        visited[hold] = true;
        for(int i = 0; i < routine[hold].size(); i++)
        {
            if(!visited[routine[hold][i].first])
            {
                int w = distances[hold] + routine[hold][i].second;
                if(w < distances[routine[hold][i].first])
                {
                    distances[routine[hold][i].first] = w;
                    correct.push(make_pair(-w, routine[hold][i].first));
                }
            }
        }

    }
    if(distances[rar] == 0x3f3f3f3f) cout << "Nooooooooo!!!" << '\n';
    else if(distances[cat] == 0x3f3f3f3f || cat == rar)
    {
        if(distances[rar] > 10) cost += distances[rar]-10 + 20;
        else cost += distances[rar] *2;
        cout << cost;
        if(cat != rar) cout << '\n' << "Yippee!!!";
    }
    else
    {
        int temp = distances[rar];
        memset(distances,0x3f3f3f3f,sizeof(distances));
        memset(visited,false, sizeof(visited));
        correct.push(make_pair(temp,rar));
        distances[rar] = temp;
        while(!correct.empty())
        {
            int round2 = correct.top().second;

            correct.pop();
            visited[round2] = true;
            for(int i = 0; i < routine[round2].size(); i++)
            {
                if(!visited[routine[round2][i].first])
                {
                    int w = distances[round2] + routine[round2][i].second;
                    if(w < distances[routine[round2][i].first])
                    {
                        distances[routine[round2][i].first] = w;
                        correct.push(make_pair(-w, routine[round2][i].first));
                    }
                }
            }
        }
        if(distances[cat] > 10) cout << (distances[cat]-10 + 20+3);
        else cout << (distances[cat]*2+3);

    }

 return 0;
}