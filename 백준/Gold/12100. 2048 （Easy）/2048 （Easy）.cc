#include <bits/stdc++.h>

using namespace std;

int N, arr[20][20], visitied[20][20]={0,}, mx=INT_MIN;

void go(int dir){
    fill(&visitied[0][0],&visitied[0][0]+20*20,0);
    if (dir==0){
        for (int i=1;i<N;i++){
            for (int j=0;j<N;j++){
                if (!arr[i][j]) continue;
                int val=arr[i][j];
                int idx=i;
                while(idx-1>=0&&arr[idx-1][j]==0){
                    idx--;
                }
                if (idx-1>=0&&arr[idx-1][j]==val&&!visitied[idx-1][j]){
                    arr[i][j]=0;
                    arr[idx-1][j]=val*2;
                    visitied[idx-1][j]=1;
                }
                else{
                    arr[i][j]=0;
                    arr[idx][j]=val;
                }
            }
        }
    }
    if (dir==1){
        for (int i=N-2;i>=0;i--){
            for (int j=0;j<N;j++){
                if (!arr[j][i]) continue;
                int val=arr[j][i];
                int idx=i;
                while(idx+1<N&&arr[j][idx+1]==0){
                    idx++;
                }
                if (idx+1<N&&arr[j][idx+1]==val&&!visitied[j][idx+1]){
                    arr[j][i]=0;
                    arr[j][idx+1]=val*2;
                    visitied[j][idx+1]=1;
                }
                else{
                    arr[j][i]=0;
                    arr[j][idx]=val;
                }
            }
        }
    }
    if (dir==2){
        for (int i=N-2;i>=0;i--){
            for (int j=0;j<N;j++){
                if (!arr[i][j]) continue;
                int val=arr[i][j];
                int idx=i;
                while(idx+1<N&&arr[idx+1][j]==0){
                    idx++;
                }
                if (idx+1<=N&&arr[idx+1][j]==val&&!visitied[idx+1][j]){
                    arr[i][j]=0;
                    arr[idx+1][j]=val*2;
                    visitied[idx+1][j]=1;
                }
                else{
                    arr[i][j]=0;
                    arr[idx][j]=val;
                }
            }
        }
    }
    if (dir==3){
        for (int i=1;i<N;i++){
            for (int j=0;j<N;j++){
                if (!arr[j][i]) continue;
                int val=arr[j][i];
                int idx=i;
                while(idx-1>=0&&arr[j][idx-1]==0){
                    idx--;
                }
                if (idx-1>=0&&arr[j][idx-1]==val&&!visitied[j][idx-1]){
                    arr[j][idx-1]=val*2;
                    arr[j][i]=0;
                    visitied[j][idx-1]=1;
                }
                else{
                    arr[j][i]=0;
                    arr[j][idx]=val;
                }
            }
        }
    }
}

void dfs(int cnt){
    if (cnt==5){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                mx=max(mx,arr[i][j]);
            }
        }
        return;
    }
    int temp_arr[20][20];
    memcpy(temp_arr,arr,sizeof(arr));
    for (int i=0;i<4;i++){
        go(i);
        dfs(cnt+1);
        memcpy(arr,temp_arr,sizeof(temp_arr));
    }
}

int main()
{
    
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    dfs(0);
    cout << mx;

    //go(1);
    // for (int i=0;i<N;i++){
    //     for (int j=0;j<N;j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}