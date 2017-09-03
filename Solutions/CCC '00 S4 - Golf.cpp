//https://dmoj.ca/problem/ccc00s4
#include <iostream>

using namespace std;

int main()
{
    int distanceOfHole,numberOfClubs;
    cin >>distanceOfHole>>numberOfClubs;
    int puts[numberOfClubs];
    for(int i = 0; i < numberOfClubs; i++)
    {
        cin >> puts[i];
    }
    int DP[distanceOfHole+1];
    for(int i = 0; i <=distanceOfHole; i++) DP[i] = 10000;
    bool h[distanceOfHole+1]={false};
    DP[0] =0;
    h[0] = true;
    for(int i = 0; i < distanceOfHole; i++)
    {
        if(h[i]==true)
        {
            for(int j = 0; j <numberOfClubs;j++)
                {
                    if(puts[j]+i <= distanceOfHole)
                    {

                        if(DP[i]+1 < DPPP[i+puts[j]])DPPP[i+puts[j]]=DPPP[i]+1;
                        if(h[i+puts[j]]!=true) {h[i+puts[j]]=true;}
                       // cout << DPPP[tots]<<" ";
                    }
                }
        }
    }
    if(DP[distanceOfHole] == 10000) cout << "Roberta acknowledges defeat.";
       else cout <<"Roberta wins in "<<DP[distanceOfHole]<<" strokes.";
    return 0;
}
