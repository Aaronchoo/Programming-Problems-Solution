//https://dmoj.ca/problem/fhc15c1p1
#include <iostream>
#include<cstring>
using namespace std;
int primacity[10000001];
bool isNotPrime[10000001]={false};
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(isNotPrime,false,10000001);
    memset(primacity,0,10000001);
    for(int i = 2; i < 10000001; i++)
    {
        if(isNotPrime[i]==false)
        {
            for(int ii = i; ii <10000001; ii +=i)
            {
                primacity[ii] +=1;
                if(ii!=i)isNotPrime[ii]=true;
            }
        }
    }

    int hold;
    int total=0;
    int a,b,c;
    cin >> hold;
    for(int i = 0; i < hold; i++)
    {
            cin>>a>>b>>c;
            for(int ii = a; ii <=b; ii++)
            {
                if(primacity[ii]==c)
                {
                    total+=1;
                }
            }
            cout << "Case #" << i+1 << ": "<<total<<'\n';

            total=0;
    }

    return 0;
}
