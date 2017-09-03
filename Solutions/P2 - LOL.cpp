//https://dmoj.ca/problem/rgss2
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int N;
    cin >> N;
    int locationX[N];
    int locationY[N];
    for(int i = 0; i < N; i++)
    {
       cin >> locationX[i] >> locationY[i];
    }

    sort(locationX, locationX + N);
    sort(locationY, locationY + N);

    int potatoking = locationX[N-1] - locationX[0];
    int rjfrijgfr = locationY[N-1] - locationY[0];
    int igji = potatoking * rjfrijgfr;
    cout << igji;

    return 0;
}