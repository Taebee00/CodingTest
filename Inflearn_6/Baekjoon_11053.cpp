#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,ret=1;
    cin >> N;
    vector<int> v;
    int cnt[1001];
    fill(cnt,cnt+1001,1);
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    for (int i=1;i<N;i++){
        int mx=1;
        for (int j=0;j<i;j++){
            if (v[j]<v[i]&&cnt[j]>=mx){
                mx=cnt[j];
                cnt[i]=mx+1;
            }
        }
        ret=max(cnt[i],ret);
    }
    cout << ret;
}

