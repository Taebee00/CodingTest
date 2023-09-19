#include <string>
#include <vector>

using namespace std;

int sum[10001];

int solution(int n) {
    int answer = 0;
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+i;
    }
    for (int i=0;i<n;i++){
        for (int j=i;j<=n;j++){
            if (sum[j]-sum[i]==n){
                answer++;
                break;
            }
            if (sum[j]-sum[i]>n){
                break;
            }
        }
    }
    return answer;
}