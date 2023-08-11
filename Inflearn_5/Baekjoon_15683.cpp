#include <bits/stdc++.h>

using namespace std;

int N, M, mp[8][8];
vector<pair<int,int>> v;
vector<int> dir;

vector<vector<pair<int,int>>> dir_v;

int cal()
{
    int temp_mp[8][8];
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            temp_mp[i][j]=mp[i][j];
        }
    }
    for (int i=0;i<v.size();i++){
        if (temp_mp[v[i].first][v[i].second]==1){

        }
    }
}

void choose(int sz){
    if (sz==v.size()){
        cal();
        return;
    }
    for (int i=0;i<4;i++){
        dir.push_back(i);
        choose(sz+1);
        dir.pop_back();
    }
}

int main()
{   
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> mp[i][j];
            if (mp[i][j]>2){
                v.push_back({i,j});
            }
        }
    }
    choose(0);
}