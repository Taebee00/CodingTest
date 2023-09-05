#include <bits/stdc++.h>

using namespace std;

int N, L[20], J[20], dp[101];

int main()
{
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> L[i];
    }
    for (int i=0;i<N;i++){
        cin >> J[i];
    }
    for (int i=0;i<N;i++){
        for (int j=100;j>=0;j--){
            if (j-L[i]>0){
                dp[j]=max(dp[j-L[i]]+J[i],dp[j]);
            }
        }
    }
    printf("%d",dp[100]);
}