#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for (long long i=1;i<=r2;i++){
        long long _r1=(long long)r1;
        long long _r2=(long long)r2;
        long long low=0; long long high=_r2;
        long long left=2000000,right=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if (i*i+mid*mid>_r2*_r2){
                high=mid-1;
            }
            else if (i*i+mid*mid<=_r2*_r2){
                low=mid+1;
                right=max(mid,right);
            }
        }
        low=0;
        high=_r2;
        while(low<=high){
            long long mid=(low+high)/2;
            if (i*i+mid*mid<_r1*_r1){
                low=mid+1;
            }
            else if (i*i+mid*mid>=_r1*_r1){
                high=mid-1;
                left=min(mid,left);
            }
        }
        answer=answer+(right-left)+1;
    }
    return 4*answer;
}