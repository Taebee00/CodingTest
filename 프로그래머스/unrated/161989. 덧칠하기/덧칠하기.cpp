#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int mn=1000001, mx=0;
    for (auto &i:section){
        mx=max(mx,i);
        mn=min(mn,i);
    }
    int idx=0;
    for (auto &i:section){
        if (idx>mx){
            break;
        }
        if (idx<=i){
            idx=i;
            idx+=m;
            answer++;
        }
    }
    return answer;
}