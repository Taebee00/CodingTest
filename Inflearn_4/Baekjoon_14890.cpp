#include <bits/stdc++.h>
using namespace std;

int N, L, ret=0, mp[100][100];

int main(){
    cin >> N >> L;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j];
        }
    }
    for (int i=0;i<N;i++){
        int flag,cnt=0;
        for (int j=1;j<N;j++){
            if (mp[i][j-1]+1==mp[i][j]){
                int cnt=0,temp=mp[i][j];
                while(cnt!=N){
                    if (mp[i][j]!=temp||j>=N){
                        flag=1;
                        break;
                    }
                    j++;
                    cnt++;
                }
                if (flag){
                    // 불가능
                }
            }
            else if (mp[i][j-1]-1==mp[i][j]){
                flag=2;
                cnt++;
            }
            else if (mp[i][j-1]==mp[i][j]){
                flag=3;
            }
            else{

            }
        }
    }
}
