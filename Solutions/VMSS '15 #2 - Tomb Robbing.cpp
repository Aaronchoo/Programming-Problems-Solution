//https://dmoj.ca/problem/vmss15c1p2
#include <iostream>
//Refresh my memory on how to code
using namespace std;
char tomb[100][100];
    int r;
    int s;
void changeERupper(int i, int j)
{
    if(i > 0 && tomb[i-1][j] == '.')
    {
        tomb[i-1][j] = 'x';
        changeERupper(i-1,j);
    }
    if(j > 0 && tomb[i][j-1] == '.')
    {
        tomb[i][j-1] = 'x';
        changeERupper(i,j-1);
    }
    if(i < r-1 && tomb[i+1][j] == '.')
    {
        tomb[i+1][j] = 'x';
        changeERupper(i+1,j);
    }
    if(j < s-1 && tomb[i][j+1] == '.')
    {
        tomb[i][j+1] = 'x';
        changeERupper(i,j+1);
    }
}
int main()
{
    int counte = 0;
    cin >> r >>s;
     for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < s; j++)
        {
            cin >> tomb[i][j];
        }
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < s; j++)
        {
            if(tomb[i][j] == '.')
            {
                tomb[i][j] = 'x';
                changeERupper(i,j);
                counte++;
            }
        }
    }
    cout << counte;
    return 0;
}