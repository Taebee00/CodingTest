#include <bits/stdc++.h>

using namespace std;

int N, M, arr[1000001]={0,}, psum[1000001]={0,};
int cnt=0;
int DAT[1000]={0,};

int main()
{
    cin >> N >> M;
    DAT[0]=1;
    for (int i=1;i<=N;i++){
        cin >> arr[i];
        psum[i]=arr[i]+psum[i-1];
        psum[i]%=M;
        cnt+=DAT[psum[i]];
        DAT[psum[i]]++;
    }
    cout << cnt;
}