#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> mp;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for (int i=0;i<name.size();i++){
        mp[name[i]]=yearning[i];
    }
    for (int i=0;i<photo.size();i++){
        int sum=0;
        for (auto &j:photo[i]){
            sum+=mp[j];
        }
        answer.push_back(sum);
    }
    return answer;
}