#include <bits/stdc++.h>
using namespace std;

int num, node, cut, cnt=0, flag[100]={0,}; 
vector<int> v[100];

void dfs(int x){
    flag[x]=1;
    if (v[x].size()){
        for (auto&j:v[x]){
            dfs(j);
        }
    }
}

int main(){
    cin >> num;
    for (int i=0;i<num;i++){
        cin >> node;
        if (node==-1){
            continue;
        }
        v[node].push_back(i);
    }
    cin >> cut;
    dfs(cut);
    for (int i=0;i<num;i++){
        if (v[i].size()==1&&v[i][0]==cut){
            cnt++;
        }
    }
    for (int i=0;i<num;i++){
        if (!v[i].size()&&!flag[i]){
            cnt++;
        }
    }
    cout << cnt;
}