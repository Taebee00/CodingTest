#include <bits/stdc++.h>

using namespace std;

int N, ret=0; 
char temp_arr[20][20], arr[20][20];

void reverse_arr(int idx){
    for (int i=0;i<N;i++){
        arr[idx][i]=arr[idx][i]=='T'?'H':'T';
    }
}

int main()
{
    cin >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> temp_arr[i][j];
        }
    }

    for (int i=0;i<1<<N;i++){
        memcpy(arr,temp_arr,sizeof(temp_arr));
        int cnt=0;
        for (int j=0;j<N;j++){
            if (i&(1<<j)){
                reverse_arr(j);
            }
        }
        for (int j=0;j<N;j++){
            int t_cnt=0;
            for (int k=0;k<N;k++){
                if (arr[k][j]=='T') t_cnt++;
            }
            cnt+=max(t_cnt,N-t_cnt);
        }
        ret=max(cnt,ret);
    }
    cout << N*N-ret;
}