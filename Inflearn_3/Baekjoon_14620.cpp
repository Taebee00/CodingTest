// #include <bits/stdc++.h>
// using namespace std;

// int N,mn=INT_MAX,mp[10][10],dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
// vector<int> v;

// int cal(int a, int b, int c){
//     int sum=0;
//     int visitied[10][10]={0,};
//     for (int i:{a,b,c}){
//         int y=i/10; int x=i%10;
//         visitied[y][x]=1;
//         sum+=mp[y][x];
//         for (int j=0;j<4;j++){
//             int ny=y+dy[j]; int nx=x+dx[j];
//             if (!(ny>=0&&ny<N&&nx>=0&&nx<N)||visitied[ny][nx]){
//                 return INT_MAX;
//             }
//             else{
//                 visitied[ny][nx]=1;
//                 sum+=mp[ny][nx];
//             }
//         }
//     }
//     return sum;
// }

// int main(){
//     cin >> N;
//     for (int i=0;i<N;i++){
//         for (int j=0;j<N;j++){
//             cin >> mp[i][j];
//             v.push_back(10*i+j);
//         }
//     }
//     for (int i=0;i<v.size()-2;i++){
//         for (int j=i+1;j<v.size()-1;j++){
//             for (int k=j+1;k<v.size();k++){
//                 mn=min(mn,cal(v[i],v[j],v[k]));
//             }
//         }
//     }
//     cout << mn;
// }
#include <bits/stdc++.h>

using namespace std;

int N, arr[10][10], visitied[10][10]={0,}, mn=INT_MAX;
vector<pair<int,int>> v, choose_v;
int dy[5]={0,-1,0,1,0}, dx[5]={0,0,1,0,-1};

int cal()
{
    int sum=0;
    fill(&visitied[0][0],&visitied[0][0]+10*10,0);
    for (auto i:choose_v){
        for (int j=0;j<5;j++){
            int ny=i.first+dy[j];
            int nx=i.second+dx[j];
            if (visitied[ny][nx]) return INT_MAX;
            sum+=arr[ny][nx];
            visitied[ny][nx]=1;
        }
    }
    return sum;
}

void choose(int n,int c,int depth){
    if (choose_v.size()==c){
        mn=min(cal(),mn);
        return;
    }
    for (int i=depth+1;i<n;i++){
        choose_v.push_back(v[i]);
        choose(n,c,i);
        choose_v.pop_back();
    }
}

int main()
{
    cin >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
            if (i>0&&j>0&&i<N-1&&j<N-1) v.push_back({i,j});
        }
    }
    choose(v.size(),3,-1);
    cout << mn;
}