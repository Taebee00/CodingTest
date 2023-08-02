#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K, arr[100], visitied[101], cnt=0;
    vector<int> multitap;
    cin >> N >> K;
    for (int i=0;i<K;i++){
        cin >> arr[i];
    }
    int idx, sz=0;
    while(idx<K){
        if (sz<N){
            if (!visitied[arr[idx]]){
                multitap.push_back(arr[idx]);
                visitied[arr[idx]]=1;
                sz++;
            }
        }
        else if (!visitied[idx]){
            int mxidx=idx;
            int mx=-1;
            for (int i=0;i<N;i++){
                for (int j=idx+1;j<K;j++){
                    if (arr[j]==multitap[i]){
                        if (j>mxidx){
                           mxidx=j;
                           mx=i;
                        }
                        break;
                    }
                    if (j==K-1){
                        
                    }
                }
            }
            if (mx!=-1)
            {
                multitap.erase(multitap.begin()+mx);
                visitied[multitap[mx]]=0;
                multitap.insert(multitap.begin()+mx,arr[idx]);
                cnt++;
            }
            else{
                multitap.erase(multitap.begin()+mx);
                visitied[multitap[mx]]=0;
                multitap.insert(multitap.begin()+mx,arr[idx]);
                cnt++;
            }
        }
        idx++;
    }
    cout << cnt;

}