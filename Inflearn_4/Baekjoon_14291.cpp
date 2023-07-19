#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, sum=0,max;
    char char_mp[4][4];
    int mp[4][4];
    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> char_mp[i][j];
            mp[i][j]=char_mp[i][j]-'0';
            sum+=mp[i][j];
        }
    }
    int vertical_sum=0;
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            vertical_sum+=mp[j][i]*pow(10,N-j-1);
        }
    }
    int horizontal_sum=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            horizontal_sum+=(mp[i][j]*pow(10,M-j-1));
        }
    }
    max=vertical_sum>horizontal_sum?vertical_sum:horizontal_sum;
    cout << max;
}