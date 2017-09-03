//https://dmoj.ca/problem/ecoo16r1p2
#include <iostream>
#include<set>
using namespace std;
set<long long> answers;
set<long long> filter;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int r = 0; r < 10; r++)
    {
        long long n;
        cin >> n;
        long long num[n];
        long long ssss,ind =0;
        for(int i = 0; i < n; i++)
        {
         cin >> ssss;
            if(filter.find(ssss) == filter.end())
            {num[ind] = ssss; ind+=1; filter.insert(ssss);}
            
        }
        long long total;
        long long total2;
        for(int i = 0; i < ind; i++)
            {
                for(int j=0; j < ind; j++)
                {
                        for(int l = 0; l < ind; l++)
                        {
                             total = num[i]*num[j]*num[l];
                            answers.insert(total);
                             total = num[i]*num[j]+ num[l];
                             answers.insert(total); 
                             total2 =(num[i] + num[j])*num[l];
                           answers.insert(total2);
                             total2 =  num[i] + num[j] + num[l];
                            answers.insert(total2);
                        }
                }

            }
        for(int m = 0; m < 5; m++)
        {
            long long check;
            cin >> check;
           if(answers.find(check) == answers.end()) cout << "F";
           else cout << "T";
        } cout << '\n';
        answers.clear();
        filter.clear();



    }
    return 0;
}