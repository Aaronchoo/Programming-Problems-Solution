//https://dmoj.ca/problem/mwc15c7p2
#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int floors,app;
    cin>> floors >> app;
    int CD[floors+1][app+1];
    int Tcd[floors+1][app+1];
    for(int i = 1; i < floors+1; i ++)
    {
        int total=0;
        for(int j = 1; j < app+1; j++)
        {
            cin >> CD[i][j];
            total = total + CD[i][j];
            Tcd[i][j]=total;
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        cout << Tcd[c][b] - Tcd[c][a] + CD[c][a] << '\n';
    }

    return 0;
}