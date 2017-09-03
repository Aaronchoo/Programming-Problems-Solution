//https://dmoj.ca/problem/vmss7wc16c5p4
//Dynamic Programing practice
#include <iostream>
#include<cstring>
using namespace std;

int main()
{

    int n;
    cin >> n;
    //DPPMANNNN = DP
    int DPMANNNN[n+1];
    int x,y,z;
    cin >> x>>y>>z;
    for(int i = 0; i <= n; i++){DPMANNNN[i]=0;}
    DPMANNNN[0] = 1;
    for(int i = 1; i <=n; i++)
    {
        if(i >= x && DPMANNNN[i-x]>0 && DPMANNNN[i-x] + 1 > DPMANNNN[i]) DPMANNNN[i] =DPMANNNN[i-x] + 1;
        if(i >= y && DPMANNNN[i-y]>0 && DPMANNNN[i-y] + 1 > DPMANNNN[i]) DPMANNNN[i] =DPMANNNN[i-y] + 1;
        if(i >= z && DPMANNNN[i-z]>0 && DPMANNNN[i-z] + 1 > DPMANNNN[i]) DPMANNNN[i] =DPMANNNN[i-z] + 1;
    }
    cout << DPMANNNN[n]-1;
    return 0;
}