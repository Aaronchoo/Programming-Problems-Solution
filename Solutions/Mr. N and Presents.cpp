//https://dmoj.ca/problem/year2017p1
#include <iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    map<int,int> List;
    map<int,int> Se;
    string letter;
    int number;
    int f = -1, e = 1;
    for(int i = 0; i < q; i++)
    {
        cin >> letter >> number;
        if(letter == "F")
        {
            List.insert(make_pair(f,number));
            Se.insert(make_pair(number,f));
            f = f - 1;
        }
        else if(letter == "E")
        {
            List.insert(make_pair(e,number));
            Se.insert(make_pair(number,e));
            e = e+1;

        }
        else
        {
            map<int,int>::iterator it = Se.find(number);
            int hold = (*it).second;
            List.erase(hold);
            Se.erase(number);

        }
    }
    map<int,int>::iterator it = List.begin();
    for(int i = 0; i < List.size(); i++)
    {
        cout << (*it).second << '\n';
        ++it;

    }


    return 0;
}