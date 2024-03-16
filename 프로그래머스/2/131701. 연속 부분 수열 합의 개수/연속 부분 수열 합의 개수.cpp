#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    vector<int> vec;
    for (int i=0;i<elements.size();i++){
        int sum=0;
        for (int j=i;j<i+elements.size();j++){
            sum+=elements[j%elements.size()];
            vec.push_back(sum);
        }
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    return vec.size();
}