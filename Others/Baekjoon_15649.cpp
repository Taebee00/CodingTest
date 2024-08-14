#include <bits/stdc++.h>

using namespace std;

int N, M, visitied[10]={0,};
vector<int> v;

void dfs(int sz){
    if (sz==M){
        for (int i:v) cout << i << " ";
        cout << "\n";
    }
    for (int i=1;i<=N;i++){
        if (!visitied[i]){
            v.push_back(i);
            visitied[i]=1;
            dfs(sz+1);
            v.pop_back();
            visitied[i]=0;
        }
    }
}

int main()
{
    cin >> N >> M;

    dfs(0);
}