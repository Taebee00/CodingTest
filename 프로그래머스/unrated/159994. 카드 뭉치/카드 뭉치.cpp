#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int idx_1=0;
    int idx_2=0;
    for (string &word:goal){
        if (cards1[idx_1]==word) idx_1++;
        else if (cards2[idx_2]==word) idx_2++;
        else{
            answer="No";
            break;
        }
    }
    return answer;
}