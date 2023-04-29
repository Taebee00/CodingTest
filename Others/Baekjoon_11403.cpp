#include <bits/stdc++.h>
using namespace std;

int N, mp[100][100], visitied[100]={0,};

void init(){
    for (int i=0;i<100;i++){
        visitied[i]=0;
    }
}

int dfs(int start,int end, int cnt){
    int ret=0;
    if (cnt&&mp[start][end]){
        return 1;
    }
    for (int i=0;i<N;i++){
        if (mp[start][i]&&!visitied[i]){
            visitied[i]=1;
            ret+=dfs(i,end,1);
        }
    }
    return ret;
}

int main(){
    cout << "\n";
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j];
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (mp[i][j]){
                cout << "1 ";
            }
            else{
                init();
                visitied[i]=1;
                if (dfs(i,j,0)){
                    cout << "1 ";
                }
                else{
                    cout << "0 ";
                }
            }
        }
        cout << "\n";
    }
}