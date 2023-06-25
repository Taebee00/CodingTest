#include <bits/stdc++.h>
using namespace std;

int n,m,rect_num,area_cnt=0,area_size=0,arr[100][100]={0,},visitied[100][100]={0,};
int leftx,lefty,rightx,righty;
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
vector<int> num_arr;

void dfs(int sy,int sx){
    visitied[sy][sx]=1;
    area_size++;
    for (int i=0;i<4;i++){
        int x=sx+dx[i];
        int y=sy+dy[i];
        if (x>=0&&x<m&&y>=0&&y<n){
            if ((!arr[y][x])&&(!visitied[y][x])){
                dfs(y,x);
            }
        }
    }
}

int main(){
    cin >> n >> m >> rect_num;
    for (int i=0;i<rect_num;i++){
        cin >> leftx >> lefty >> rightx >> righty;
        for (int j=leftx;j<rightx;j++){
            for (int k=lefty;k<righty;k++){
                arr[n-k-1][j]=1;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!visitied[i][j]&&!arr[i][j]){
                dfs(i,j);
                area_cnt++;
                num_arr.push_back(area_size);
                area_size=0;
            }
        }
    }
    cout << area_cnt << "\n";
    sort(num_arr.begin(),num_arr.end());
    for (auto&k:num_arr){
        cout << k << " ";
    }
}