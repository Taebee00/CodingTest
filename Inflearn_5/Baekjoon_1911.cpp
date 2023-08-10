#include <bits/stdc++.h>

using namespace std;


int N,L,first,last;
vector<pair<int,int>> v;

int main(){
    
    cin >> N >> L;
    for (int i=0;i<N;i++){
        int start;
        int end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end());
    int cnt=0, temp=v[0].first;
    for (auto&i:v){
        if (temp<i.first){
            temp=i.first;
        }
        while(temp<i.second){
            temp+=L;
            cnt++;
        }
    }
    cout << cnt;
}