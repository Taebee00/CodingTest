#include <bits/stdc++.h>

using namespace std;

int N, population[10];
vector<int> v[10];
vector<int> a_v, b_v;
int visitied[10]={0,};
int answer=INT_MAX;

int dfs(int idx, vector<int> &dfs_v){
    int sum=population[idx];
    visitied[idx]=1;
    for (int i:v[idx]){
        if (!visitied[i]&&find(dfs_v.begin(),dfs_v.end(),i)!=dfs_v.end()){
            sum+=dfs(i,dfs_v);
        }
    }
    return sum;
}

int cal(){
    int ret_a=dfs(a_v[0],a_v);
    int ret_b=dfs(b_v[0],b_v);
    int ret=abs(ret_a-ret_b);
    int cnt=0;
    for (int i=0;i<N;i++){
        if (visitied[i]) cnt++;
    }
    if (cnt!=N) return INT_MAX;
    return ret;
}

int main()
{

    cin >> N;

    for (int i=0;i<N;i++){
        cin >> population[i];
    }

    for (int i=0;i<N;i++){
        int temp;
        vector<int> temp_v;
        cin >> temp;
        for (int j=0;j<temp;j++){
            int temp_2;
            cin >> temp_2;
            temp_v.push_back(temp_2-1);
        }
        v[i]=temp_v;
    }

    for (int i=1;i<((1<<N)-1);i++){
        fill(visitied,visitied+10,0);
        a_v.clear(); b_v.clear();
        for (int j=0;j<N;j++){
            if (i&(1<<j)) a_v.push_back(j);
            else b_v.push_back(j);
        }
        answer=min(answer,cal());
    }
    if (answer==INT_MAX) cout << -1;
    else cout << answer;
}