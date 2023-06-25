#include <bits/stdc++.h>
using namespace std;

int h,w,dist,cnt=0,ret=0,visitied[10][10]={0,};
char mp[10][10];
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

void init(){
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            visitied[i][j]=0;
        }
    }
}

void dfs(int sy,int sx,int d,int cnt){
    //cout << sy << " " << sx << "\n";
    if (cnt==dist){
        if (sy==0&&sx==w-1){
            ret++;
        }
        init();
        return;
    }
    cnt++;
    visitied[sy][sx]=1;
    for (int i=0;i<4;i++){
        if (d!=i){
            int x=sx+dx[i]; int y=sy+dy[i];
            if (x>=0&&x<w&&y>=0&&y<h&&mp[y][x]!='T'&&!visitied[y][x]){
                dfs(y,x,(i+2)%4,cnt);
            }
        }
    }
}

int main(){
    cin >> h >> w >> dist;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> mp[i][j];
        }
    }
    dfs(h-1,0,-1,1);
    cout << ret;
}

