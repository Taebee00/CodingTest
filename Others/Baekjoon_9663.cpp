#include <bits/stdc++.h>

using namespace std;

int N, answer=0, arr[20][20], temp[20][20], chess[20][20]={0,};
vector<pair<int,int>> v, chosen_v;
pair<int,int> dydx[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

bool check(){
    int flag=1;
    fill(&chess[0][0],&chess[0][0]+20*20,0);
    memcpy(temp,arr,sizeof(arr));
    for (auto i:chosen_v){
        temp[i.first][i.second]=1;
    }
    for (auto i:chosen_v){
        for (int j=0;j<8;j++){
            int y=i.first; int x=i.second;
            while(1){
                y=y+dydx[j].first;
                x=x+dydx[j].second;
                if (y<0||x<0||y>=N||x>=N) break;
                if (temp[y][x]){
                    flag=0;
                    break;
                }
            }
            if (flag==0) break;
        }
        if (flag==0) break;
    }
    return flag;
}

// void dfs(int idx,int sz){
//     if (sz==N){
//         if (check()) answer++;
//         for (auto i:v) cout << i.first << ", " << i.second << " ";
//         cout << "\n";
//     }
//     for (int i=idx;i<N;i++){
//         for (int j=0;j<N;j++){
//             if (visitied[i][j]) continue;
//             v.push_back({i,j});
//             visitied[i][j]=1;
//             dfs(i,sz+1);
//             v.pop_back();
//             visitied[i][j]=0;
//         }
//     }
// }

void choose(int n, int r, int depth){
    if (chosen_v.size()==r){
        
        if (check()) answer++;
        // for (auto i:chosen_v) cout << i.first << ", " << i.second << " ";
        // cout << "\n";
    }
    for (int i=depth+1;i<n;i++){
        chosen_v.push_back(v[i]);
        choose(n,r,i);
        chosen_v.pop_back();
    }
}

int main()
{
    cin >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            v.push_back({i,j});
        }
    }

    choose(v.size(),N,-1);

    cout << answer;
}
