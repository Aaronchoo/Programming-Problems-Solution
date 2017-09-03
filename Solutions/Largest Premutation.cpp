//https://dmoj.ca/problem/largeperm
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int premu[n];
    int ordered[n];
    for(int i = 0; i < n; i++)
    {
        cin >> premu[i];
        ordered[i] = premu[i];
    }
    std::sort(ordered,ordered+n);
    bool yes = false;
    while(k--)
    {
        int temp,ok,loc;
        for(int i = n-1; i >=0; i--)
        {
            if(ordered[i]!=premu[n-i-1]) {temp = ordered[i]; ok = i; i = -1;}
            else if(i-1 <0){yes = true; k = 0;}
        }
          if(yes ==false){  for(int j = 0; j < n; j++)
            {
                if(premu[j] ==temp) {loc = j; j = n;}
            }
            premu[loc] = premu[n-ok-1];
            premu[n-ok-1] = ordered[ok];}
    }
    for(int i = 0; i < n; i++)
    {
        cout << premu[i] << " ";
    }
return 0;
}