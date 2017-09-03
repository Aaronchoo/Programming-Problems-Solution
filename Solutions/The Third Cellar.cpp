//https://dmoj.ca/problem/phantom2
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    bool isPrime[1000001];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    int j=2;
    while(j <=1000000)
    {
         if(isPrime[j] ==true)
         {
             for(int i = j+j; i < 1000001; i+=j)
             {
              isPrime[i] = false;
             }
         }
         j+=1;


    }
    for(int i = 0; i < n; i++)
    {    int dn=0;
        int a,b;
        cin >> a >>b;
        for(a; a < b;a++)
        {
            if(isPrime[a]==true)
            {
                dn+=1;
            }
        }
        cout << dn<<'\n';
    }
    return 0;
}
