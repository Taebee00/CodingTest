#include <bits/stdc++.h>

using namespace std;

int N, M, C, arr[52][52]={0,};
// y좌표, x좌표, 방문횟수, 방문노드
int dp[52][52][52][52]={0,};
map<pair<int,int>,int> mp;

int main()
{
    cin >> N >> M >> C;

    for (int i=0;i<C;i++){
        int y, x;
        cin >> y >> x;
        mp[{y,x}]=i+1;
        arr[y][x]=1;
    }
    
    if (arr[1][1]==1) dp[1][1][1][1]=1;
    else dp[1][1][0][0]=1;

    for (int i=0;i<=mp.size();i++){ //지금까지 몇개 방문했는지
        for (int y=1;y<=N;y++){
            for (int x=1;x<=M;x++){
                // 현재 y,x 좌표에 오락실이 있고
                // 방문한 최근 오락실보다 높은 숫자일 떄
                if (mp.count({y,x})){
                    if (y-1>=1){
                        for (int k=0;k<mp[{y,x}];k++){
                            dp[y][x][i+1][mp[{y,x}]]+=dp[y-1][x][i][k];
                        }
                    }
                    if (x-1>=1){
                        for (int k=0;k<mp[{y,x}];k++){
                            dp[y][x][i+1][mp[{y,x}]]+=dp[y][x-1][i][k];
                        }
                    }
                }
                // 현재 y,x 좌표에 오락실이 없을 때
                else{
                    if (y-1>=1){
                        for (int k=0;k<=mp.size();k++){
                            dp[y][x][i][k]+=dp[y-1][x][i][k];
                        }
                    }
                    if (x-1>=1){
                        for (int k=0;k<=mp.size();k++){
                            dp[y][x][i][k]+=dp[y][x-1][i][k];
                        }
                    }
                }
            }
        }
    }
    for (int i=0;i<=mp.size();i++){
        long long sum=0;
        for (int j=0;j<=mp.size();j++){
            sum+=dp[N][M][i][j]%1000007;
        }
        cout << sum << " ";
    }

}