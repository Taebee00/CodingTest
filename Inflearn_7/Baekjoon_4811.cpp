#include <bits/stdc++.h>

using namespace std;

int N,h_size,w_size;
unsigned long long dp[31][31];

long long find(int h_size,int w_size){
    long long cnt=0;
    if (h_size+w_size==2*N){
        dp[h_size][w_size]=1;
        return 1;
    }
    if (dp[h_size][w_size]){
        return dp[h_size][w_size];
    }
    if (h_size<N){
        cnt+=find(h_size+1,w_size);
    }
    if (w_size<h_size){
        cnt+=find(h_size,w_size+1);
    }
    dp[h_size][w_size]=cnt;
    return cnt;
}

int main()
{
    while(1){
        for (int i=0;i<30;i++){
            for (int j=0;j<30;j++){
                dp[i][j]=0;
            }
        }
        cin >> N;
        if (N==0) break;
        h_size=1; w_size=0;
        cout << find(1,0) << "\n";
    }
}