#include <bits/stdc++.h>
using namespace std;

int N,people[11],mn=INT_MAX,v1_sum=0,v2_sum=0,mp[11][11]={0,},visitied[11]={0,},v1_cnt=0,v2_cnt=0;

vector<int> v1,v2;

void v1_dfs(int num){
    v1_cnt++;
    v1_sum+=people[num];
    visitied[num]=1;
    for (int i=1;i<=N;i++){
        if (mp[num][i]&&binary_search(v1.begin(),v1.end(),i)&&!visitied[i]){
            v1_dfs(i);
        }
    }
}

void v2_dfs(int num){
    v2_cnt++;
    v2_sum+=people[num];
    visitied[num]=1;
    for (int i=1;i<=N;i++){
        if (mp[num][i]&&binary_search(v2.begin(),v2.end(),i)&&!visitied[i]){
            v2_dfs(i);
        }
    }
}

int main(){
    cin >> N;
    for (int i=1;i<=N;i++){
        cin >> people[i];
    }
    for (int i=1;i<=N;i++){
        int num;
        cin >> num;
        for (int j=0;j<num;j++){
            int node;
            cin >> node;
            mp[i][node]=1;
            mp[node][i]=1;
        }
    }
    for (int i=1;i<(1<<N);i++){
        v1.clear();
        v2.clear();
        v1_sum=0,v2_sum=0,v1_cnt=0,v2_cnt=0;
        for (int j=1;j<=N;j++){
            visitied[j]=0;
        }
        for (int j=0;j<N;j++){
            if (i&(1<<j)){
                v1.push_back(j+1);
            }
            else{
                v2.push_back(j+1);
            }
        }
        if (v1.size()){
            v1_dfs(v1[0]);
        }
        if (v2.size()){
            v2_dfs(v2[0]);
        }
        if (v1_cnt==v1.size()&&v2_cnt==v2.size()&&abs(v1_sum-v2_sum)<mn)
        {
            mn=abs(v1_sum-v2_sum);
        }
    }
    mn==INT_MAX?cout<<"-1":cout << mn;
}