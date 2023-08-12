#include <bits/stdc++.h>

using namespace std;

int n, last_date=0;
vector<pair<int,int>> v;
priority_queue<int> pq;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if (a.second>b.second){
        return 1;
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        int money, date;
        cin >> money >> date;
        v.push_back({money,date});
        last_date=last_date<date?date:last_date;
    }
    sort(v.begin(),v.end(),cmp);
    int idx=0,sum=0;
    for (int i=last_date;i>0;i--){
        while(v[idx].second>=i&&idx<n){
            pq.push(v[idx].first);
            idx++;
        }
        if (pq.size()){
            sum+=pq.top();
            pq.pop();
        }
    }
    cout << sum;
}