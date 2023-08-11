#include <bits/stdc++.h>

using namespace std;

int N, M, T, mp[54][54], tc[54][3], ret;

int rot(int num, int dir, int k)
{
    for (int i=0;i<N;i++){
        if ((i+1)%num==0){
            if (!dir){
                rotate(mp[i],mp[i]+M-k,mp[i]+M);
            }
            else{
                rotate(mp[i],mp[i]+k,mp[i]+M);
            }
        }
    }
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++){
        for (int j=0;j<M-1;j++){
            if (mp[i][j]==mp[i][j+1]&&mp[i][j]){               
                v.push_back({i,j});
                v.push_back({i,j+1});
            }
        }
        if (mp[i][M-1]==mp[i][0]&&mp[i][M-1]){
            v.push_back({i,0});
            v.push_back({i,M-1});
        }
    }
    for (int i=0;i<M;i++){
        for (int j=0;j<N-1;j++){
            if (mp[j][i]==mp[j+1][i]&&mp[j][i]){
                v.push_back({j,i});
                v.push_back({j+1,i});
            }
        }
    }
    if (v.size()){
        for (auto&i:v){
            //cout << i.first << " " << i.second << "\n";
            if (mp[i.first][i.second]){
                mp[i.first][i.second]=0;
            }
        }
    }
    // for (int j=0;j<N;j++){
    //     for (int k=0;k<M;k++){
    //         cout << mp[j][k] << " ";
    //     }
    //     cout << "\n";
    // }
    int sum=0,cnt=0,ret=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){  
            if (mp[i][j]){
                cnt++;
                sum+=mp[i][j];
            }
        }
    }
    double avr=double(sum)/double(cnt);
    if (!v.size()){
        sum=0;
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (mp[i][j]){
                    if (double(mp[i][j])>(avr)){
                        mp[i][j]-=1;
                    }
                    else if (double(mp[i][j])<(avr)){
                        mp[i][j]+=1;
                    }
                    sum+=mp[i][j];
                }
            }
        } 
    }
    return sum;
}

int main()
{
    cin >> N >> M >> T;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> mp[i][j];
        }
    }
    for (int i=0;i<T;i++){
        for (int j=0;j<3;j++){
            cin >> tc[i][j];
        }
    }

    for (int i=0;i<T;i++){
        ret=rot(tc[i][0],tc[i][1],tc[i][2]);
    }
    cout << ret;
}