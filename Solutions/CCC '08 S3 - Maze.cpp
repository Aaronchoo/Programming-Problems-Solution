//https://dmoj.ca/problem/ccc08s3
#include <iostream>
#include <queue>
#include<cstring>
using namespace std;
bool visited[21][21] = {false};
char maps[21][21];
int dis[21][21] = {0};
int x,y;
int bfs(int k, int l)
{
    queue<pair<int,int>> q;
    dis[k][l]=1;
    visited[k][l];
    q.push(make_pair(k,l));
    while(!q.empty())
    {
        k = q.front().first;
        l = q.front().second;q.pop();
        if(k == y-1 && l == x-1 && maps[y-1][x-1] != '*')break;
        if((maps[k][l] == '+' || maps[k][l] == '|') && k > 0 && visited[k-1][l] == false && maps[k-1][l] != '*' )
        {
            if(dis[k][l] +1 < dis[k-1][l]) dis[k-1][l] = dis[k][l]+1;
            visited[k-1][l] = true;
            q.push(make_pair(k-1,l));
        }
        if((maps[k][l] == '+' || maps[k][l] == '|') && k < y-1 && visited[k+1][l] == false&& maps[k+1][l] != '*')
        {
            if(dis[k][l] +1 < dis[k+1][l]) dis[k+1][l] = dis[k][l]+1;
            visited[k+1][l] = true;
            q.push(make_pair(k+1,l));
        }
        if((maps[k][l] == '+' || maps[k][l] == '-') && l < x-1 && visited[k][l+1] == false&& maps[k][l+1] != '*')
        {
            if(dis[k][l] +1 < dis[k][l+1]) dis[k][l+1] = dis[k][l]+1;
            visited[k][l+1] = true;
            q.push(make_pair(k,l+1));
        }
        if((maps[k][l] == '+' || maps[k][l] == '-') && l > 0&& visited[k][l-1] == false&& maps[k][l-1] != '*')
        {
            if(dis[k][l] +1 < dis[k][l-1]) dis[k][l-1] = dis[k][l]+1;
            visited[k][l-1] = true;
            q.push(make_pair(k,l-1));
        }
    }
    if(dis[y-1][x-1] ==269488144) return -1;
    else return dis[y-1][x-1];
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int ex;
    cin>>ex;
    while(ex--)
    {
        memset(maps,' ',sizeof(maps));memset(dis,10000,sizeof(dis));memset(visited,false,sizeof(visited));
        cin >> y >> x;
        for(int j = 0; j < y; j++)
        {
            for(int c = 0; c < x; c++)
            {
                cin >> maps[j][c];
            }
        }
        cout << bfs(0,0)<<'\n';
    }
    return 0;
}