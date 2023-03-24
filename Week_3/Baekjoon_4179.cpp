#include <bits/stdc++.h>
using namespace std;

int h,w,ret,f_visitied[1005][1005]={0,},j_visitied[1005][1005]={0,};
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
pair<int,int> jihoon;
vector<pair<int,int>> fire;
char mp[1005][1005];
queue<pair<int,int>> j_queue, f_queue;

void bfs(){
    for (auto&i:fire){
        f_queue.push({i.first,i.second});
        f_visitied[i.first][i.second]=1;
    }

    while(f_queue.size()){
    
        pair<int,int> f_loc=f_queue.front();

        for (int j=0;j<4;j++){
            int fx=f_loc.second+dx[j]; int fy=f_loc.first+dy[j];

            if (fx>=0&&fx<w&&fy>=0&&fy<h&&!f_visitied[fy][fx]&&mp[fy][fx]!='#'){
                f_queue.push({fy,fx});
                f_visitied[fy][fx]=f_visitied[f_loc.first][f_loc.second]+1;
                mp[fy][fx]='F';
            }
        }
        f_queue.pop();       
    }

    j_queue.push({jihoon.first,jihoon.second});
    j_visitied[jihoon.first][jihoon.second]=1;

    while(j_queue.size()){
        
        pair<int,int> j_loc=j_queue.front();

        if (j_loc.first==0||j_loc.first==h-1||j_loc.second==0||j_loc.second==w-1){
            cout << j_visitied[j_loc.first][j_loc.second];
            return;
        }
        for (int i=0;i<4;i++){
            int jx=j_loc.second+dx[i]; int jy=j_loc.first+dy[i];

            if (jx>=0&&jx<w&&jy>=0&&jy<h&&!j_visitied[jy][jx]&&mp[jy][jx]!='#'){
                if (mp[jy][jx]=='F'){
                    if (j_visitied[j_loc.first][j_loc.second]+1<f_visitied[jy][jx]){
                        j_queue.push({jy,jx});
                        j_visitied[jy][jx]=j_visitied[j_loc.first][j_loc.second]+1;
                    }
                }
                else{
                    j_queue.push({jy,jx});
                    j_visitied[jy][jx]=j_visitied[j_loc.first][j_loc.second]+1;
                }
            }
        }
        j_queue.pop();
    }
    cout << "IMPOSSIBLE";
}

int main(){
    cin >> h >> w;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> mp[i][j];
            if (mp[i][j]=='J'){
                jihoon={i,j};
            }
            else if (mp[i][j]=='F'){
                fire.push_back({i,j});
            }
        }
    }
    bfs();
}