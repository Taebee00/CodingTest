#include <bits/stdc++.h>

using namespace std;

int N, M, arr[8][8], answer=INT_MAX;
vector<pair<int,int>> cctv;
vector<int> dir_v;

int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
vector<int> cctv_dir[6];

int calculate(){
    int temp_arr[8][8];
    memcpy(temp_arr,arr,sizeof(arr));
    for (int i=0;i<cctv.size();i++){
        int y=cctv[i].first;
        int x=cctv[i].second;
        for (int j:cctv_dir[arr[y][x]]){
            int dir=(dir_v[i]+j)%4;
            int ny=y;
            int nx=x;
            while(ny>=0&&nx>=0&&ny<N&&nx<M&&arr[ny][nx]!=6){
                if (arr[ny][nx]==0){
                    temp_arr[ny][nx]=10;
                }
                ny+=dy[dir];
                nx+=dx[dir];
            }
        }
    }
    int cnt=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (temp_arr[i][j]==0) cnt++;
        }
    }
    return cnt;
}

void combination(int cnt,int sz){
    if (cnt==sz){
        answer=min(answer,calculate());
        return;
    }
    for (int i=0;i<4;i++){
        dir_v.push_back(i);
        combination(cnt+1,sz);
        dir_v.pop_back();
    }
}

int main()
{
    cctv_dir[1].push_back(0);
    cctv_dir[2].push_back(0);
    cctv_dir[2].push_back(2);
    cctv_dir[3].push_back(0);
    cctv_dir[3].push_back(1);
    cctv_dir[4].push_back(0);
    cctv_dir[4].push_back(1);
    cctv_dir[4].push_back(2);
    cctv_dir[5].push_back(0);
    cctv_dir[5].push_back(1);
    cctv_dir[5].push_back(2);
    cctv_dir[5].push_back(3);

    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> arr[i][j];
            if (arr[i][j]>=1&&arr[i][j]<=5) cctv.push_back({i,j});
        }
    }
    combination(0,cctv.size());
    cout << answer;
}