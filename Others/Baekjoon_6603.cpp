#include <bits/stdc++.h>

using namespace std;

int k, temp, visitied[15];
vector<int> v, chosen_v;
vector<vector<int>> answer_v;

void dfs(int sz,int idx){
    if (sz==6){ 
        answer_v.push_back(chosen_v);
    }
    for (int i=idx+1;i<k;i++){
        chosen_v.push_back(v[i]);
        visitied[i]=1;
        dfs(sz+1,i);
        chosen_v.pop_back();
        visitied[i]=0;
    }
}

int main()
{
    while(true){
        v.clear();
        chosen_v.clear();
        answer_v.clear();
        cin >> k;
        if (k==0) break;
        for (int i=0;i<k;i++){
            cin >> temp;
            v.push_back(temp);
        }
        dfs(0,-1);
        for (auto i:answer_v){
            for (auto j:i){
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}