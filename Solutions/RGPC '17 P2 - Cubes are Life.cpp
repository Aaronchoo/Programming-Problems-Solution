//https://dmoj.ca/problem/rgpc17p2
#include <iostream>
using namespace std;
double chen[100000];
double totalchen[100000];
long long holder[10000000];
int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    for(int  i = 0; i < a; i++)
    {
        double same;
        int cool;
        cin>> same;
        cool = same;
        chen[i] = same/2;
        holder[cool] = i;
    }
    double totalchens=0;
    for(int i = 0; i < a;i++ )
    {
        totalchens += chen[i];
        totalchen[i] = totalchens;
    }
    for(int i = 0; i < c; i++)
    {
        int d,e;
        double f;
        cin >> e >> d;

        f = totalchen[holder[d]] - totalchen[holder[e]] + chen[holder[e]];
                if(f >= b) cout << "Enough" << '\n';
        else cout << "Not enough"<< '\n';
    }
    return 0;
}