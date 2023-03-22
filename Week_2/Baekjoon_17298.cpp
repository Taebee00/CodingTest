#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, sth, cnt=0; vector<pair<int,int>> v; map<int,int> mp;
    cin >> num;
    for (int i=0;i<num;i++){
        cin >> sth;
        v.push_back({i,sth});
        for (int j=0;j<v.size()-1;j++){
            if (v[j].second<v[i].second){
                mp[v[j].first]=sth;
                v.erase(v.begin()+j);
                j--;       
            }
        }
    }
    for (int i=0;i<num;i++){
        if (!mp[i]) cout << "-1" << " ";
        else cout << mp[i] << " ";
    }
}