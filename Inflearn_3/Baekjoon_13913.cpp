// #include <bits/stdc++.h>
// using namespace std;

// int n,k, visitied[100001]={0,}, parent[100001]={-1,};
// queue<int> mp;
// stack<int> ret;

// void find(int loc, int goal){
//     parent[loc]=-1;
//     visitied[loc]=1;
//     mp.push(loc);
//     while(!mp.empty()){
//         if (mp.front()==goal){
//             ret.push(mp.front());
//             while(parent[ret.top()]!=-1){
//                 ret.push(parent[ret.top()]);
//             }
//             cout << visitied[mp.front()]-1 << "\n";
//             while(!ret.empty()){ 
//                 cout << ret.top() << " ";
//                 ret.pop();
//             }
//         }
//         for (auto &i:{mp.front()-1,mp.front()+1,mp.front()*2}){
//             if (i>=0&&i<=100000&&!visitied[i]){
//                 visitied[i]=visitied[mp.front()]+1;
//                 mp.push(i);
//                 parent[i]=mp.front();
//             }
//         }
//         mp.pop();
//     }
// }

// int main()
// {
//     cin >> n >> k;
//     find(n,k);
// }

#include <bits/stdc++.h>

using namespace std;

int N, K, arr[100001], visitied[100001]={0,}, from[100001];
vector<int> v;

int bfs(int start,int end){
    queue<int> que;
    visitied[start]=1;
    que.push(start);
    while(que.size()){
        int temp=que.front();
        que.pop();
        for (int i:{temp-1,temp+1,temp*2}){
            if (i<0||i>100000||visitied[i]) continue;
            visitied[i]=visitied[temp]+1;
            que.push(i);
            from[i]=temp;
            if (i==end){
                return visitied[i]-1;
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    if (N==K) {
        cout << "0\n" << N;
        return 0;
    }
    cout << bfs(N,K) << "\n";
    for (int i=K;;i=from[i]){
        v.push_back(i);
        if (from[i]==N){
            v.push_back(N);
            break;
        }
    }
    reverse(v.begin(),v.end());
    for (int i:v) cout << i << " ";
}