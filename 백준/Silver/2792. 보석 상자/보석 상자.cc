#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    long long int N, M, low=1, high=0, ret=__LONG_LONG_MAX__;
    cin >> N >> M;
    vector<long long int> color;
    for (int i=0;i<M;i++){
        long long int temp;
        cin >> temp;
        color.push_back(temp);
        high=max(temp,high);
    }
    while(low<=high){
        long long int mid=(low+high)/2;
        long long int cnt=0;
        for (long long int &i:color){
            cnt+=i/mid;
            if (i%mid) cnt++;
        }
        if (cnt>N){
            low=mid+1;
        }
        else{
            ret=min(ret,mid);
            high=mid-1;
        }
    }
    cout << ret;
}