#include <bits/stdc++.h>

using namespace std;

int N, S, answer=0, visitied[30]={0,};
vector<int> v;
vector<int> chosen_v;

void dfs(int sz,int sum,int idx){
    if (sum==S){
        answer++;
    }
    if (sz==N){
        return;
    }
    for (int i=idx+1;i<v.size();i++){
        if (!visitied[i]){
            visitied[i]=1;
            dfs(sz+1,sum+v[i],i);
            visitied[i]=0;
        }
    }
}

int main()
{
    cin >> N >> S;

    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    dfs(0, 0, -1);
    if (S==0) answer--;
    cout << answer;
}