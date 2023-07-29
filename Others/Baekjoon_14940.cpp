#include <bits/stdc++.h>

using namespace std;

int n, m, goal_x, goal_y, mp[1004][1004], visitied[1004][1004];

int dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};

void bfs(int _y,int _x){
    queue<pair<int,int>> q;
    q.push({_y,_x});
    visitied[_y][_x]=0;
    while(q.size()){
        for (int i=0;i<4;i++){            
            int y=q.front().first+dy[i];
            int x=q.front().second+dx[i];    
            if (x>=0&&x<m&&y>=0&&y<n&&visitied[y][x]==-1&&mp[y][x]){
                q.push({y,x});
                visitied[y][x]=visitied[q.front().first][q.front().second]+1;
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> mp[i][j];
            if (mp[i][j]==2){
                goal_y=i;
                goal_x=j;
            }
            visitied[i][j]=-1;
        }
    }
    bfs(goal_y,goal_x);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!mp[i][j]){
                cout << "0 ";
            }
            else{
                cout << visitied[i][j] << " ";
            }
        }
        cout << "\n";
    }
}