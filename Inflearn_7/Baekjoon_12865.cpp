#include <bits/stdc++.h>

using namespace std;

int N,K,dp[100001];
vector<pair<int,int>> v;

int main()
{
    cin >> N >> K;
    for (int i=0;i<N;i++){
        pair<int,int> temp;
        cin >> temp.first >> temp.second;
        v.push_back(temp);
    }
    for (int i=0;i<N;i++){
        for (int j=K;j>=v[i].first;j--){
            //if (dp[j-v[i].first]!=-1){
            dp[j]=max(dp[j-v[i].first]+v[i].second,dp[j]);
            //}
        }   
    }
    printf("%d ",dp[K]);
}