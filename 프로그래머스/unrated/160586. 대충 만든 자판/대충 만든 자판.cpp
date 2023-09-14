#include <string>
#include <vector>
#include <map>

using namespace std;

map<char,int> mp;
vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for (char i='A';i<='Z';i++){
        mp[i]=1000;
    }
    for (string& i:keymap){
        for (int k=0;k<i.size();k++){
            if (mp[i[k]]>k){
                mp[i[k]]=k;
            }
        }
    }
    
    for (string& i:targets){
        int temp=0,flag=0;
        for (char &k:i){
            if (mp[k]==1000){
                flag=1;
                break;
            }
            temp+=mp[k]+1;
        }
        if (!flag) answer.push_back(temp);
        else answer.push_back(-1);
    }
    return answer;
}