//https://dmoj.ca/problem/ccc03s3
#include <iostream>
#include <algorithm>

using namespace std;
char ar[25][25];
int DotCounter=0;
int LotsOfThings = 0;
int x;    int y;
void Remove(int i,int j)
{
    if(i > 0 && ar[i-1][j] == '.' )
    {
        ar[i-1][j] = 'x';
        DotCounter--;
        LotsOfThings++;
        Remove(i-1,j);
    }
    if(j>0 && ar[i][j-1] == '.')
    {
        ar[i][j-1] = 'x';
        DotCounter--;
        LotsOfThings++;
        Remove(i,j-1);
    }
    if(i < x-1 && ar[i+1][j]=='.')
    {
        ar[i+1][j] = 'x';
        DotCounter--;
        LotsOfThings++;
        Remove(i+1,j);
    }
    if(j < y-1 && ar[i][j+1] == '.')
    {
        ar[i][j+1] = 'x';
        DotCounter--;
        LotsOfThings++;
        Remove(i,j+1);

    }
}
int main()
{

    int woodAmout;
    cin >> woodAmout >> x >> y;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cin >> ar[i][j];
            if(ar[i][j] == '.')
            {
                DotCounter++;
            }
            //Could add a if statement for the '.'
        }
    }
    //Room holder
    int rooms[20];
    int indexRoom = 0;
    bool ra;
    while(DotCounter != 0)
    {
        ra = true;
        //Use for loop to run through it all
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(ar[i][j] == '.')
                {
                    ar[i][j] = 'x';
                    DotCounter--;
                    LotsOfThings++;
                    Remove(i,j);
                    ra = false;
                    break;
                }
                if(ra == false)
                {
                    break;
                }
            }
        }
        //Once you're here, assume that they found everything in the box and increase the array counter
        rooms[indexRoom] = LotsOfThings;
        LotsOfThings = 0;
        indexRoom++;
    }

    //Actual part now.
    //Reuse c
    int aaaa = 0;
    std::sort(rooms, rooms + indexRoom);
    //Smallest to biggest?
    for(int i = indexRoom-1; i > -1; i--)
    {
        woodAmout = woodAmout - rooms[i];
        if(woodAmout > 0)
        {
            aaaa++;

        }
        else if(woodAmout == 0)
        {
            aaaa++;
            break;
        }
        else
        {
            woodAmout = woodAmout + rooms[i];
        break;
        }


    }
    cout << aaaa <<  " room";
    if(aaaa != 1)
    {
        cout<< "s";
    }
        cout << ", "<<  woodAmout << " square metre(s) left over";
    
    return 0;
}