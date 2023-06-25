#include <bits/stdc++.h>
using namespace std;

int h,w,mp[100][100],ret=0,visitied[100][100]={0,};
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
vector<int> v;

void init(){
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            visitied[i][j]=0;
        }
    }
}

void dfs(int _y,int _x){
    visitied[_y][_x]=1;
    for (int i=0;i<4;i++){
        int y=_y+dy[i]; int x=_x+dx[i];
        if (y>=0&&y<h&&x>=0&&x<w){
            if (!visitied[y][x]&&mp[y][x]==0){
                dfs(y,x);
            }
            else if (mp[y][x]==1){
                mp[y][x]=0;
                visitied[y][x]=1;
                ret++;
            }
        }
    }
}

int find(){
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (i==0||i==h-1||j==0||j==w-1){
                dfs(i,j);
            }
        }
    }
    init();
    return ret;
}

int main(){
    cin >> h >> w;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> mp[i][j];
        }
    }
    while(true){
        int sum=find();
        if (!sum){
            cout << v.size() << "\n" << v[v.size()-1];
            break;
        }
        v.push_back(sum);
        ret=0;
    }
}