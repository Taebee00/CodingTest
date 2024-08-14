#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=0;i<TC;i++){
        int N, M, mx=-1;
        vector<int> v;
        cin >> N >> M;
        for (int j=0;j<N;j++){
            int weight;
            cin >> weight;
            v.push_back(weight);
        }
        for (int j=0;j<v.size()-1;j++){
            for (int k=j+1;k<v.size();k++){
                int sum=v[j]+v[k];
                if (sum<=M){
                    mx=max(sum,mx);
                }
            }
        }
        printf("#%d %d\n",i+1,mx);
    }
}