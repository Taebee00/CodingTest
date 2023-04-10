#include <bits/stdc++.h>
using namespace std;

int n,k, visitied[100001]={0,}, parent[100001]={-1,};
queue<int> mp;
stack<int> ret;

void find(int loc, int goal){
    parent[loc]=-1;
    visitied[loc]=1;
    mp.push(loc);
    while(!mp.empty()){
        if (mp.front()==goal){
            ret.push(mp.front());
            while(parent[ret.top()]!=-1){
                ret.push(parent[ret.top()]);
            }
            cout << visitied[mp.front()]-1 << "\n";
            while(!ret.empty()){ 
                cout << ret.top() << " ";
                ret.pop();
            }
        }
        for (auto &i:{mp.front()-1,mp.front()+1,mp.front()*2}){
            if (i>=0&&i<=100000&&!visitied[i]){
                visitied[i]=visitied[mp.front()]+1;
                mp.push(i);
                parent[i]=mp.front();
            }
        }
        mp.pop();
    }
}

int main()
{
    cin >> n >> k;
    find(n,k);
}