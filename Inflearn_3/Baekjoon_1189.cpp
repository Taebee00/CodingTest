#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>


using namespace std;

char mp[5][5];
int h, w, dist, cnt=0, visitied[5][5]={0,};
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

void dfs(int y, int x){
    for (int i=0;i<4;i++){
        int nx=x+dx[i]; int ny=y+dy[i];
        if (nx>=0&&nx<w&&ny>=0&&ny<h&&!visitied[ny][nx]&&mp[ny][nx]=='.'){
            visitied[ny][nx]=visitied[y][x]+1;
            if (visitied[ny][nx]==dist){
                if (ny==0&&nx==w-1){
                    cnt++;
                }
            }
            dfs(ny,nx);
            visitied[ny][nx]=0;
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
    visitied[h-1][0]=1;
    dfs(h-1,0);
    cout << cnt;
}