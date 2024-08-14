#include <bits/stdc++.h>

using namespace std;

int TC, N, M, visitied[1001]={0,};
vector<string> answer_v;
map<int,vector<int>> mp;

int dfs(int node){
    visitied[node]=1;
    int sum=1;
    for (int i:mp[node]){
        if (!visitied[i]) sum+=dfs(i);
    }
    return sum;
}

int main()
{
    cin >> TC;

    for (int i=0;i<TC;i++){
        int edge_cnt=0, flag=1;
        cin >> N >> M;
        mp.clear();
        fill(visitied,visitied+1001,0);
        for (int j=0;j<M;j++){
            int a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        if (M+1==N){
            if (!mp[1].size()) answer_v.push_back("graph");
            else if (dfs(1)==N) answer_v.push_back("tree");
            else answer_v.push_back("graph");
        }
        else answer_v.push_back("graph");
    }

    for (string i:answer_v){
        cout << i << "\n";
    }
}