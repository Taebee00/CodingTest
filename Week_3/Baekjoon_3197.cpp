#include <bits/stdc++.h>
using namespace std;

int h,w; pair<int,int> L[2];
char mp[1500][1500];
int x_visitied[1500][1500]={0,}, l_visitied[1500][1500]={0,};
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
queue<pair<int,int>> l_q,x_q,x_q2;

// x_q에 초기 상태에서 물과 인접한 빙판 좌표를 모두 push;
void dfs(int y,int x){
    x_visitied[y][x]=1;
    for (int i=0;i<4;i++){
        int _y=y+dy[i]; int _x=x+dx[i];
        if (_y>=0&&_y<h&&_x>=0&&_x<w&&!x_visitied[_y][_x]){
            if (mp[_y][_x]=='X'){
                x_q.push({_y,_x});
                x_visitied[_y][_x]=x_visitied[y][x]+1;
            }
        }
    }
}

void L_dfs(int y,int x){
    l_visitied[y][x]=1;
    for (int i=0;i<4;i++){
        int _y=y+dy[i]; int _x=x+dx[i];
        if (_y>=0&&_y<h&&_x>=0&&_x<w&&!l_visitied[_y][_x]){
            if (mp[_y][_x]=='.'){
                L_dfs(_y,_x);
            }
            else if (mp[_y][_x]=='X'){
                l_q.push({_y,_x});
            }
        }
    }
}

void find(){
    while(!x_q.empty()){
        for (int i=0;i<4;i++){
            int _y=x_q.front().first+dy[i]; int _x=x_q.front().second+dx[i];
            if (_y>=0&&_y<h&&_x>=0&&_x<w&&!x_visitied[_y][_x]){
                if (mp[_y][_x]=='X'){
                    x_visitied[_y][_x]=x_visitied[x_q.front().first][x_q.front().second];
                    x_q2.push({_y,_x});
                    mp[_y][_x]='.';
                }
            }
        }
        x_q.pop();
    }

    while(!x_q2.empty()){
        x_q.push({x_q2.front().first,x_q2.front().second});
        x_q2.pop();
    }
}

int main(){
    cin >> h >> w;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> mp[i][j];
            if (mp[i][j]=='.'){
                dfs(i,j);
            }
            int L_cnt=0;
            if (mp[i][j]=='L'){
                L[L_cnt].first=i;
                L[L_cnt++].second=j;
            }
        }
    }
    L_dfs(L[0].first,L[0].second);
    find();
}