#include <bits/stdc++.h>
using namespace std;

int sz, mn, mx, mp[50][50],visitied[50][50]={0,};
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
vector<pair<int,int>> v;

void init(){
    for (int i=0;i<sz;i++){
        for (int j=0;j<sz;j++){
            visitied[i][j]=0;
        }
    }
}

pair<int,int> dfs(int _y,int _x){
    visitied[_y][_x]=1;
    int cnt=1;
    int sum=mp[_y][_x];
    v.push_back({_y,_x});
    for (int i=0;i<4;i++){
        int x=_x+dx[i]; int y=_y+dy[i];
        if (y>=0&&y<sz&&x>=0&&x<sz&&!visitied[y][x]){
            if (abs(mp[_y][_x]-mp[y][x])>=mn&&abs(mp[_y][_x]-mp[y][x])<=mx){
                pair<int,int> ret=dfs(y,x);
                sum=ret.first+sum;
                cnt=ret.second+cnt;              
            }
        }
    }
    return {sum,cnt}; 
}

int main(){
    // 입력
    cin >> sz >> mn >> mx;
    for (int i=0;i<sz;i++){
        for (int j=0;j<sz;j++){
            cin >> mp[i][j];
        }
    }
    int flag=1, day=0;
    // 이동이 없을 때까지
    while(1){
        // 맵 전체를 돌며
        flag=0;
        for (int i=0;i<sz;i++){
            for (int j=0;j<sz;j++){
                if (!visitied[i][j]){
                    pair<int,int> ret=dfs(i,j); // 탐색을 해 연합의 갯수와 합 파악
                    int val=ret.first/ret.second; // 숫자 계산
                    if (ret.second>1){
                        flag=1;
                        for (auto&k:v){
                            mp[k.first][k.second]=val;
                        }
                    }
                    v.clear();
                }
            }
        }
        if (flag){
            day++;
        }
        else{
            cout << day;
            break;
        }
        init();
    }
}