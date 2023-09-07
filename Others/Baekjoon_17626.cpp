#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    int i=1;
    while(i*i<=50000){
        v.push_back(i*i);
        i++;
    }
    int dp[50001];
    fill(dp,dp+50001,INT_MAX);
    dp[0]=0;
    for (int i=1;i<=n;i++){
        for (int j:v){
            if (i-j>=0){
                dp[i]=min(dp[i],dp[i-j]+1);
            }
        }
    }
    printf("%d",dp[n]);
}