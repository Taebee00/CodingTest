#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, ret=1;;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i=0;i<N;i++){
        pair<int,int> temp;
        cin >> temp.first >> temp.second;
        v.push_back({temp.first,temp.second});
    }
    sort(v.begin(),v.end());
    int cnt[100];
    for (int i=0;i<N;i++){
        cnt[i]=1;
    }
    for (int i=1;i<v.size();i++){
        int mx=0;
        for (int j=0;j<i;j++){
            if (v[j].second<v[i].second&&cnt[j]>mx){
                cnt[i]=cnt[j]+1;
                mx=cnt[j];
                ret=max(mx+1,ret);
            }
        }
    }
    for (int i=0;i<v.size();i++){
        cout << cnt[i] << " ";
    }
    cout << N-ret;
}