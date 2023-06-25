#include <bits/stdc++.h>
using namespace std;

int N,chicken=0,mn_ret=INT_MAX,c_chicken; int mp[50][50];
int visitied[50][50]={0,};
vector<int> v;
vector<pair<int,int>> vp;

int cal(int y,int x){
    int dist,h,w,mn=INT_MAX;
    for (auto&i:v){
        h=vp[i].first>y?vp[i].first-y:y-vp[i].first;
        w=vp[i].second>x?vp[i].second-x:x-vp[i].second;
        dist=h+w;
        mn=min(dist,mn);
    }
    return mn;
}

int find(){
    int ret=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (mp[i][j]==1){
                ret+=cal(i,j);
            }
        }
    }
    return ret;
}

void Choose(int num,int cnum,int size){
    if (size==cnum){
        for (int i=0;i<cnum;i++){
        }
        mn_ret=min(find(),mn_ret);
        return;
    }
    for (int i=v.size()?v.back()+1:0;i<num;i++){
        v.push_back(i);
        size++;
        Choose(num,cnum,size);
        v.pop_back();
        size--;
    }
}

int main(){
    cin >> N >> c_chicken;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j];
            if (mp[i][j]==2){
                vp.push_back({i,j});
                chicken++;
            }
        }
    }
    Choose(chicken,c_chicken,0);
    cout << mn_ret;
}