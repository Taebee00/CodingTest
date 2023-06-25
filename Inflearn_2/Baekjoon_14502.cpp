#include <bits/stdc++.h>
using namespace std;

int h,w,mp[8][8],mp_2[8][8], visitied[8][8]={0,};
vector<pair<int,int>> v;
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

void init(){
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            visitied[i][j]=0;
            mp_2[i][j]=mp[i][j];
        }
    }
}

void dfs(int i,int j){
    visitied[i][j]=1;
    mp_2[i][j]=2;
    for (int k=0;k<4;k++){
        int x=j+dx[k]; int y=i+dy[k];
        if (x>=0&&x<w&&y>=0&&y<h){
            if (!visitied[y][x]&&(mp_2[y][x]==0||mp_2[y][x]==2)){
                dfs(y,x);
            }
        }
    }
}

int find(){
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (mp_2[i][j]==2&&!visitied[i][j]){
                dfs(i,j);
            }
        }
    }
    int cnt=0;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (!mp_2[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    cin >> h >> w;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> mp[i][j];
            mp_2[i][j]=mp[i][j];
            v.push_back({i,j});
        }
    }
    int max=0;
    for (int i=0;i<v.size()-2;i++){
        for (int j=i+1;j<v.size()-1;j++){
            for (int k=j+1;k<v.size();k++){
                if (!mp_2[v[i].first][v[i].second]&&!mp_2[v[j].first][v[j].second]&&!mp_2[v[k].first][v[k].second]){
                    mp_2[v[i].first][v[i].second]=1;
                    mp_2[v[j].first][v[j].second]=1;
                    mp_2[v[k].first][v[k].second]=1;
                    int cnt=find();
                    if (cnt>max) max=cnt;
                    //cout << cnt << "\n";
                    init();
                }
            }
        }
    }
    cout << max;
}