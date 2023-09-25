#include <bits/stdc++.h>

using namespace std;

int mp[10][10], visitied[10][10]={0,}, num,ret=INT_MAX, paper[6]={5,5,5,5,5,5};
int cnt=0;
vector<pair<int,int>> v;

void dfs(int idx){
    if (cnt>=ret){
        return;
    }
    if (idx==v.size()){
        if (cnt<ret){
            ret=cnt;
        }
        return;
    }
    int y=v[idx].first, x=v[idx].second;
    if (visitied[y][x]) dfs(idx+1);
    
    for (int i=5;i>0;i--){
        bool is_possible=true;
        if (paper[i]==0){
            continue;
        }
        for (int j=0;j<i;j++){
            for (int k=0;k<i;k++){
                if (y+j>=10||x+k>=10||mp[y+j][x+k]==0||visitied[y+j][x+k]){
                    is_possible=false;
                    break;
                }
            }
        }
        if (is_possible==true){
            paper[i]--;
            cnt++;
            for (int j=0;j<i;j++){
                for (int k=0;k<i;k++){
                    visitied[y+j][x+k]=1;
                }
            }
            dfs(idx+1);
            paper[i]++;
            cnt--;
            for (int j=0;j<i;j++){
                for (int k=0;k<i;k++){
                    visitied[y+j][x+k]=0;
                }
            }
        }
    }

}

int main(){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cin >> mp[i][j];
            if (mp[i][j]) v.push_back({i,j});
        }
    }
    if (v.size()){
        dfs(0);
        if (ret==INT_MAX) printf("-1");
        else printf("%d",ret);
    }
    else printf("0");
}