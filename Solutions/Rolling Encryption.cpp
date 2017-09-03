//https://dmoj.ca/problem/rollencrypt
#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    char alhpa[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int temp[26]={0};
    int value;
    string number;
    cin >> value >> number;
    int sm=0,val,totals=0;
    int kk[number.size()];
   for(int i = 0; i < value+1; i++)
   {
            for(int j = 0; j < 26; j++)
            {
                if(number[i]==alhpa[j])
                {
                    kk[i] = j;
                    if(value > i)temp[j] +=1;
                    if(value > i)j = 26;
                }
                if(value ==i)
                {
                    if(temp[j] > sm) {
                        sm = temp[j];
                        val = j;
                        }
                }
            }
            if (i == value && i < number.size())
            {
        char s = number[i];
        if(s+val+1 > 122)
        {
            s = s+val+1-26;
        }
        else   s =s+val+1;
        cout << s;
            }
                else if(i < number.size()) cout << number[i];
   }
          sm = 0; val = 0;
    for(int i = value+1; i < number.size(); i++)
    {
        temp[kk[totals]] =temp[kk[totals]]-1;
        totals +=1;
        if(totals+value < number.size())temp[kk[totals+value-1]] +=1;
         sm = 0; val = 0;
        for(int j = 0; j < 26; j++)
        {
            if(number[i]==alhpa[j])
            {
                    kk[i] = j;
            }
           // if(totals == 1) cout << temp[1] <<" ";
            if(temp[j] > sm){ sm = temp[j]; val = j;}

        }
        char s = number[i];
        if(s+val+1 > 122)
        {
            s = s+val+1-26;
        }
        else   s =s+val+1;
        cout << s;

    }

    return 0;
}
