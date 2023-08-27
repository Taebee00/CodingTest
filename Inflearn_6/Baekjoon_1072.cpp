#include <bits/stdc++.h>

using namespace std;

long long X, Y,ret=INT_MAX;

int main()
{
    cin >> X >> Y;
    int per=Y*100/X;

    long long low=1, high=INT_MAX;
    while(low<=high){
        long long mid=(low+high)/2;
        //printf("%d\n",mid);
        int temp_per=((100*(Y+mid))/(X+mid));
        if (temp_per==per){
            low=mid+1;
        }
        else{
            high=mid-1;
            ret=min(ret,mid);
        }
    }
    if (high==INT_MAX||X==Y) cout << -1;
    else cout << ret;
}