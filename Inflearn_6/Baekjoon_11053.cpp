#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, mx=1;
    vector<pair<int,int>> v;
    cin >> N;

    for (int i=0;i<N;i++){
        int num, cnt=1;
        cin >> num;
        for (int j=0;j<i;j++){
            if (v[j].first<num){
                cnt=max(cnt,v[j].second+1);
                mx=max(cnt,mx);
            }
        }
        v.push_back({num,cnt});
    }
    cout << mx;
}