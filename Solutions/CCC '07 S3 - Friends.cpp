//https://dmoj.ca/problem/ccc07s3
#include <iostream>
#include <vector>
using namespace std;
  int n;
vector<vector<int> > friends(10000);

int findingDory(int x, int y, int value)
{
    if(value > n || friends[x].size() != 1) return -1;
    if(friends[x][0] == y) return value;
    return findingDory(friends[x][0],y,value+1);


}
int main()
{
  cin >> n;
  int x,y;
  for(int i = 0; i < n; i++)
  {
      cin >> x >> y;
        friends[x].push_back(y);
  }
  while(true)
  {
      cin >> x >> y;
      if(x == 0 || y == 0) break;
      //Do recursion to get thing
      int value;
      value = findingDory(x,y,0);
      if(value >-1) cout << "Yes " << value << endl;
      else cout << "No" << endl;

  }
    return 0;
}