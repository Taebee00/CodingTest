#include <bits/stdc++.h>

using namespace std;

int N, idx=1, answer=0, arr[4000001]={0,};
int prefix_sum[4000000];

int main()
{
    cin >> N;

    arr[1]=1;
    arr[2]=0;

    for (int i=2;i<=4000000;i++){
        for (int j=2;i*j<=4000000;j++){
            arr[i*j]=1;
        }
    }
    prefix_sum[0]=0;
    for (int i=0;i<=4000000;i++){
        if (!arr[i]){
            prefix_sum[idx]=prefix_sum[idx-1]+i;
            int temp=idx; int temp_sum=0;
            while(prefix_sum[idx]-prefix_sum[temp]<N&&temp>=0){
                temp--;
            }
            if (prefix_sum[idx]-prefix_sum[temp]==N) answer++;
            idx++;
        }
    }
    cout << answer;
}