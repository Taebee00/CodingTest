#include <bits/stdc++.h>
using namespace std;

int hor_cnt=0, ver_cnt=0;
int visitied[100][100]={0,};

int main()
{
    int N, L, mp[100][100];
    cin >> N >> L;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j];
        }
    }

    for (int i=0;i<N;i++){
        int cnt=1,flag=0;
        for (int j=0;j<N-1;j++){
            if (mp[i][j]==mp[i][j+1]){
                continue;
            }
            else if (mp[i][j]+1==mp[i][j+1]){
                int cnt=0;
                int k=j;
                while (mp[i][k]==mp[i][j]&&k>=0&&!visitied[i][k]){
                    cnt++;
                    k--;
                    if (cnt==L){
                        for (int l=j;l>j-cnt;l--){
                            visitied[i][l]=1;
                        }
                        break;
                    }
                }
                if (cnt<L){
                    flag=1;
                    break;
                }               
            }
            else if (mp[i][j]==mp[i][j+1]+1){
                int cnt=0;
                int k=j+1;
                while (mp[i][k]==mp[i][j+1]&&k<N&&!visitied[i][k]){
                    cnt++;
                    k++;
                    if (cnt==L){
                        for (int l=j+1;l<j+1+cnt;l++){
                            visitied[i][l]=1;
                        }
                        break;
                    }
                }
                if (cnt<L){
                    flag=1;
                    break;
                }        
            }
            else{
                flag=1;
                break;
            }
        }
        if (!flag){
            hor_cnt++;
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            visitied[i][j]=0;
        }
    }

    for (int i=0;i<N;i++){
        int cnt=1,flag=0;
        for (int j=0;j<N-1;j++){
            if (mp[j][i]==mp[j+1][i]){
                continue;
            }
            else if (mp[j][i]+1==mp[j+1][i]){
                int cnt=0;
                int k=j;
                while (mp[k][i]==mp[j][i]&&k>=0&&!visitied[k][i]){
                    cnt++;
                    k--;
                    if (cnt==L){                       
                        for (int l=j;l>j-cnt;l--){
                            visitied[l][i]=1;
                        }
                        break;
                    }
                }
                if (cnt<L){
                    flag=1;
                    break;
                }                              
            }
            else if (mp[j][i]==mp[j+1][i]+1){
                int cnt=0;
                int k=j+1;
                while (mp[k][i]==mp[j+1][i]&&k<N&&!visitied[k][i]){
                    cnt++;
                    k++;
                    if (cnt==L){
                        for (int l=j+1;l<j+1+cnt;l++){
                            visitied[l][i]=1;
                        }
                        break;
                    }
                }
                if (cnt<L){
                    flag=1;
                    break;
                }        
            }
            else{
                flag=1;
                break;
            }
        }
        if (!flag){
            ver_cnt++;
        }
    }
    cout << ver_cnt+hor_cnt;
}
