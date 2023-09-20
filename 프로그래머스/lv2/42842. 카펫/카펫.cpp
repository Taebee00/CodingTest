#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int vertical, horizontal;
    for (int i=1;i<=sqrt(yellow);i++){
        if (yellow%i==0){
            vertical=yellow/i;
            horizontal=i;
        }
        if ((vertical+2)*(horizontal+2)-yellow==brown){
            answer.push_back(vertical+2);
            answer.push_back(horizontal+2);
            return answer;
        }
    }
}