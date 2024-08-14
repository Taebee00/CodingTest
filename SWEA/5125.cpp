#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=0;i<TC;i++){
        int N, L, mx=0;
        vector<pair<int,int>> v;
        cin >> N >> L;
        for (int j=0;j<N;j++){
            int T, K;
            cin >> T >> K;
            v.push_back({T,K});
        }
        for (int j=0;j<(1<<N);j++){
            pair<int,int> sum={0,0};
            for (int k=0;k<N;k++){
                if (j&(1<<k)){
                    sum.first+=v[k].first;
                    sum.second+=v[k].second;
                }
            }
            if (sum.second<=L){
                mx=max(sum.first,mx);
            }
        }
        printf("#%d %d\n",i+1,mx);
    }
}