#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, mn=2e18, mx=-10000;
char arr[5][5];
int dy[2]={0,1}, dx[2]={1,0};
vector<pair<int,int>> v;

int go(int num1,char cal,int num2){
    if (cal=='*') return num1*num2;
    else if (cal=='+') return num1+num2;
    else if (cal=='-') return num1-num2;
}

void dfs(int y,int x,int dir,char cal,int sum){
    // 종료조건
    if (y==N-1&&x==N-1){
        //cout << "------------------\n";
        // for (auto i:v) cout << i.first << "," << i.second << " -> " ;
        // cout << sum  << "\n";
        mn=min(sum,mn);
        mx=max(sum,mx);
        return;
    }
    // 재귀호출
    int ny=y+dy[dir];
    int nx=x+dx[dir];
    if (ny<0||nx<0||ny>=N||nx>=N) return;
    v.push_back({ny,nx});
    if (cal=='N'){
        dfs(ny,nx,0,arr[ny][nx],sum);
        dfs(ny,nx,1,arr[ny][nx],sum);
    }
    else{
        int val=go(sum,cal,int(arr[ny][nx]-'0'));
        dfs(ny,nx,0,'N',val);
        dfs(ny,nx,1,'N',val);
    }
    v.pop_back();
}

int main()
{
    
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    dfs(0,0,0,'N',int(arr[0][0]-'0'));
    dfs(0,0,1,'N',int(arr[0][0]-'0'));
    cout << mx << " " << mn;
}