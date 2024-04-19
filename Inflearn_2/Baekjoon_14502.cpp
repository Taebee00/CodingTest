#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> choice_v;
vector<vector<pair<int,int>>> choice_v2;
vector<pair<int,int>> v; 
vector<pair<int,int>> virus_v;
int N, M, arr[8][8], visitied[8][8], temp[8][8], answer=64, cnt=0, wall_cnt=3;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

void choose(int n, int r,int depth){
    if (choice_v.size()==3){
        choice_v2.push_back(choice_v);
        return;
    }
    for (int i=depth+1;i<n;i++){
        choice_v.push_back(v[i]);
        choose(n,r,i);
        choice_v.pop_back();
    }
}

int dfs(int y,int x){
    int sum=1;
    visitied[y][x]=1;
    for (int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||nx<0||ny>=N||nx>=M) continue;
        if (visitied[ny][nx]||temp[ny][nx]==1) continue;
        sum+=dfs(ny,nx); 
    }
    return sum;
}

int main()
{    
    cin >> N >> M;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> arr[i][j];
            if (arr[i][j]==0) v.push_back({i,j});
            if (arr[i][j]==2) virus_v.push_back({i,j});
            if (arr[i][j]==1) wall_cnt++;
        }
    }

    choose(v.size(),3,-1);

    for (auto i:choice_v2){
        cnt=0;
        memcpy(temp,arr,sizeof(arr));
        fill(&visitied[0][0],&visitied[0][0]+8*8,0);
        for (auto j:i){
            if (temp[j.first][j.second]==0) temp[j.first][j.second]=1;
        }
        for (auto j:virus_v){
            if (visitied[j.first][j.second]==0) cnt+=dfs(j.first,j.second);
        }
        answer=min(cnt,answer);
    }
    cout << N*M-(answer+wall_cnt);
}