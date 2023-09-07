#include <bits/stdc++.h>

using namespace std;

vector<int> mp[14][14];
int N,M,K,A[14][14],nut[14][14];
int dy[8]={-1,-1,-1,0,0,1,1,1}, dx[8]={-1,0,1,-1,1,-1,0,1};

void spring_summer(){
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (mp[i][j].size()){
                sort(mp[i][j].begin(),mp[i][j].end());
                for (int k=0;k<mp[i][j].size();k++){
                    if (nut[i][j]>=mp[i][j][k]){
                        nut[i][j]-=mp[i][j][k];
                        mp[i][j][k]++;
                    }
                    else{
                        for (int l=k;l<mp[i][j].size();l++){
                            nut[i][j]+=mp[i][j][l]/2;
                        }
                        mp[i][j].erase(mp[i][j].begin()+k,mp[i][j].end());
                        break;
                    }
                }
            }
        }
    }
}

void fall_winter(){
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (mp[i][j].size()){
                for (int k=0;k<mp[i][j].size();k++){
                    if (mp[i][j][k]%5==0){
                        for (int l=0;l<8;l++){
                            if (i+dy[l]>=1&&i+dy[l]<=N&&j+dx[l]>=1&&j+dx[l]<=N)
                            mp[i+dy[l]][j+dx[l]].push_back(1);
                        }
                    }
                }
            }
            nut[i][j]+=A[i][j];
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            cin >> A[i][j];
            nut[i][j]=5;
        }
    }
    for (int i=0;i<M;i++){
        int y,x,age;
        cin >> x >> y >> age;
        mp[x][y].push_back(age);
    }
    for (int i=0;i<K;i++){
        spring_summer();
        fall_winter();
    }
    int sum=0;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            sum+=mp[i][j].size();
        }
    }
    cout << sum;
}