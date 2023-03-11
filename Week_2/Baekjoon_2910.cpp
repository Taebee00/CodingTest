#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long,pair<int,int>> &a,pair<long long,pair<int,int>> &b){
    if (a.second.first==b.second.first){
        return a.second.second < b.second.second;
    }
    return a.second.first > b.second.first;
}

long long num, mx;
map<long long,pair<int,int>> arr;

int main(){
    int order=0;
    cin >> num >> mx;
    long long input;
    for (int i=0;i<num;i++){
        cin >> input;
        arr[input].first++;
        if (arr[input].first==1){
            arr[input].second=order++;
        }
    }
    vector<pair<long long,pair<int,int>>> v(arr.begin(),arr.end());
    sort(v.begin(),v.end(),cmp);
    for (auto&i:v){
        for (int j=0;j<i.second.first;j++){
            cout << i.first << " ";
        }
    }
}