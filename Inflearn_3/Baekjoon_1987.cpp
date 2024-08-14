#include <bits/stdc++.h>

using namespace std;

int R, C, answer=0, visitied[20][20]={0,};
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
char arr[20][20];
vector<char> v;

void dfs(int y,int x)
{
    visitied[y][x]=1;
    v.push_back(arr[y][x]);
    for (int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||nx<0||ny>=R||nx>=C) continue;
        if (visitied[ny][nx]||find(v.begin(),v.end(),arr[ny][nx])!=v.end()) continue;
        dfs(ny,nx);
    }
    answer=max(answer,int(v.size()));
    visitied[y][x]=0;
    v.pop_back();
}

int main()
{
    cin >> R >> C;

    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> arr[i][j];
        }
    }
    dfs(0,0);
    cout << answer;
}