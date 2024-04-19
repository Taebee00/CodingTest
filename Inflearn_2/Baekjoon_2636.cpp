#include <bits/stdc++.h>

using namespace std;

int N, M, arr[100][100], visitied[100][100]={0,}, cnt=0, prev_cnt, clk=0;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};

// 가운데 구멍 2로 만들기
void dfs(int y,int x){
    arr[y][x]=0;
    visitied[y][x]=1;
    for (int i=0;i<4;i++){
        int ny=y+dy[i]; int nx=x+dx[i];
        if (ny<0||nx<0||ny>N||nx>M) continue;
        if (visitied[ny][nx]||arr[ny][nx]==1) continue;
        dfs(ny,nx);
    }
}

int main()
{
    cin >> N >> M;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> arr[i][j];
            if (arr[i][j]==1) cnt++;
        }
    }    

    dfs(0,0);

    for (int i=1;i<N-1;i++){
        for (int j=1;j<M-1;j++){
            if (visitied[i][j]==0&&arr[i][j]==0) arr[i][j]=2;
        }
    }

    while(cnt>0){
        vector<pair<int,int>> cheese_v;
        vector<pair<int,int>> hole_v;
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (arr[i][j]==0){
                    for (int k=0;k<4;k++){
                        int y=i+dy[k]; int x=j+dx[k];
                        if (y<1||x<1||y>N-1||x>M-1) continue;
                        if (arr[y][x]==1){
                            cheese_v.push_back({y,x});
                        }
                    }
                }
            }
        }
        prev_cnt=cnt;
        for (auto i:cheese_v){
            if (arr[i.first][i.second]==1){
                arr[i.first][i.second]=0;
                cnt--;
            }
        }
        fill(&visitied[0][0],&visitied[0][0]+100*100,0);
        dfs(0,0);
        clk++;
    }

    cout << clk << "\n" << prev_cnt;
}