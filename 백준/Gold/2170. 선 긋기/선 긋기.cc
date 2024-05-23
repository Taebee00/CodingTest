#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i=0;i<N;i++){
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end());
    int sum=0;
    int start=v[0].first;
    int end=v[0].second;
    for (int i=1;i<v.size();i++){
        if (v[i].second<=end) continue;
        if (v[i].first>end){
            sum+=(end-start);
            start=v[i].first;
            end=v[i].second;
        }    
        else if (v[i].first<=end){
            end=v[i].second;
        }
    }
    sum+=(end-start);
    cout << sum;
}