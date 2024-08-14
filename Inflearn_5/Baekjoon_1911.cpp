#include <bits/stdc++.h>

using namespace std;

int N, L, answer=0;
vector<pair<int,int>> v;

int main()
{
    cin >> N >> L;

    for (int i=0;i<N;i++){
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end());
    int temp=0;
    for (auto i:v){
        if (temp>=i.second) continue;
        int temp=max(temp,i.first);
        while(temp<i.second){
            temp+=L;
            answer++;
        }
    }
    cout << answer;
}