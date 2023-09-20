#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,int> mp;
    int turn=1;
    mp[words[0]]=1;
    for (int i=1;i<words.size();i++){
        if (words[i][0]!=words[i-1][words[i-1].size()-1]||mp[words[i]]!=0){
            break;
        }
        mp[words[i]]=1;
        turn++;
    }
    if (turn==words.size()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(turn%n+1);
        answer.push_back(turn/n+1);
    }
    printf("%d ",turn);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << "Hello Cpp" << endl;

    return answer;
}