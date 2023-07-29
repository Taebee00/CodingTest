#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, max_dealine=0, sum=0;
    map<int,vector<int>> mp;
    priority_queue<int> pq;
    cin >> N;
    for (int i=0;i<N;i++){
        int deadline, ramen;
        cin >> deadline >> ramen;
        mp[deadline].push_back(ramen);
        if (deadline>max_dealine){
            max_dealine=deadline;
        }
    }
    for (int i=max_dealine;i>=1;i--){
        for (int j=0;j<mp[i].size();j++){
            pq.push(mp[i][j]);
        }
        if (!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
    }
    cout << sum;
}