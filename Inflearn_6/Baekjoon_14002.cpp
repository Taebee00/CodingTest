#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,ret=1,lastidx=0;
    cin >> N;
    vector<int> v;
    int cnt[1001];
    int way[1001];
    fill(cnt,cnt+1001,1);
    fill(way,way+1001,-1);
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
                way[i]=j;
            }
        }
        if (ret<cnt[i]){
            ret=cnt[i];
            lastidx=i;
        }
    }
    printf("%d\n",ret);
    int idx=lastidx;
    vector<int> ret_v;
    while(idx!=-1){
        ret_v.push_back(v[idx]);
        idx=way[idx];
    }
    for (int i=ret-1;i>=0;i--){
        printf("%d ",ret_v[i]);
    }
}

