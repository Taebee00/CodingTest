#include <bits/stdc++.h>

using namespace std;

int N, M, temp, same_cnt, answer;
vector<int> B;
map<int,int> A;

int find_idx(int num){
    if (num==*lower_bound(B.begin(),B.end(),num)){
        int ret=upper_bound(B.begin(),B.end(),num)-lower_bound(B.begin(),B.end(),num);
        return ret;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i=0;i<N;i++){
        cin >> temp;
        A[temp]++;
    }

    for (int i=0;i<M;i++){
        cin >> temp;
        B.push_back(temp);
    }

    sort(B.begin(),B.end());

    for (auto i:A){
        same_cnt+=2*min(i.second,find_idx(i.first));
    }
    cout << N+M-same_cnt;
}