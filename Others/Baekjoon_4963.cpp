#include <bits/stdc++.h>

using namespace std;

void dfs(int y,int x,int (*arr)[s])

int main()
{
    int TC;

    cin >> TC;

    for (int tc=0;tc<TC;tc++){
        int w, h, arr[51][51], visitied[51][51]={0,};
        cin >> w >> h;
        for (int i=0;i<h;i++){
            for (int j=0;j<w;j++){
                cin >> arr[i][j];
            }
        }
        for (int i=0;i<h;i++){
            for (int j=0;j<w;j++){
                if (visitied[i][j]!=1) continue;
                dfs(i,j,arr,visitied);
            }
        }
    }
}