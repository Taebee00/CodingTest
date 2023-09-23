#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long dp[2001];
    fill(dp,dp+n+1,0);
    dp[0]=1;
    dp[1]=1;
    for (int i=2;i<=n;i++){
        dp[i]=dp[i-2]+dp[i-1];
        dp[i]%=1234567;
    }
    return dp[n];
}