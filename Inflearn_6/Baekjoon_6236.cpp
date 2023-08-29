#include <bits/stdc++.h>

using namespace std;

int N, M;
long long low=0, high=1e18,ret;
vector<int> v;

int main()
{
    cin >> N >> M;
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        low=max((long long)temp,low);
    }
    
    while(low<=high){
        long long mid=(low+high)/2;
        long long temp=0,cnt=0;
        for (int i:v){
            if ((long long)i>temp){
                cnt++;
                temp=mid;
            }
           temp-=(long long)i;
        }
        if (cnt<=(long long)M){
            high=mid-1; 
            ret=mid;
        }
        else low=mid+1;
    }
    printf("%lld",ret);
    // long long mid=500;
    // long long temp=0,cnt=0;
    // for (int i:v){
    //     if ((long long)i>temp){
    //         cnt++;
    //         temp=mid;
    //         printf("1 %d\n",temp);
    //     }
    //     else{
    //         temp-=(long long)i;
    //         printf("0 %d\n",temp);
    //     }
    // }
}