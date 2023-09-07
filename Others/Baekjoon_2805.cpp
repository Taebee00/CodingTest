#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N,M,low=0,high=0,ret=0;
    vector<long long> v;
    cin >> N >> M;
    for (int i=0;i<N;i++){
        long long temp;
        cin >> temp;
        v.push_back(temp);
        high=max(high,temp);
    }
    while(low<=high){
        long long sum=0;
        long long mid=(low+high)/2;
        //printf("%d\n",mid);
        for (int i:v){
            if (i-mid>0) sum+=i-mid;
        }
        if (sum>=M){
            low=mid+1;
            ret=max(mid,ret);
        }
        else high=mid-1;
    }
    printf("%lld",ret);
}