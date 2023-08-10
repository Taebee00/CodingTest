#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M, mp[10][10],sum_mp[10][10];
    int sum=0;
    vector<vector<int>> v;
    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j];
            sum+=mp[i][j];
            sum_mp[i][j]+=sum;
        }
        sum=0;
    }
    for (int i=0;i<M;i++){
        int x_1,x_2,y_1,y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        
        v.push_back({x_1,y_1,x_2,y_2});
    }
    for (auto&i:v){
        int big=0,top=0,left=0,right=0;
        for (int j=0;j<=i[3];j++){
            big+=sum_mp[j][N-1];
        }
        for (int j=0;j<i[1];j++){
            top+=sum_mp[j][N-1];
        }
        for (int j=i[1];j<=i[3];j++){
            if (i[0]-1>=0){
                left+=sum_mp[j][i[0]-1];
            }
        }
        for (int j=i[1];j<=i[3];j++){
            right+=sum_mp[j][N-1]-sum_mp[j][i[2]];
        }
        cout << big-top-left-right;
    }
}