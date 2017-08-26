//https://dmoj.ca/problem/rgss4
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
  int maxii[1001];
int main()
{
    int n;
    cin >> n;
    memset(maxii, 0, 1001);
    int number[n];
    for(int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    for(int i = 0; i < n; i++)
    {//does not need to be right after each othter
        int temp = number[i]-1;
        for(int k = number[i]-2; k > 0 ; k--)
        {
            if(maxii[temp] < maxii[k])
            {
                temp = k;
            }
        }
        maxii[number[i]] = maxii[temp] + number[i];

    }
    std::sort(maxii, maxii+1001);
    cout << maxii[1000];
    return 0;
}
