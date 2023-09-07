#include <bits/stdc++.h>

using namespace std;

int N,K,dp[100001];
queue<pair<int,int>> q;

int bfs(int start,int end){
    q.push({start,0});
    while(q.size()){
        int num=q.front().first;
        int tm=q.front().second;
        if (dp[num]>=tm){
            dp[num]=tm;
            if (num==end){
                return tm;
            }
            if (num-1>=0){
                q.push({num-1,tm+1});
            }
            if (num<end){
                if (num+1<=100000) q.push({num+1,tm+1});
                if (num*2<=100000) q.push({num*2,tm});
            }
        }
        q.pop();
    }
    
}

int main()
{
    cin >> N >> K;
    fill(dp,dp+100000,INT_MAX);
    if (N>=K){
        cout << N-K;
    }
    else cout << bfs(N,K);
}