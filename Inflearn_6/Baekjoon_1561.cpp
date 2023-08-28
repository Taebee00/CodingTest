#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    vector<int> v;
    cin >> N >> M;
    for (int i=0;i<M;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    long long low=0, high=60000000004,tm=__LONG_LONG_MAX__;

    while(low<=high){
        long long mid=(low+high)/2;
        long long cnt=0;
        for (int i:v){
            cnt+=mid/i+1;
        }
        if (cnt>=N){
            high=mid-1;
            tm=min(mid,tm);
        }
        else low=mid+1;
    }

    long long cnt=0, temp_tm=0;
    for (int i:v){
        cnt+=tm/(long long)i;
        temp_tm=max(temp_tm,tm%(long long)i);
    }
    temp_tm=tm-temp_tm;
    //printf("tm: %lld temp_tm: %lld cnt: %lld\n",tm,temp_tm,cnt);
    while(1){
        for (int i=0;i<v.size();i++){
            if (tm-(tm%v[i])==temp_tm){
                //printf("%lld:%d ",temp_tm,i); 
                cnt++;
            }
            if (cnt==N) {
                printf("%d",i+1); 
                return 0;
            }
        }
        temp_tm++;
    }
}