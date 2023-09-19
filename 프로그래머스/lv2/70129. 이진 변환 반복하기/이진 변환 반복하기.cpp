#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<string,int> cal(string s){
    int cnt=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='1'){
            cnt++;
        }
    }
    int num=cnt;
    string ret="";
    while(num!=0){
        ret+=(num%2)+'0';
        num/=2;
    }   
    reverse(ret.begin(),ret.end());
    return {ret,s.size()-cnt};
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0,zeros=0;
    while(s!="1"){
        pair<string,int> ret=cal(s);
        s=ret.first;
        zeros+=ret.second;
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zeros);
    return answer;
}