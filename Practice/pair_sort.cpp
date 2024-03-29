#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second; // pair의 두번째 인자 기준 오름차순 정렬
}

int main()
{
    for (int i = 0; i < 10; i++){
        v.push_back({i, 10-i});
    }
    sort(v.begin(),v.end(),cmp);
    for (auto it : v) cout << it.first << " : " << it.second << "\n";
}