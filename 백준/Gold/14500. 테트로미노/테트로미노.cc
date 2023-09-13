#include <bits/stdc++.h>

using namespace std;

int N,M,mp[501][501],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};

int dfs(int y,int x,int sz,int sum,int dir){
    if (sz==4){
        return sum;
    }
    int mx=0;
    for (int i=0;i<4;i++){
        int next_y=y+dy[i];
        int next_x=x+dx[i];       
        if (next_y>=0&&next_x>=0&&next_y<N&&next_x<M&&((i+2)%4!=dir)){
            mx=max(mx,dfs(next_y,next_x,sz+1,sum+mp[next_y][next_x],i));
        }
    }
    return mx;
}

int main()
{
    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> mp[i][j];
        }
    }
    int mx=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            mx=max(mx,dfs(i,j,1,mp[i][j],5));
            int mn=INT_MAX, sum=mp[i][j], cnt=0;
            for (int k=0;k<4;k++){
                int y=i+dy[k], x=j+dx[k];
                if (y>=0&&x>=0&&y<N&&x<M){
                    sum+=mp[y][x];
                    mn=min(mn,mp[y][x]);
                    cnt++;
                }
            }
            if (cnt==4) sum-=mn;
            mx=max(mx,sum);
        }
        //printf("\n");
    }
    printf("%d",mx);
}