//https://dmoj.ca/problem/ccc15s3
#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> free;
    int numberofgates, numberofplanes, planes;
    int counter = 0;
    cin >> numberofgates >> numberofplanes;
    for(int i = 1; i <= numberofgates; i++)
    {
        free.insert(-i);
    }
    for(int i = 0; i < numberofplanes; i++)
    {
        cin >> planes;
        if(free.find(-planes) == free.end())
        {
            if(free.upper_bound(-planes) == free.end())
            {
                break;
            }
            else
            {
                free.erase(free.upper_bound(-planes));
                counter = counter +1;
            }
        }
        else
        {
            free.erase(-planes);
            counter=counter+1;
        }
    }


cout << counter;
return 0;
}