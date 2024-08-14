#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=0;i<TC;i++){
        int N, M, K, arr[20000], tm_arr[20000]={0,}, mx_tm=0, cnt=0, tm_idx=0, flag=1;
        cin >> N >> M >> K;
        for (int j=0;j<N;j++){
            int tm;
            cin >> tm;
            tm_arr[tm]++;
            mx_tm=max(tm,mx_tm);
        }
        for (int j=0;j<=mx_tm;j++){
            if (j>0&&j%M==0){
                cnt+=K;
            }
            if (tm_arr[j]){
                cnt-=tm_arr[j];
                if (cnt<0){
                    flag=0;
                    break;
                }
            }
        }
        if (flag) printf("#%d Possible\n",i+1);
        else printf("#%d Impossible\n",i+1);
    }
}