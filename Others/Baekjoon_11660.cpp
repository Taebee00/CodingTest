#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M, mp[1024][1024],sum_mp[1024][1024];
    long long sum=0;
    vector<vector<int>> v;
    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j];
            sum+=mp[i][j];
            sum_mp[i][j]+=sum;
        }
    }
    for (int i=0;i<M;i++){
        int x_1,x_2,y_1,y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        
        v.push_back({x_1-1,y_1-1,x_2-1,y_2-1});
    }
    for (auto&i:v){
        long long ret=0;
        for (int j=i[1];j<=i[3];j++){
            if (i[0]==0){
                ret+=sum_mp[j][i[2]];
            }
            else{
                ret+=sum_mp[j][i[2]]-sum_mp[j][i[0]-1];
            }
        }
        cout << ret;
    }
}