#include <bits/stdc++.h>
using namespace std;

int h,w,mx=1,visitied[20][20]={0,}, dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
char mp[20][20];
pair<int,int> parent[20][20];
vector<char> v;

void dfs(int y,int x){
    for (int i=0;i<4;i++){
        int ny=y+dy[i]; int nx=x+dx[i];
        if (ny>=0&&ny<h&&nx>=0&&nx<w&&!visitied[ny][nx]){
            if (find(v.begin(),v.end(),mp[ny][nx])==v.end()){ 
                visitied[ny][nx]=visitied[y][x]+1;
                v.push_back(mp[ny][nx]);
                mx=max(visitied[ny][nx],mx);
                dfs(ny,nx);
            }
        }
    }
    visitied[y][x]=0;
    v.erase(v.end()-1);
}

int main(){
    cin >> h >> w;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> mp[i][j];
        }
    }
    v.push_back(mp[0][0]);
    visitied[0][0]=1;
    dfs(0,0);
    cout << mx;
}