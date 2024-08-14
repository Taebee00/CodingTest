#include <bits/stdc++.h>

using namespace std;

int R, C, T, answer=0, arr[50][50], temp_arr[50][50];
pair<int,int> cleaner;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};


void rotate(int y,int x){
    int ny=y; int nx=x;
    while(ny-1>=0){
        temp_arr[ny][nx]=temp_arr[ny-1][nx];
        ny--;
    }
    while(nx+1<C){
        temp_arr[ny][nx]=temp_arr[ny][nx+1];
        nx++;
    }
    while(ny+1<=y){
        temp_arr[ny][nx]=temp_arr[ny+1][nx];
        ny++;
    }
    while(nx-1>=0){
        temp_arr[ny][nx]=temp_arr[ny][nx-1];
        nx--;
    }
    temp_arr[y][x]=-1;
    temp_arr[y][x+1]=0;
}

void r_rotate(int y,int x){
    int ny=y; int nx=x;
    while(ny+1<R){
        temp_arr[ny][nx]=temp_arr[ny+1][nx];
        ny++;
    }
    while(nx+1<C){
        temp_arr[ny][nx]=temp_arr[ny][nx+1];
        nx++;
    }
    while(ny-1>=y){
        temp_arr[ny][nx]=temp_arr[ny-1][nx];
        ny--;
    }
    while(nx-1>=0){
        temp_arr[ny][nx]=temp_arr[ny][nx-1];
        nx--;
    }
    temp_arr[y][x]=-1;
    temp_arr[y][x+1]=0;
}

int main()
{
    cin >> R >> C >> T;

    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> arr[i][j];
            if (arr[i][j]==-1) cleaner={i,j};
        }
    }

    while(T--){
        // 먼지 확산
        vector<pair<int,int>> temp_v;
        memcpy(temp_arr,arr,sizeof(arr));
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                if (arr[i][j]>0){
                    int cnt=0;
                    for (int k=0;k<4;k++){
                        int ny=i+dy[k]; int nx=j+dx[k];
                        if (ny<0||nx<0||ny>=R||nx>=C) continue;
                        if (arr[ny][nx]==-1) continue;
                        temp_arr[ny][nx]+=arr[i][j]/5;
                        cnt++;
                    }
                    temp_arr[i][j]-=(cnt*(arr[i][j]/5));
                }
            }
        }
        //먼지 흡입
        rotate(cleaner.first-1,cleaner.second);
        r_rotate(cleaner.first,cleaner.second);
        memcpy(arr,temp_arr,sizeof(arr));
    }
    
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            if (temp_arr[i][j]>0) answer+=arr[i][j];
        }
    }
    cout << answer;
}