#include <bits/stdc++.h>

using namespace std;

int N, arr[101][101]={0,}, answer=0;
int dy[4]={0,-1,0,1}, dx[4]={1,0,-1,0};

void dragon_curve(vector<pair<int,int>> &v, int gen, pair<int,int> center){
    if (gen==0) return;
    vector<pair<int,int>> temp_v;
    pair<int,int> next_center;
    for (int i=0;i<v.size();i++){
        int y=v[i].first-center.first;
        int x=v[i].second-center.second;
        int ny=center.first+x;
        int nx=center.second-y;
        if (ny<0||nx<0||ny>100||nx>100) continue;
        if (i==0) next_center={ny,nx};
        temp_v.push_back({ny,nx});
    }
    for (auto i:temp_v) v.push_back(i);
    dragon_curve(v,gen-1,next_center);
}

int main()
{
    cin >> N;

    for (int i=0;i<N;i++){
        vector<pair<int,int>> v;
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        v.push_back({y,x});
        v.push_back({y+dy[d],x+dx[d]});
        dragon_curve(v,g,v[1]);
        for (auto j:v){
            arr[j.first][j.second]=1;
        }
    }
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            if (arr[i][j]&&arr[i+1][j]&&arr[i][j+1]&&arr[i+1][j+1]) answer++;
        }
    }
    cout << answer;
}
