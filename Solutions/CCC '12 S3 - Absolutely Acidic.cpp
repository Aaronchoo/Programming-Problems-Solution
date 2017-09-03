//https://dmoj.ca/problem/ccc12s3
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
      cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int reading[n];
    for(int i = 0; i < n; i++)
    {
        cin >> reading[i];
    }
    //Sort(array.begin(), array.end());
    bool PAIR = true;
    std::sort(reading, reading+n);

    int holdLarge =0, numberLarge = 0, holdSmaller1 = -1, numberSmaller1= -1,holdSmaller2 = -2, numberSmaller2 = -2;
    int valueToCheck = reading[0], tempNumber =0;
    for(int i = 0; i <= n; i++)
    {
        if(i != 0)valueToCheck = reading[i-1];
        if(i == n && tempNumber != 1) tempNumber++;
        else if(valueToCheck == reading[i]) tempNumber++;
        else if(tempNumber >= numberLarge)
        {
            //shift down all values
            if(numberLarge == numberSmaller1 /*assuming that the number is lager than the small*/)
            {
                if(numberSmaller1 >numberSmaller2)
                {
                 holdSmaller2 = holdSmaller1;
                 numberSmaller2 = numberSmaller1;
                }
                holdSmaller1 = holdLarge;
                numberSmaller1 = numberLarge;
                holdLarge = valueToCheck;
                  numberLarge = tempNumber;
                tempNumber = 1;
            }
            else if(numberLarge > numberSmaller1)
            {
                if(numberSmaller1 >numberSmaller2)
                {
                 holdSmaller2 = holdSmaller1;
                 numberSmaller2 = numberSmaller1;
                }
                //problem is figuring out the second tie.
                holdSmaller1 = holdLarge;
                numberSmaller1 = numberLarge;
                holdLarge = valueToCheck;
                  numberLarge = tempNumber;
                tempNumber = 1;
            }
        }
        /*else if(tempNumber == numberLarge)
        {
            holdLarge = valueToCheck;
                  numberLarge = tempNumber;
                tempNumber = 1;
        }*/
        else if(tempNumber > numberSmaller1)
        {
            if(numberSmaller1 >numberSmaller2)
                {
                 holdSmaller2 = holdSmaller1;
                 numberSmaller2 = numberSmaller1;
                }
            holdSmaller1 = valueToCheck;
            numberSmaller1 = tempNumber;
            tempNumber = 1;
        }
        else if(tempNumber == numberSmaller1)
        {
            if(valueToCheck > holdSmaller1)
            {

                if(holdSmaller2 > holdSmaller1 && holdSmaller2 >0)
                {
                    holdSmaller2 = holdSmaller1;
                }
                holdSmaller1 = valueToCheck;

            }
            else if(valueToCheck < holdSmaller2)
            {
               holdSmaller2 = valueToCheck;
            }
            tempNumber = 1;
        }
        else tempNumber = 1;
    }
    int number1, number2;
    number1 = holdLarge -holdSmaller1;
    number2 = holdLarge - holdSmaller2;
    if(number1 > 0 && number1 > number2 && number2*(-1) < number1) cout << number1;
    else if(number1*(-1) > 0 && number1*(-1) > number2 && number2*(-1) < number1*(-1)) cout<< number1*(-1);
    else if(number2 > 0 && number2 > number1 && number1*(-1) <number2) cout << number2;
    else cout << number2*(-1);

    return 0;
}