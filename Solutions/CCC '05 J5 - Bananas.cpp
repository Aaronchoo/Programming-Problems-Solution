//https://dmoj.ca/problem/ccc05j5
//Monkey Language!
//https://dmoj.ca/problem/ccc05j5
#include <iostream>
#include<string>
using namespace std;
int Spos = 0;

bool Language(string monkey, int pos, int x)
{
    std::string lang = monkey.substr(pos,1);
    //A word
    if(x == 0)
    {
        if(lang == "A")
        {
            if(pos == monkey.length()-1 && Spos == 0) return true;
            else return Language(monkey,pos+1,1);
        }
        else if(lang == "B")
        {
            Spos++;
            return Language(monkey,pos+1,0);
        }
            else return false;
    }
    //N
    else
    {
        if(lang == "N" && pos <= monkey.length()-2 ) return Language(monkey,pos+1,0);
        else if (lang =="S")
            {

                Spos--;
                if(pos == monkey.length()-1 && Spos == 0) return true;
                else if(Spos != 0&& pos == monkey.length()-1) return false;
                    else return Language(monkey,pos+1,1);
            }
        else return false;
    }

}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string monkey;
    cin >> monkey;
    while(true)
    {
        if(Language(monkey,0,0) == true)
        {
            cout << "YES" <<endl;
        }
        else cout << "NO" <<endl;
        Spos = 0;
        cin >> monkey;
        if(monkey == "X") break;

    }

    return 0;
}