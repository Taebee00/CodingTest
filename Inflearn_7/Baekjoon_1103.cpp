#include <bits/stdc++.h>

using namespace std;

int N,M,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
int mp[50][50],dp[50][50],visitied[50][50];

int bfs(int _y,int _x)
{
    //printf("%d %d\n",_y,_x);
    int mx=0;
    if (_y<0||_y>=N||_x<0||_x>=M||mp[_y][_x]==0){
        return 0;
    }
    if (visitied[_y][_x]){
        cout << -1;
        exit(0);
    } 
    visitied[_y][_x]=1;
    if (dp[_y][_x]){
        visitied[_y][_x]=0;
        return dp[_y][_x];
    }
    for (int i=0;i<4;i++){
        int y=_y+(mp[_y][_x]*dy[i]); int x=_x+(mp[_y][_x]*dx[i]);
        mx=max(mx,bfs(y,x)+1);
    }
    dp[_y][_x]=mx;
    visitied[_y][_x]=0;
    return mx;
}

int main(){
    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            char temp;
            cin >> temp;
            if (temp=='H') mp[i][j]=0;
            else mp[i][j]=int(temp-'0');
        }
    }
    int ret=bfs(0,0);
    if (ret==INT_MAX-1) cout << -1;
    else cout << ret;
}