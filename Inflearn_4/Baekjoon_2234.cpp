#include <bits/stdc++.h>

using namespace std;

int N, M, arr[50][50], visitied[50][50]={0,};
int answer_1=0, answer_2=0, answer_3=0;
int dy[4]={0,-1,0,1}, dx[4]={-1,0,1,0};
vector<pair<int,int>> v[2501];

int dfs(int y,int x){
    int ret=1;
    visitied[y][x]=answer_1;
    v[answer_1].push_back({y,x});
    for (int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||nx<0||ny>=M||nx>=N) continue;
        if (visitied[ny][nx]||(arr[y][x]&(1<<i))) continue;
        ret+=dfs(ny,nx);
    }
    return ret;
}

int main()
{
    cin >> N >> M;

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            if (!visitied[i][j]){
                answer_1++;
                answer_2=max(answer_2,dfs(i,j));
            }
        }
    }
    
    for (int i=1;i<=answer_1;i++){
        for (auto j:v[i]){
            for (int k=0;k<4;k++){
                int ny=j.first+dy[k];
                int nx=j.second+dx[k];
                if (ny<0||nx<0||ny>=M||nx>=N) continue;
                if (visitied[ny][nx]!=i){
                    answer_3=max(answer_3,int(v[i].size()+v[visitied[ny][nx]].size()));
                }
            }
        }
    }

    for (int i=1;i<=answer_1;i++){
    }
    cout << answer_1 << "\n" << answer_2 << "\n" << answer_3;
}