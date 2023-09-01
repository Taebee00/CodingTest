#include <bits/stdc++.h>

using namespace std;

struct node{
    int y;
    int x;
    int dir;
};

int N, home[16][16], visitied[16][16][3], dp[16][16][3];
vector<vector<int>> v;
queue<pair<pair<int,int>,int>> q;

void bfs(int y,int x,int dir)
{
    q.push({{y,x},dir});
    dp[0][1][0]=1;
    while(q.size()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int dir=q.front().second;
        //printf("%d %d %d\n",y,x,dir);
        if (dir==0){
            if (x+1<N&&!home[y][x+1]&&!visitied[y][x+1][0]){
                dp[y][x+1][0]+=dp[y][x][0];
                visitied[y][x+1][0]=1;
                q.push({{y,x+1},0});
                if (y+1<N&&!home[y+1][x+1]&&!home[y][x+1]&&!home[y+1][x]&&!visitied[y+1][x+1][1]){
                    q.push({{y+1,x+1},1});
                    visitied[y+1][x+1][1]=1;
                    dp[y+1][x+1][1]+=dp[y][x][0];
                }
            }
        }
        else if (dir==1){
            if (x+1<N&&y+1<N&&!home[y+1][x+1]&&!home[y][x+1]&&!home[y+1][x]&&!visitied[y+1][x+1][1]){
                dp[y+1][x+1][1]+=dp[y][x][1];
                visitied[y+1][x+1][1]=1;
                q.push({{y+1,x+1},1});
            }
            if (x+1<N&&!home[y][x+1]&&!visitied[y][x+1][0]){
                dp[y][x+1][0]+=dp[y][x][1];
                visitied[y][x+1][0]=1;
                q.push({{y,x+1},0});
            }
            if (y+1<N&&!home[y+1][x]&&!visitied[y+1][x][2]){
                dp[y+1][x][2]+=dp[y][x][1];
                visitied[y+1][x][2]=1;
                q.push({{y+1,x},2});
                if (y+1==3&&x==4){
                    printf("%d %d %d\n",y,x,dir);
                    printf("%d\n",dp[y+1][x][2]);
                }
            }
        }
        else{
            if (y+1<N&&!home[y+1][x]&&!visitied[y+1][x][2]){
                dp[y+1][x][2]+=dp[y][x][2];
                visitied[y+1][x][2]=1;
                if (y+1==3&&x==4){
                    printf("%d %d %d\n",y,x,dir);
                    printf("%d\n",dp[y+1][x][2]);
                }
                q.push({{y+1,x},2});
                if (x+1<N&&!home[y+1][x+1]&&!home[y][x+1]&&!home[y+1][x]&&!visitied[y+1][x+1][1]){
                    dp[y+1][x+1][1]+=dp[y][x][2];
                    visitied[y+1][x+1][1]=1;
                    q.push({{y+1,x+1},1});
                }
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> home[i][j];
        }
    }
    bfs(0,1,0);
    cout << visitied[N-1][N-1];
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            int sum=0;
            printf("{ ");
            for (int k=0;k<3;k++){
                printf("%d ",dp[i][j][k]);
                //sum+=dp[i][j][k];
            }
            printf("} ");
            //printf("%d ",sum);
        }
        printf("\n");
    }
}