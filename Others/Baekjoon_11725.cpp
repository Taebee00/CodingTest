#include <bits/stdc++.h>

using namespace std;

vector<int> tr[100001];
int N, visitied[100001], parent[100001];
vector<vector<int>> v;

void dfs(int n){
    visitied[n]=1;
    for (int &i:tr[n]){
        if (!visitied[i]){
            parent[i]=n;
            dfs(i);
        }
    }
}

int main()
{
    
    cin >> N;
    for (int i=0;i<N-1;i++){
        int temp[2];
        cin >> temp[0] >> temp[1];
        tr[temp[0]].push_back(temp[1]);
        tr[temp[1]].push_back(temp[0]);
    }
    dfs(1);
    for (int i=2;i<=N;i++){
        printf("%d\n",parent[i]);
    }
}