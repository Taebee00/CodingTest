#include <bits/stdc++.h>

using namespace std;

int M, N, K, answer_cnt;
int arr[100][100]={0,}, visitied[100][100]={0,};
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<int> answer_v;

int dfs(int y,int x){
    int sum=1;
    visitied[y][x]=1;
    for (int i=0;i<4;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if (ny<0||nx<0||ny>=M||nx>=N) continue;
        if (visitied[ny][nx]||arr[ny][nx]) continue;
        sum+=dfs(ny,nx);
    }
    return sum;
}

int main()
{
    cin >> M >> N >> K;

    for (int i=0;i<K;i++){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;

        for (int j=ly;j<ry;j++){
            for (int k=lx;k<rx;k++){
                arr[j][k]=1;
            }
        }
    } 

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            if (arr[i][j]==0&&(!visitied[i][j])){
                answer_v.push_back(dfs(i,j));
                answer_cnt++;
            }
        }
    }

    cout << answer_cnt << "\n";
    sort(answer_v.begin(),answer_v.end());
    for (int i:answer_v) cout << i << " ";
}