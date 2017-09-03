//https://dmoj.ca/problem/ioi94p1
//dp practice
#include <iostream>

using namespace std;

int main()
{
   int n,s=1,total=0;
   cin >> n;
   int py[n][5051];
   for(int i = 0; i < n; i++)
   {

       for(int j = 0; j < s; j++)
       {
           total+=1;
           cin>>py[i][j];
       }
       s+=1;
   }
    int DPDP[n][5051];
    DPDP[0][0] = py[0][0];
    for(int i =0; i < n-1; i++)
    {
        for(int j = 0; j <= i;j++)
        {
            if(DPDP[i][j]+py[i+1][j] > DPDP[i+1][j]) DPDP[i+1][j] = DPDP[i][j]+py[i+1][j];
            if(DPDP[i][j]+py[i+1][j+1] > DPDP[i+1][j+1]) DPDP[i+1][j+1] = DPDP[i][j]+py[i+1][j+1];
        }
    }
    int big = 0;
    for(int i = 0; i <n; i++)
    {
        if(DPDP[n-1][i] > big) big = DPDP[n-1][i];
    }
    cout << big;

    return 0;
}