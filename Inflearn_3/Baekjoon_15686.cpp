#include <bits/stdc++.h>

using namespace std;

int N, M, arr[51][51], answer=INT_MAX;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
vector<pair<int,int>> chicken_v;
vector<pair<int,int>> house_v;
vector<pair<int,int>> choose_v;

int cal_distance(){
    int distance_sum=0;
    for (auto i:house_v){
        int temp_dddddsum=INT_MAX;
        for (auto j:choose_v){
            temp_sum=min(temp_sum,abs(i.first-j.first)+abs(i.second-j.second));
        }
        distance_sum+=temp_sum;
    }
    return distance_sum;
}

void choose(int n,int c,int idx){
    if (choose_v.size()==c){
        answer=min(cal_distance(),answer);
    }
    for (int i=idx+1;i<n;i++){
        choose_v.push_back(chicken_v[i]);
        choose(n,c,i);
        choose_v.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
            if (arr[i][j]==1) house_v.push_back({i,j});
            if (arr[i][j]==2) chicken_v.push_back({i,j});
        }
    }
    choose(chicken_v.size(),M,-1);
    cout << answer;
}