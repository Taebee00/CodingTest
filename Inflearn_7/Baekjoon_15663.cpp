#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;
vector<vector<int>> per_v;

void per(int n,int m,int depth){
    if (depth==M){
        int flag=0;
        if (per_v.size()){
            for (auto&i:per_v){
                int temp_flag=0;
                for (int j=0;j<m;j++){
                    if (i[j]!=v[j]){                       
                        temp_flag=1;
                        break;
                    }
                }
                if (!temp_flag){
                    flag=1;
                    break;
                }
            }
        }
        if (!per_v.size()||!flag){
            vector<int> temp_v;
            for (int i=0;i<m;i++){
                temp_v.push_back(v[i]);
            }
            per_v.push_back(temp_v);
            return;
        }
    }
    for (int i=depth;i<n;i++){
        swap(v[depth],v[i]); 
        per(n,m,depth+1);
        swap(v[depth],v[i]);
    }
}

int main()
{
    cin >> N >> M;
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    per(N,M,0);
    sort(per_v.begin(),per_v.end());
    for (auto&i:per_v){
        for (int j=0;j<M;j++){
            printf("%d ",i[j]);
        }
        printf("\n");
    }
}