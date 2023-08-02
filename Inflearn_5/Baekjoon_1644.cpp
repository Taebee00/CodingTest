#include <bits/stdc++.h>

using namespace std;

int sosu[4000001]={0,};
int sosuarr[4000000];
int sumarr[4000000];

int main()
{
    int N;
    cin >> N;
    for (int i=2;i<=N;i++){
        int idx=2;
        while(idx*i<=N&&!sosu[i]){
            sosu[idx*i]=1;
            idx++;
        }
    }
    int idx=1;
    sumarr[0]=0;
    for (int i=2;i<=N;i++){
        if (!sosu[i]){
            sosuarr[idx]=i;
            sumarr[idx]=sumarr[idx-1]+i;
            idx++;
        }
    }
    // for (int i=0;i<idx;i++){
    //     cout << sumarr[i] << " ";
    // }
    int cnt=0;
    int front=0;
    int rear=0;
    while(rear<=idx){
        rear++;
        while (sumarr[rear]-sumarr[front]>N){
            front++;
        }
        if (sumarr[rear]-sumarr[front]==N){
            cnt++;
            //printf("%d %d\n",sosuarr[front],sosuarr[rear]);
        }
    }
    cout << cnt;
}