#include <bits/stdc++.h>

using namespace std;

int TC, N, M, visitied[21]={0,}, mx=0;
vector<int> v[21];

int dfs(int node, int cnt){
    mx=max(mx,cnt);
    for (int i:v[node]){
        if (!visitied[i]){
            visitied[i]=1;
            dfs(i, cnt+1);
            visitied[i]=0;
        }
    }
}

int main()
{
    cin >> TC;
    for (int i=1;i<=TC;i++){
        cin >> N >> M;
        int answer=1;
        for (int j=0;j<20;j++) v[j].clear();
        for (int j=0;j<M;j++){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        } 
        for (int j=1;j<=N;j++){
            fill(visitied,visitied+21,0);  
            mx=0;
            visitied[j]=1;
            dfs(j,1);
            answer=max(mx,answer);
        }
        printf("#%d %d\n",i,answer);
    }
}