//https://dmoj.ca/problem/dmopc14c2p4
#include <iostream>

using namespace std;

int Tree[1000000];
int mass[1000000];

int main()
{
      cin.sync_with_stdio(0);
    cin.tie(0);

    int NumberOfTrees;
    cin >> NumberOfTrees;
    int totalMass=0;
    for(int i = 0; i < NumberOfTrees; i++)
    {
        cin >> Tree[i];
        totalMass = totalMass + Tree[i];
        mass[i] = totalMass;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int a,b;
        cin >> b >> a;
        cout << mass[a] - mass[b] + Tree[b] << '\n';
    }
    return 0;
}