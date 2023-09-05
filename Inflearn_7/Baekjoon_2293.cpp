#include <bits/stdc++.h>

using namespace std;

int n,k,arr[101],dp[10001],exist[10001][100];

int main()
{  
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    dp[0]=1;
    for (int i=0;i<=k;i++){
        for (int j=0;j<n;j++){
            if (i-arr[j]>=0){
                dp[i]+=dp[i-arr[j]];
            }
        }
    }
    printf("%d",dp[k]);
}