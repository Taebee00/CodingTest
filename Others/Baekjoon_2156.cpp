#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int dp[10001];

int main()
{
    int N;
    cin >> N;
    for (int i=1;i<=N;i++){
        cin >> arr[i];
    }
    dp[1]=arr[1];
    dp[2]=arr[1]+arr[2];
    for (int i=3;i<=N;i++){
        dp[i]=max(arr[i]+dp[i-2],arr[i-1]+arr[i]+dp[i-3]);
        dp[i]=max(dp[i],dp[i-1]);
        
    }
    // for (int i=0;i<=N;i++){
    //     printf("%d ",dp[i]);
    // }
    printf("%d",dp[N]);
}