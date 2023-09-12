#include <bits/stdc++.h>

using namespace std;

int A_size,B_size,ret_A,ret_B,cnt=0,ret=INT_MAX,dp[1000][1000][7];

int cup(int A,int B,int move){
    
    int ret=1;
    if ((move==1&&A==A_size)||(move==2&&B==B_size)||(move==3&&A==0)||(move==4&&B==0)) return INT_MAX;
    if (A==ret_A&&B==ret_B){
        return ret;
    }
    cnt++;
    printf("%d %d %d\n",A,B,move);
    if (dp[A][B][move]){
        return dp[A][B][move];
    }
    int mn=INT_MAX;
    if (move==1) for (int i=1;i<=6;i++){
        if (ret+cup(A_size,B,i)<mn) mn=ret+cup(A_size,B,i);
    }
    else if (move==2) for (int i=1;i<=6;i++){
        if (ret+cup(A,B_size,i)<mn) mn=ret+cup(A,B_size,i);
    }
    else if (move==3) for (int i=1;i<=6;i++){
        if (ret+cup(0,B,i)<mn) mn=ret+cup(0,B,i);
    }
    else if (move==4) for (int i=1;i<=6;i++){
        if (ret+cup(A,0,i)<mn) mn=ret+cup(A,0,i);
    }
    else if (move==5){
        int next_B=B+A>B_size?B_size:B+A;
        int next_A=next_A-(next_B-B);
        for (int i=1;i<=6;i++){
            if (ret+cup(next_A,next_B,i)<mn) mn=ret+cup(next_A,next_B,i);
        }
    } 
    else if (move==6){
        int next_A=A+B>A_size?A_size:A+B;
        int next_B=next_B-(next_A-A);
        for (int i=1;i<=6;i++){
            if (ret+cup(next_A,next_B,i)<mn) mn=ret+cup(next_A,next_B,i);
        }
    }
    dp[A][B][move]=mn;
    return mn;
}   

int main()
{
    cin >> A_size >> B_size >> ret_A >> ret_B;
    for (int i=1;i<=6;i++){
        ret=min(ret,cup(0,0,i));
    }
    printf("%d",ret);
}