#include <bits/stdc++.h>

using namespace std;

int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};

int main()
{
    int tc;

    cin >> tc;

    for (int i=0;i<tc;i++){
        int N, M, arr[20][20], mx=0;
        cin >> N >> M;
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                cin >> arr[j][k];
            }
        }
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                int A_sum=arr[j][k];
                for (int l=0;l<8;l+=2){
                    for (int m=1;m<M;m++){
                        int y=j+m*dy[l];
                        int x=k+m*dx[l];
                        if (y<0||x<0||y>=N||x>=N) continue;
                        A_sum+=arr[y][x];
                    }
                }
                int B_sum=arr[j][k];
                for (int l=1;l<8;l+=2){
                    for (int m=1;m<M;m++){
                        int y=j+m*dy[l];
                        int x=k+m*dx[l];
                        if (y<0||x<0||y>=N||x>=N) continue;
                        B_sum+=arr[y][x];
                    }
                }
                int sum=max(A_sum,B_sum);
                mx=max(mx,sum);
            }
        }
        printf("#%d %d\n",i+1,mx);
    }
}