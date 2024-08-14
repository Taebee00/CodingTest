// #include <bits/stdc++.h>

// using namespace std;

// int N,K,C[300000];
// pair<int,int> jewel[300000];
// priority_queue<int> pq;
// long long sum=0;

// bool jewel_cmp(const pair<int,int> &a, const pair<int,int> &b)
// {
//     if (a.first==b.first){
//         return a.second > b.second;
//     }
//     return a.first < b.first;
// }

// bool C_cmp(const int &a, const int &b)
// {
//     return a<b;
// }

// int main()
// {
//     cin >> N >> K;
//     for (int i=0;i<N;i++){
//         cin >> jewel[i].first >> jewel[i].second;
//     }
//     for (int i=0;i<K;i++){
//         cin >> C[i];
//     }
//     sort(jewel,jewel+N,jewel_cmp);
//     sort(C,C+K,C_cmp);
//     int idx=0;
//     for (int i=0;i<K;i++){
//         while(jewel[idx].first<=C[i]&&idx<N){
//             pq.push(jewel[idx].second);
//             idx++;
//         }
//         if (!pq.empty()){
//             sum+=pq.top();
//             pq.pop();
//         }
//     }
//     cout << sum;
// }
#include <bits/stdc++.h>

using namespace std;

int N, K;
long long answer=0;
vector<pair<long long,long long>> jewels;
priority_queue<long long> pq;
vector<int> bags;

int main()
{
    cin >> N >> K;

    for (int i=0;i<N;i++){
        long long a,b;
        cin >> a >> b;
        jewels.push_back({a,b});
    }
    for (int i=0;i<K;i++){
        int temp;
        cin >> temp;
        bags.push_back(temp);
    }
    sort(jewels.begin(),jewels.end());
    sort(bags.begin(),bags.end());
    int idx=0;
    for (int i:bags){
        while(idx<N&&jewels[idx].first<=i){
            pq.push(jewels[idx].second);
            idx++;
        }
        if (pq.size()){
            answer+=pq.top();
            pq.pop();
        }
    }
    cout << answer;
}