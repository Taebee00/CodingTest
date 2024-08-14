#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;

    cin >> tc;

    for (int i=0;i<tc;i++){
        int N, M, A[21], B[21], temp[21], mx=INT_MIN;
        cin >> N >> M;
        for (int j=0;j<N;j++){
            cin >> A[j];
        }
        for (int j=0;j<M;j++){
            cin >> B[j];
        }
        if (N > M){
            memcpy(temp,B,sizeof(int)*21);
            memcpy(B,A,sizeof(int)*21);
            memcpy(A,temp,sizeof(int)*21);
        }
        for (int j=0;j<=abs(M-N);j++){
            int sum=0;
            for (int k=0;k<min(M,N);k++){
                sum+=B[j+k]*A[k];
            }
            mx=max(sum,mx);
        }
        printf("#%d %d\n",i+1,mx);
    }
}