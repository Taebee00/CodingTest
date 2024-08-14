#include <bits/stdc++.h>

using namespace std;

int N, M, last, answer=0, visitied[2000]={0,};
vector<int> v[2000];

void dfs(int sz){
    if (sz==5){
        answer=1;
        return;
    }
    if (sz==0){
        for (int i=0;i<N;i++){
            last=i;
            visitied[i]=1;
            dfs(sz+1);
            visitied[i]=0;
        }
    }
    else{
        for (int i:v[last]){
            if (!visitied[i]){
                int temp=last;
                last=i;
                visitied[last]=1;
                dfs(sz+1);
                visitied[last]=0;
                last=temp;
            } 
        }
    }
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);  

    cin >> N >> M;

    for (int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(0);

    cout << answer;
}