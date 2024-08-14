#include <bits/stdc++.h>

using namespace std;

int N, M, visitied[10]={0,};
vector<int> v;

void dfs(int sz){
    if (sz==M){
        for (int i:v) cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i=1;i<=N;i++){
        v.push_back(i);
        dfs(sz+1);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    dfs(0);
}