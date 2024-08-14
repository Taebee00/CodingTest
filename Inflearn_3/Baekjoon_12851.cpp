#include <bits/stdc++.h>

using namespace std;

int N, K, visitied[100001]={0,}, ret=INT_MAX, cnt=0;

vector<int> cal(int temp){
    vector<int> v;
    v.push_back(temp+1);
    v.push_back(temp-1);
    v.push_back(temp*2);
    return v;
}

void bfs(int start, int finish){
    queue<int> que;
    que.push(start);
    visitied[start]=1;
    while(que.size()){
        int temp=que.front();
        que.pop();
        vector<int> temp_v=cal(temp);
        if (visitied[temp]==ret) break;
        for (int i:temp_v){
            if (i==finish){
                ret=visitied[temp]+1;
                cnt++;
            }
            if (i<0||i>100000) continue;
            if (visitied[i]&&visitied[i]<visitied[temp]+1) continue; 
            que.push(i);
            visitied[i]=visitied[temp]+1;
        }
    }
}

int main()
{
    cin >> N >> K;
    if (N==K){
        cout << "0\n1";
        return 0;
    }
    bfs(N,K);
    cout << ret-1 << "\n" << cnt;
}