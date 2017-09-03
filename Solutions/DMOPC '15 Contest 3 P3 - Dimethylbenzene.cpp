//https://dmoj.ca/problem/dmopc15c3p3
#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int> > Chem(21);
bool visited[21] = {false};
int check(int goal, int current)
{
    visited[current] = true;
    if(current == goal) {return 1;}
    for(int i = 0; i < Chem[current].size(); i++)
    {
        if(visited[Chem[current][i]] == false)
        {
            return check(goal, Chem[current][i])+1;
        }
    }
    return -1000;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >>a >> b;
        Chem[a].push_back(b);

    }
    int test=0;
    for(int i =1; i < 21; i++)
    {
        if(visited[i] == false && Chem[i].size() >0)
        {
            for(int j = 0; j < Chem[i].size(); j++)
            {
                test =check(i,Chem[i][j]);
                if(test >= 6) { i =100; break;}
            }
        }
    }
    if(test >=6) cout << "YES"<<'\n';
    else cout << "NO" << '\n';


    return 0;
}