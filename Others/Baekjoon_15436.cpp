#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;
int dp[1600000]={0,};

int main()
{
    int N;
    cin >> N;
    v.resize(N+1);
    for (int i=1;i<=N;i++){
        cin >> v[i].first >> v[i].second;
    }
    v[0]={0,0};
    for (int i=1;i<=N;i++){
        int T=v[i].first;
        int P=v[i].second;
        dp[i]=max(dp[i-1],dp[i]);
        dp[i+T-1]=max(dp[i+T-1],dp[i-1]+P);
    }
    //for (int i=0;i<=N;i++) cout << dp[i] << " ";
    cout << dp[N];
}