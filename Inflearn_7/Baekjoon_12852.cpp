#include <bits/stdc++.h>

using namespace std;

int N,dp[1000001];

int recur(int N){
    int cnt=INT_MAX;
    if (N==1){
        dp[N]=0;
        return 0;
    }
    if (dp[N]){
        return dp[N];
    }
    if (N%3==0){
        cnt=min(recur(N/3),cnt);
    }
    if (N%2==0){
        cnt=min(recur(N/2),cnt);
    }
    cnt=min(recur(N-1),cnt);
    dp[N]=cnt+1;
    return cnt+1;
}

int main()
{
    cin >> N;
    printf("%d\n",recur(N));
    while(N!=1){
        printf("%d ",N);
        int mn=INT_MAX,mn_idx;
        if (N%3==0&&dp[N/3]<mn){
            mn=dp[N/3];
            mn_idx=N/3;
        }
        if (N%2==0&&dp[N/2]<mn){
            mn=dp[N/2];
            mn_idx=N/2;
        }
        if (dp[N-1]<mn){
            mn=dp[N-1];
            mn_idx=N-1;
        }
        N=mn_idx;     
    }
    printf("1");
}