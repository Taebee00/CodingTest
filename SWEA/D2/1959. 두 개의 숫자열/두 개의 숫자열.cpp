#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=1;i<=TC;i++){
        int N, M, N_arr[20], M_arr[20], answer=INT_MIN;
        cin >> N >> M;
        for (int j=0;j<N;j++) cin >> N_arr[j];
        for (int j=0;j<M;j++) cin >> M_arr[j];
        if (N>M){
            swap(N,M);
            int temp_arr[20];
            memcpy(temp_arr,N_arr,sizeof(int)*20);
            memcpy(N_arr,M_arr,sizeof(int)*20);
            memcpy(M_arr,temp_arr,sizeof(int)*20);
        }
        for (int j=0;j<=M-N;j++){
            int sum=0;
            for (int k=0;k<N;k++){
                sum+=N_arr[k]*M_arr[j+k];
            }
            answer=max(answer,sum);
        }
        printf("#%d %d\n",i,answer);
    }
}