#include <bits/stdc++.h>

using namespace std;

long long dp[101][10],ret=9;

int main()
{
    int N;

    dp[1][0]=0;
    fill(&dp[1][1],&dp[1][10]+1,1);

    cin >> N;

    for (int i=2;i<=N;i++){
        long long sum=0;
        for (int j=0;j<=9;j++){
            if (j==0) dp[i][0]=dp[i-1][1];
            else if (j==9) dp[i][9]=dp[i-1][8];
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
            sum+=dp[i][j];
            sum%=1000000000;
        }
        ret=sum;
    }
    printf("%lld",ret%1000000000);
}