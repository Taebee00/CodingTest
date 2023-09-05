#include <bits/stdc++.h>

using namespace std;

int N,M, mp[1025][1025],sum_mp[1025][1025];
int tc[100000][4];

int main()
{
    cin >> N >> M;

    for (int i=1;i<=N;i++){
        int sum=0;
        for (int j=1;j<=N;j++){
            cin >> mp[i][j];
            sum+=mp[i][j];
            sum_mp[i][j]=sum;
        }
    }
    for (int i=0;i<M;i++){
        for (int j=0;j<4;j++){
            cin >> tc[i][j];
        }
    }

    

    for (int i=0;i<M;i++){
        int sum=0;
        for (int j=tc[i][0];j<=tc[i][2];j++){
            sum+=sum_mp[j][tc[i][3]]-sum_mp[j][tc[i][1]-1];
            //printf("%d %d %d\n",j,tc[i][2],tc[i][0]);
        }
        printf("%d\n",sum);
    }
}