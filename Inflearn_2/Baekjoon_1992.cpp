#include <bits/stdc++.h>

using namespace std;

int N;
char arr[64][64];
string answer;

void recur(int y, int x, int sz){

    printf("%d, %d, %d\n",y,x,sz);
    
    char clr=arr[y][x];
    int flag=0;

    for (int i=y;i<y+sz;i++){
        for (int j=x;j<x+sz;j++){
            if (arr[i][j]!=clr){
                flag=1;
                answer=answer+'(';
                recur(y,x,sz/2);
                recur(y,x+sz/2,sz/2);
                recur(y+sz/2,x,sz/2);
                recur(y+sz/2,x+sz/2,sz/2);
                answer=answer+')';
                return;
            }
        }
    }

    if (!flag||sz==1){
        answer+=clr;
        return;
    }
    
}

int main()
{
    cin >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }

    recur(0,0,N);

    cout << answer;
}