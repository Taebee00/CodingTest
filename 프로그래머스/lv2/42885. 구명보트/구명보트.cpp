#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int answer = 0;
    int small=0;
    int big=people.size()-1;
    int cnt=0;
    while(small<big){
        if (people[small]+people[big]<=limit){  
            small++;
            big--;
            cnt++;
        }
        else{
            cnt++;
            big--;
        }
        if (small==big){
            cnt++;
        }
    }

    return answer=cnt;
}