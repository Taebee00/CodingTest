#include <bits/stdc++.h>

using namespace std;

int n,k,dp[10000];
vector<int> v(100,0);

int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    fill(dp,dp+k+1,INT_MAX);
    dp[0]=0;
    for (int i=1;i<=k;i++){
        for (int &j:v){
            if (i-j>=0&&dp[i-j]!=INT_MAX){
                dp[i]=min(dp[i-j]+1,dp[i]);
            }
        }
    }
    // for (int i=1;i<=k;i++){
    //     printf("%d ",dp[i]);
    // }
    if (dp[k]==INT_MAX) printf("-1");
    else printf("%d",dp[k]);

}