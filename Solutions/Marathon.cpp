//https://dmoj.ca/problem/gfssoc2j4
#include <iostream>

using namespace std;

int main()
{
      cin.sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    int anime[n];
    int totalrating[n];
    //do n + 1? hmmmm anime this up yo
    int runnningtotalll=0;
    for(int i = 0; i < n; i++)
    {
        cin >> anime[i];
        runnningtotalll = runnningtotalll + anime[i];
        totalrating[i]=runnningtotalll;

    }
    for(int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        cout << totalrating[n-1] - (totalrating[b-1] - totalrating[a-1] + anime[a-1]) << '\n';
    }
    return 0;
}