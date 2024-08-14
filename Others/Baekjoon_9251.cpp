#include <bits/stdc++.h>

using namespace std;

int N, K, visitied[100001]={0,}, time_arr[3]={0,1,1};
pair<int,int> dloc[3]={{2,0},{1,1},{1,-1}};

int bfs(int start, int end){
    queue<int> que;
    visitied[start]=1;
    que.push(start);
    while(que.size()){
        int loc=que.front();
        que.pop();
        for (int i=0;i<3;i++){
            int nloc=(loc*dloc[i].first)+dloc[i].second;
            if (nloc>=0&&nloc<=100000&&(!visitied[nloc]||visitied[nloc]>visitied[loc]+time_arr[i])){
                que.push(nloc);
                visitied[nloc]=visitied[loc]+time_arr[i];
                if (nloc==end) return visitied[nloc]-1;
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    if (N==K) cout << 0;
    else cout << bfs(N,K);
}