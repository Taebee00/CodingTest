#include <bits/stdc++.h>

using namespace std;

int N,M,low=0,high=0,ret=INT_MAX;
vector<int> v;
int sum[100001]={0,};

int main()
{
    cin >> N >> M;
    for (int i=1;i<=N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        high+=temp;
        low=max(low,temp);
    }
    while(low<=high){
        int mid=(low+high)/2;
        int cnt=0;
        for (int i=0;i<v.size();i++){
            int sum=0,flag=0;
            while(i<v.size()&&sum+v[i]<=mid){
                flag=1;
                sum+=v[i];
                i++;
            }
            if (flag){
                cnt++;
                i--;
            }
        }
        if (cnt>M) low=mid+1;
        else{
            high=mid-1;
            ret=min(ret,mid);
        }
    }
    cout << ret;
}