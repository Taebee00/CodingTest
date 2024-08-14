// #include <bits/stdc++.h>
// using namespace std;

// int h,w,j_y,j_x,t_y,t_x, visitied[300][300]={0,}; char mp[300][300];
// queue<pair<int,int>> q;
// queue<pair<int,int>> q2;

// int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

// void dfs(int y,int x){
//     for (int i=0;i<4;i++){
//         int _x=x+dx[i]; int _y=y+dy[i];
//         if (_x>=0&&_x<w&&_y>=0&&_y<h&&!visitied[_y][_x]){
//             visitied[_y][_x]=1;
//             q2.push({_y,_x});
//             if (mp[_y][_x]=='0'){  
//                 dfs(_y,_x);
//             }
//             else{
//                 mp[_y][_x]='0';
//             }
//         }
//     } 
// }

// int find(){
//     int cnt=0;
//     q.push({j_y-1,j_x-1});
//     mp[j_y-1][j_x-1]='0';
//     while(1){
//         cnt++;
//         while(!q.empty())
//         {
//             if (q.front().first==t_y-1&&q.front().second==t_x-1){
//                 return cnt-1;
//             }
//             dfs(q.front().first,q.front().second);
//             q.pop();
//         }
//         while(!q2.empty()){
//             q.push({q2.front().first,q2.front().second});
//             q2.pop();
//         }
//     }
// }

// int main(){
//     cin >> h >> w >> j_y >> j_x >> t_y >> t_x;
//     for (int i=0;i<h;i++){
//         for (int j=0;j<w;j++){
//             cin >> mp[i][j];
//         }
//     }
//     cout << find();
// }
#include <bits/stdc++.h>

using namespace std;

int N, M, visitied[300][300]={0,}, jump_cnt[300][300], answer=0, cnt=1;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
int x_1, y_1, x_2, y_2;
char arr[300][300];
pair<int,int> junan;
vector<pair<int,int>> v;

void dfs(int y, int x){
    visitied[y][x]=1;
    for (int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||nx<0||ny>=N||nx>=M) continue;
        if (visitied[ny][nx]) continue;
        if (arr[ny][nx]=='1') v.push_back({ny,nx});
        else if (arr[ny][nx]=='#') answer=cnt;
        else if (arr[ny][nx]=='0') dfs(ny,nx);
    }
}

int main()
{
    cin >> N >> M;
    cin >> x_1 >> y_1 >> x_2 >> y_2;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> arr[i][j];
            if (arr[i][j]=='*') junan={i,j};
        }
    }

    while(answer==0){
        fill(&visitied[0][0],&visitied[0][0]+300*300,0);
        dfs(junan.first,junan.second);
        for (auto i:v) arr[i.first][i.second]='0';
        v.clear();
        cnt++;
    }

    cout << answer;
}