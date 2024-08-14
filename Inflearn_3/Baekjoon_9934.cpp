#include <bits/stdc++.h>
using namespace std;

int k, order_cnt=0,order[1500]={0,};
vector<int> v[10];

void dfs(int cnt, int sz){
    if (sz==k){
        v[sz].push_back(order[order_cnt++]);
        return;
    }
    dfs(++cnt,sz+1);
    v[sz].push_back(order[order_cnt++]); 
    dfs(++cnt,sz+1);
}

int main(){
    cin >> k;
    int num=1,cnt=0;
    for (int i=1;i<=k;i++){
        for (int k=0;k<num;k++){
            cin >> order[cnt++];
        }
        num*=2;
    }
    dfs(0,1);
    for (int i=1;i<=k;i++){
        for (auto &j:v[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

struct node{
    int num;
    int left;
    int right;
};

struct node root;
int K, visitied[3000]={0,};

void dfs(int n){
    queue<struct node> que;
    que.push(root);
    visitied[root]=1;
    while(que.size()){
        struct node temp=que.front();
        que.pop();
        if (visitied[temp.num]>K) continue;
        
    }
}


int main()
{
    root.num=0;
    bfs(root);
}