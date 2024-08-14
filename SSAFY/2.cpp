#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=1;i<=TC;i++){
        int N, people_arr[500], cap_arr[500];
        cin >> N;
        for (int j=0;j<N;j++){
            cin >> people_arr[j];
        }
        for (int j=0;j<N;j++){
            cin >> cap_arr[j];
        }
        sort(people_arr,people_arr+N);
        sort(cap_arr,cap_arr+N);
        int cap_idx=0, cnt=0;
        for (int j=0;j<N;j++){
            if (cap_idx>=N) break;
            if (cap_arr[cap_idx]>=people_arr[j]-3&&cap_arr[cap_idx]<=people_arr[j]+3){
                cap_idx++;
                cnt++;
                continue;
            }
            else if (cap_arr[cap_idx]<people_arr[j]-3){
                cap_idx++;
                j--;
            }
            else if (cap_arr[cap_idx]>people_arr[j]+3){
                continue;
            }
        }
        printf("#%d %d\n",i,cnt);
    }
}