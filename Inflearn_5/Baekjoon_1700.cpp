#include <bits/stdc++.h>

using namespace std;

int N, K, arr[100], visitied[100]={0,},cnt=0;
map<int,vector<int>> mp;
vector<int> v;

int main()
{
    cin >> N >> K;
    for (int i=0;i<K;i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    for (int i=0;i<K;i++){
        if (v.size()!=N){
            if (!visitied[arr[i]]){
                v.push_back(arr[i]);
                visitied[arr[i]]=1;
            }
        }
        else{
            if (!visitied[arr[i]]){
                int mx=0,mxidx;
                for (int k=0;k<v.size();k++){
                    if (mp[v[k]].size()&&mp[v[k]][0]>mx){
                        mx=mp[v[k]][0];
                        mxidx=k;
                    }
                    else if (!mp[v[k]].size()){
                        mx=INT_MAX;
                        mxidx=k;
                    }
                    
                }
                visitied[v[mxidx]]=0;
                v.erase(v.begin()+mxidx);
                v.push_back(arr[i]);
                visitied[arr[i]]=1;
                cnt++;
            }
        }
        mp[arr[i]].erase(mp[arr[i]].begin());
    }
    cout << cnt;
}
