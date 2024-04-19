#include <bits/stdc++.h>

using namespace std;

int N, M, answer=0, visitied[50][50]={0,};
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
char arr[50][50];
vector<pair<int,int>> land_v;

int bfs(int y, int x){
    int ret=0;
    fill(&visitied[0][0],&visitied[0][0]+50*50,0);
    visitied[y][x]=1;
    queue<pair<int,int>> que;
    que.push({y,x});
    while(que.size()){
        pair<int,int> temp=que.front();
        que.pop();
        for (int i=0;i<4;i++){
            int ny=temp.first+dy[i];
            int nx=temp.second+dx[i];
            if (ny<0||nx<0||ny>=N||nx>=M) continue;
            if (visitied[ny][nx]||arr[ny][nx]=='W') continue;
            visitied[ny][nx]=visitied[temp.first][temp.second]+1;
            ret=max(visitied[ny][nx],ret);
            que.push({ny,nx});
        }
    }
    return ret-1;
}

int main()
{
    cin >> N >> M;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> arr[i][j];
            if (arr[i][j]=='L') land_v.push_back({i,j});
        }
    }

    for (int i=0;i<land_v.size();i++){
        answer=max(bfs(land_v[i].first,land_v[i].second),answer);
    }

    cout << answer;
}