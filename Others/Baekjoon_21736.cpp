#include <bits/stdc++.h>

using namespace std;

int N,M,visitied[600][600]={0,};
char mp[600][600];
int start_y,start_x;
int dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};

int dfs(int _y,int _x){
    int ret=0;
    visitied[_y][_x]=1;
    for (int i=0;i<4;i++){
        int y=_y+dy[i];
        int x=_x+dx[i];
        if (y>=0&&y<N&&x>=0&&x<M&&!visitied[y][x]&&mp[y][x]!='X'){
            if (mp[y][x]=='P'){
                ret++;
            }
            ret+=dfs(y,x);
        }
    }
    return ret;
}

int main()
{
    cin >> N >> M;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> mp[i][j];
            if (mp[i][j]=='I'){
                start_y=i;
                start_x=j;
            }
        }
    }

    int ret=dfs(start_y,start_x);
    if (!ret) cout << "TT";
    else cout << ret;
}