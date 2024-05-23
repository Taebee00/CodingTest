#include <bits/stdc++.h>

using namespace std;

int N, M, mp[8][8],ret=INT_MAX;
vector<pair<int,int>> v;

int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
vector<vector<int>> dir={{},{1},{1,3},{0,1},{3,0,1},{0,1,2,3}};

void choose(int sz){
    if (sz==v.size()){
        int cnt=0;
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (!mp[i][j]){
                    cnt++;
                }
            }
        }
        ret=min(ret,cnt);
        return;
    }
    pair<int,int> i=v[sz];
    for (int j=0;j<4;j++){
        //printf("%d %d\n",sz,j);
        vector<pair<int,int>> temp_v;
        for (auto&k:dir[mp[i.first][i.second]]){
            int y=i.first;
            int x=i.second;
            while(mp[y][x]!=6){
                y=y+dy[(k+j)%4];
                x=x+dx[(k+j)%4];
                if (y>=0&&y<N&&x>=0&&x<M&&mp[y][x]!=6){
                    if (!mp[y][x]){
                        mp[y][x]=-1;
                        temp_v.push_back({y,x});
                    }
                }
                else{
                    break;
                }
            }
        }
        choose(sz+1);
        for (auto&k:temp_v){
            mp[k.first][k.second]=0;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> mp[i][j];
            if (mp[i][j]>=1&&mp[i][j]<=5){
                v.push_back({i,j});
            }
        }
    }
    choose(0);
    cout << ret;
}