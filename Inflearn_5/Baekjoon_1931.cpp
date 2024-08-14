#include <bits/stdc++.h>

using namespace std;

int N, answer=0;
vector<pair<int,int>> v;

int main()
{
    cin >> N;
    
    for (int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());

    int limit=0;
    for (auto i:v){
        if (i.second>=limit){
            limit=i.first;
            answer++;
        }
    }
    cout << answer;
}