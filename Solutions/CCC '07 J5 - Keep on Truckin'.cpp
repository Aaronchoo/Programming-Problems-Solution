//https://dmoj.ca/problem/ccc07j5
//Dynamic programing practice
#include <iostream>

using namespace std;

int main()
{
    int ridealong[7001]={0};
    bool type[7001];
    type[0] = true;type[990] = true;type[7000] = true;
    type[1010] = true;
    type[1970] = true;type[2030] = true;type[2940] = true;
    type[3060] = true;type[3930] = true;type[4060] = true;
    type[4970] = true;type[5030] = true;type[5990] = true;type[6010] = true;
    int A,B;
    cin >> A >> B;
    int jl;
    cin>>jl;
    //making all the values in the array to 0
    //set first as 1
    ridealong[0] = 1;
    //add additional stops
    for(int i = 0; i < jl; i++){int k; cin >> k; type[k]=true;}
    //Loops through to see if they are able to make it
    for(int j = 0; j <7000;j++)
    {
        if(ridealong[j]!=0)
        {for(int i = A; i <= B; i++)
        {
            if(i+j <= 7000){
            //Increase counter if they touch
            if(type[j+i] == true) {ridealong[j+i]+=ridealong[j];}}
            else i = B+1;
        }}
    }
    cout << ridealong[7000];
    return 0;
}