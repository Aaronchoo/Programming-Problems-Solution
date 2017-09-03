//https://dmoj.ca/problem/dmpg15b4
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int cards;
    cin >> cards;
    vector<int> pnumbers;
    vector<int> nnumbers;
    int temp,maxval = 1;
    for(int i = 0; i < cards; i++)
    {
        cin >> temp;
        if(temp != 0)
        {
                if(temp < 0) nnumbers.push_back(temp);
            else pnumbers.push_back(temp);
        }
    }
    int pos =int(pnumbers.size()), neg = int(nnumbers.size());
      if(pos + neg > 1)
      {
        std::sort(pnumbers.begin(),pnumbers.begin()+pos);
        std::sort(nnumbers.begin(),nnumbers.begin()+neg);
        if(neg%2 != 0)
        {
            neg = neg -1;
        }
      for(int i = 0; i < pos; i++)
      {
          maxval = maxval*pnumbers[i];
      }
      for(int i = 0; i < neg; i++)
      {
          maxval = maxval*nnumbers[i];
      }

      cout << maxval << '\n';
      }
    else if(pos == 1) cout << pnumbers[0] << '\n';
    else if(neg == 1 && cards == 1)cout << nnumbers[0] << '\n';
    else cout << "0";
return 0;
}