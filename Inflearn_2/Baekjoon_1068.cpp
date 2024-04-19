#include <bits/stdc++.h>

using namespace std;

int N, root, erase_node, visitied[50]={0,};
vector<int> vec_arr[50];

void erase_dfs(int node){
    visitied[node]=1;
    for (int i:vec_arr[node]){
        if (!visitied[i]) erase_dfs(i);
    }
}

int find_leaf_dfs(int node){
    int cnt=0;
    int sum=0;
    for (int i:vec_arr[node]){
        if (visitied[i]==0){
            cnt++;
            sum+=find_leaf_dfs(i);
        }
    }
    if (cnt==0) return 1;
    else return sum;
}

int main()
{
    cin >> N;

    for (int i=0;i<N;i++){
        int node;
        cin >> node;
        if (node==-1){
            root=i;
            continue;
        }
        vec_arr[node].push_back(i);
    }

    cin >> erase_node;

    erase_dfs(erase_node);

    if (erase_node==root) cout << 0;
    else cout << find_leaf_dfs(root);
}