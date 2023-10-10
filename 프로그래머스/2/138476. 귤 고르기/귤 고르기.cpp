#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;

int solution(int k, vector<int> tangerine) {
    map<int,int> mp;
    for (int &i:tangerine){
        mp[i]++;
    }
    for (int &i:tangerine){
        v.push_back({mp[i],i});
    }
    sort(v.begin(),v.end());
    // for (int i=0;i<v.size();i++){
    //     printf("%d %d   ",v[i].first,v[i].second);
    // }
    for (int i=0;i<(tangerine.size()-k);i++){
        v.erase(v.begin());
    }
    int answer=1;
    for (int i=0;i<v.size()-1;i++){
        if (v[i].second!=v[i+1].second){
            answer++;
        }
    }
    return answer;
}