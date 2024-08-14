#include <bits/stdc++.h>

using namespace std;

int N, M, r=0, answer=INT_MAX;
vector<int> v;

int check(int num){
    int sum=0, cnt=1, idx=0;
    while(idx<v.size()){
        if (sum+v[idx]>num){
            if (v[idx]>num) return 0;
            sum=0;
            cnt++;
        }
        else{
            sum+=v[idx];
            idx++;
        }
    }
    if (cnt<=M) return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        r+=temp;
    }
    
    int l=0;
    while(l<=r){
        int mid=(l+r)/2;
        if (check(mid)){
            r=mid-1;
            answer=min(mid,answer);
        }
        else{
            l=mid+1;
        }
    }

    cout << answer;
}