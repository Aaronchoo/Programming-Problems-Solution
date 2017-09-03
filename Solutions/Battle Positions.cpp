//https://dmoj.ca/problem/seed3
#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    // S/O to double speed;
    int station,TroopsNeeded, Jwaves, Ktroops;
    cin >> station >> TroopsNeeded >> Jwaves;
    int original[station] = {0};
    int change[station] = {0};
    for( int i = 0; i < Jwaves; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        change[a-1] += c;
        change[b] -=c;
    }
    original[0] = change[0];
    for(int i = 1; i < station; i++)
    {
        original[i] = change[i] + original[i-1];
    }
    int counter=0;
    for(int j = 0; j < station; j++)
    {
        if(original[j] >= TroopsNeeded) counter+=1;
    }
    cout << station-counter << '\n';

    return 0;
}