#include <bits/stdc++.h>

using namespace std;

int main()
{
    int S,C;
    long long low=1,high=0,ret=0,rret=0;
    vector<int> v;
    cin >> S >> C;
    for (int i=0;i<S;i++){
        long long temp;
        cin >> temp;
        v.push_back(temp);
        high=max(high,temp);
    }
    while(low<=high){
        long long mid=(low+high)/2;
        int cnt=0;
        for (int&i:v){
            cnt+=i/mid;
        }
        if (cnt>=C){
            low=mid+1;
            ret=max(ret,mid);
        }
        else{
            high=mid-1;
        }
    }
    int cnt=0;
    for (int &i:v){
        while(i>0&&cnt<C){
            i-=ret;
            cnt++;
        }
        rret+=i;
    }
    cout << rret;
}