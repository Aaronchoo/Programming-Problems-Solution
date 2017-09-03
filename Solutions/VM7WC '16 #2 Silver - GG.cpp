//https://dmoj.ca/problem/vmss7wc16c2p2
//DP practice
#include <iostream>

using namespace std;

int main()
{
    string G;
    cin >> G;
    int Total[G.size()];
    int Sum[G.size()];
        if(G[0]=='G') Total[0] =1;
        else Total[0]=0;
    for(int i = 1; i <G.size(); i++)
    {
        if(G[i]=='G') Total[i] =1;
        else Total[i]=0;
        Sum[i] = Sum[i-1] + Total[i];
    }
    int s;
    cin >> s;
    for(int i = 0; i < s; i++)\
    {
        int a,b;
        cin >> a >>b;
        cout << Sum[b] - Sum[a] + Total[a]<<endl;    }
    return 0;