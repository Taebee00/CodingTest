#include <bits/stdc++.h>

using namespace std;

int N, C;
map<int,pair<int,int>> mp;
struct st{
    int num;
    int freq;
    int idx;
};
vector<struct st> v; 

bool cmp(struct st &a, struct st &b){
    if (a.freq==b.freq){
        return a.idx<b.idx;
    }
    return a.freq>b.freq;
}

int main()
{
    cin >> N >> C;

    for (int i=0;i<N;i++){
        int num;
        cin >> num;
        if (mp.find(num)==mp.end()){
            mp[num].second=i;
        }
        mp[num].first++;
    }

    for (auto i:mp){
        struct st temp;
        temp.num=i.first;
        temp.freq=i.second.first;
        temp.idx=i.second.second;
        v.push_back(temp);
    }

    sort(v.begin(),v.end(),cmp);

    for (auto i:v){
        for (int j=0;j<i.freq;j++){
            cout << i.num << " ";
        }
    }
}