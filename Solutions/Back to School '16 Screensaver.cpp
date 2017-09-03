//https://dmoj.ca/problem/bts16p4
#include <iostream>

using namespace std;

int main()
{
   int x,y,tick;
   cin >> x >> y >> tick;
char values[y][x];
int tempX, tempY;
   for(int i = 0; i < y; i++)
   {
       for(int j = 0; j < x; j++)
       {
           cin >> values[i][j];
           if(values[i][j] == 'O')
           {
               tempX = j;
               tempY = i;
           }
       }
   }
   int direction = 5;
   //Direction 4 is up, 5 is right, 6 is down, 7 is left
   for(int i = 0; i <= tick; i++)
   {
       if(i==tick)
       {
           cout << "The observer stays within the grid.";
       }
       else if(direction == 5)
       {
            if(tempX+1 == x)
           {
               cout << "The observer leaves the grid after " <<i+1<< " tick(s).";
               break;
           }
           else if(values[tempY][tempX+1] == '\\')
           {
               tempX++;
               direction = 6;
               values[tempY][tempX] = '/';
           }
           else if(values[tempY][tempX+1] == '|')
           {
               tempX++;
               direction = 7;
               values[tempY][tempX] = '-';
           }
             else if(values[tempY][tempX+1] == '/')
           {
               tempX++;
               direction = 4;
               values[tempY][tempX] = '\\';
           }
           else tempX++;
       }
       else if(direction == 6)
       {
           if(tempY+1 == y)
           {
               cout <<"The observer leaves the grid after " << i+1 << " tick(s).";
               break;
           }
           else if(values[tempY+1][tempX] == '/')
           {
               tempY++;
               direction = 7;
               values[tempY][tempX]= '\\';
           }
           else if(values[tempY+1][tempX] == '-')
           {
               tempY++;
               direction = 4;
               values[tempY][tempX] = '|';
           }
           else if(values[tempY+1][tempX] == '\\')
           {
               tempY++;
               direction = 5;
               values[tempY][tempX]= '/';
           }
           else tempY++;
       }
       else if(direction == 7)
       {
           if(tempX == 0)
           {
               cout <<"The observer leaves the grid after " << i+1 << " tick(s).";
               break;
           }
           else if(values[tempY][tempX-1] == '/')
           {
               tempX--;
               direction = 6;
               values[tempY][tempX]= '\\';
           }
           else if(values[tempY][tempX-1] == '|')
           {
               tempX--;
               direction = 5;
               values[tempY][tempX] = '-';
           }
           else if( values[tempY][tempX-1] == '\\')
           {
               tempX--;
               direction = 4;
               values[tempY][tempX] = '/';
               }//don't forget '\\'
           else tempX--;
       }
              else if(direction == 4)
       {
           if(tempY == 0)
           {
               cout <<"The observer leaves the grid after " << i+1  << " tick(s).";
               break;
           }
           else if(values[tempY-1][tempX] == '/')
           {
               tempY--;
               direction = 5;
               values[tempY][tempX] = '\\';
           }
           else if(values[tempY-1][tempX] == '-')
           {
              tempY--;
               direction = 6;
               values[tempY][tempX] = '|';
           }
           else if(values[tempY-1][tempX] == '\\')  {
               tempY--;
               direction = 7;
               values[tempY][tempX] = '/';
           }
           else tempY--;       }

   }

    return 0;
}