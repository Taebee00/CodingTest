#include <bits/stdc++.h>
using namespace std;

int h,w,visitied[54][54]={0,};
char mp[54][54];
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
vector<pair<int,int>> v;
queue<pair<int,int>> q;
int ret=0;

void init(){
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            visitied[i][j]=0;
        }
    }
}

int bfs(int _y,int _x){
    int mx=0;
    q.push({_y,_x});
    visitied[_y][_x]=1;
    while (q.size()){
        pair<int,int> loc=q.front();
        for (int i=0;i<4;i++){
            int x=loc.second+dx[i]; int y=loc.first+dy[i];
            if (x>=0&&x<w&&y>=0&&y<h&&mp[y][x]=='L'&&!visitied[y][x]){
                visitied[y][x]=visitied[loc.first][loc.second]+1;
                q.push({y,x});
                mx=visitied[y][x];
            }
        }
        q.pop();
    }
    return mx;
}

int main(){
    cin >> h >> w;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> mp[i][j];
            if (mp[i][j]=='L'){
                v.push_back({i,j});
            }
        }
    }
    for (int i=0;i<v.size();i++){
        if (!visitied[v[i].first][v[i].second]){
            ret=max(bfs(v[i].first,v[i].second),ret);
            init();
        }
    }  
    cout << ret-1;
}