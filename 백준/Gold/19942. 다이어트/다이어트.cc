#include <bits/stdc++.h>
using namespace std;

int N, m[4], arr[15][5],price_mx=INT_MAX;
vector<int> v;

int main(){
    cin >> N;
    for (int i=0;i<4;i++){
        cin >> m[i];
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<5;j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<(1<<N);i++){
        int sum[5]={0,};
        for (int j=0;j<N;j++){
            if (i&(1<<j)){
                for (int k=0;k<5;k++){
                    sum[k]+=arr[j][k];
                }
            }
        }
        int cnt=0;
        for (int j=0;j<4;j++){
            if (m[j]<=sum[j]){
                cnt++;
            }
        }
        if (cnt==4&&sum[4]==price_mx){
            vector<int> v2;
            for (int j=0;j<N;j++){
                if (i&(1<<j)){
                    v2.push_back(j+1);
                }
            }
            for (int j=0;j<v.size();j++){
                if (v[j]<v2[j]){
                    break;
                }
                else if (v[j]>v2[j]){
                    v.clear();
                    for (auto&k:v2){
                        v.push_back(k);
                    }
                    break;
                }
            }
        }
        else if (cnt==4&&sum[4]<price_mx){
            v.clear();
            for (int j=0;j<N;j++){
                if (i&(1<<j)){
                    v.push_back(j+1);
                }
            }
            price_mx=sum[4];
        }
    }
    if (v.empty()){
        cout << "-1";
    }
    else{
        cout << price_mx << "\n";
        for (auto&i:v){
            cout << i << " ";
        }
    }
}