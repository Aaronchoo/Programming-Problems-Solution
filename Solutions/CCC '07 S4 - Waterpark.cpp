//https://dmoj.ca/problem/ccc07s4
#include <iostream>
#include<vector>
using namespace std;
vector<vector<int> > slide(10000);
int n;
bool visited[10000]={false};
int ways[10000] = {0};
int holdup( int current)
{
    if(current ==n)
    {
            return 1;
    }
    else
    {
        for(int i = 0; i < slide[current].size(); i++)
        {
            if(visited[slide[current][i]] == true) {ways[current] +=ways[slide[current][i]];}
            else
            {
                ways[current] +=holdup(slide[current][i]);
               
            }

        }
        if(ways[current] > 0){visited[current] = true;}
        return ways[current];

    }
}

int main()
{
        cin.sync_with_stdio(0);
        cin.tie(0);
    int a,b;
    cin >> n;
    cin >> a >> b;
    while(a != 0 && b!= 0)
    {
        slide[a].push_back(b);
        cin >> a >> b;
    }
          cout << holdup(1);
    return 0;
}