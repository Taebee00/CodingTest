#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;
}

int main()
{
    pair<int,int> cow[100];
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> cow[i].first >> cow[i].second;
    }
    sort(cow,cow+N,cmp);
    int time=cow[0].first;
    for (auto&i:cow){
        if (i.first>time){
            time=i.first;
        }
        time+=i.second;
    }
    cout << time;
}