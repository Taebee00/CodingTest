#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=1;i<=TC;i++){
        int N, K;
        vector<int> v;
        vector<pair<int,int>> pair_v;
        cin >> N >> K;
        for (int j=0;j<N;j++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        for (int j:v){
            for (int k:v){
                pair_v.push_back({j,k});
            }
        }
        sort(pair_v.begin(),pair_v.end());
        printf("#%d %d\n",i,pair_v[K-1].first+pair_v[K-1].second);
    }
}