#include <bits/stdc++.h>

using namespace std;

vector<long long> v;
long long N, temp;

void dfs(int sz){
    for (int i=0;i<10;i++){
        if (sz==0){
            temp=i;
            v.push_back(temp);
            dfs(sz+1);
        }
        else if (temp%10>i){
            temp=temp*10+i;
            v.push_back(temp);
            dfs(sz+1);
            temp/=10;
        }
    }
}

int main()
{
    cin >> N;

    dfs(0);

    sort(v.begin(),v.end());

    if (N>=v.size()) cout << -1;
    else cout << v[N];
}