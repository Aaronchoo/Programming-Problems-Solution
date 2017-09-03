//https://dmoj.ca/problem/odd
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    unordered_set<int> odd;
    int n,in;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> in;
        if(odd.find(in) == odd.end())
        {
            odd.insert(in);
        }
        else odd.erase(in);
    }
    cout << *odd.begin();
    return 0;
}