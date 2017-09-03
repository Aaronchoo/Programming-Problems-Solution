//https://dmoj.ca/problem/cco13p2
#include <iostream>
#include<cmath>
using namespace std;

struct Node{
    int l,r,maximum,winner;

} treeNode[4194305];
int realIdex[4194305];
int numberOfCurrent = 1;
int n,m,x,y;
char commandToDo;

void push_up(int indx){
    if(treeNode[indx*2].maximum >  treeNode[indx*2+1].maximum){
        treeNode[indx].maximum = treeNode[indx*2].maximum;
        treeNode[indx].winner = treeNode[indx*2].winner;
    }
    else{
        treeNode[indx].maximum = treeNode[indx*2+1].maximum;
        treeNode[indx].winner = treeNode[indx*2+1].winner;
    }
}

void build(int l,int r,int indx){

    treeNode[indx].l=l;treeNode[indx].r=r;
    if(l==r){
        cin>>treeNode[indx].maximum;
        treeNode[indx].winner = numberOfCurrent;
        realIdex[numberOfCurrent] = indx;
        numberOfCurrent++;
        return;
    }
    int middle=(l+r)/2;
    build(l,middle,indx*2);
    build(middle+1,r,indx*2+1);
    push_up(indx);
}

void update(int x, int v, int indx){
    if(treeNode[indx].l>x && treeNode[indx].r < x) return;
    if(treeNode[indx].l==x && treeNode[indx].r==x){
        treeNode[indx].maximum=v;
        return;
    }
    int mid = (treeNode[indx].l+treeNode[indx].r)/2;
    if(x<=mid){
        update(x,v,indx*2);
    }
    else{
        update(x,v,indx*2+1);
    }
    push_up(indx);
}

int numberOfWins(int countWins,int pos){

    if(treeNode[pos].winner==countWins){
        return numberOfWins(countWins,pos/2)+1;
    }
    else if(pos == 1 &&treeNode[pos].winner==countWins )
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >>n>>m;
    n = pow(2,n);
    build(1,n,1);
    while(m--){
        cin >> commandToDo;
        if(commandToDo=='R'){
                int replacedNode,replacementNode;
            cin >> replacedNode>>replacementNode;
            update(replacedNode,replacementNode,1);
        }
        else if(commandToDo == 'W'){
            cout << treeNode[1].winner << '\n';
        }
        else{
            int countWinsIndx;
            cin >> countWinsIndx;
            cout << numberOfWins(countWinsIndx,realIdex[countWinsIndx]/2) << '\n';

        }
    }




    return 0;
}
