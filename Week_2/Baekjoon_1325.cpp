#include <bits/stdc++.h>
using namespace std;

int com_1, com_2, com_num, trust_num, ret=0, mx=0, visitied[10001]={0,};
vector<int> v[10001]; vector<int> max_v;

void init(){
    for (int i=0;i<=com_num;i++){
        visitied[i]=0;
    }
    ret=0;
}

void dfs(int i){
    ret++;
    visitied[i]=1;
    if (v[i].size()){
        for (auto&j:v[i]){
            if (!visitied[j]){
                dfs(j);
            }
        }
    }
}

int main(){
    cin >> com_num >> trust_num;
    for (int i=0;i<trust_num;i++){
        cin >> com_1 >> com_2;
        v[com_2].push_back(com_1);
    }
    for (int i=0;i<=com_num;i++){
        dfs(i);
        if (ret>mx){
            mx=ret;
            max_v.clear();
            max_v.push_back(i);
        }
        else if (ret==mx){
            max_v.push_back(i);
        }
        init();
    }
    sort(max_v.begin(),max_v.end());
    for (auto&i:max_v){
        cout << i << " ";
    }
}