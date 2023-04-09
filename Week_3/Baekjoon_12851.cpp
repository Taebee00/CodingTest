#include <bits/stdc++.h>
using namespace std;

int n,k, visitied[100001]={0,};
queue<int> mp;

pair<int,int> find(int loc, int goal){
    visitied[loc]=1;
    mp.push(loc);
    while(!mp.empty()){
        int mn,cnt=0;
        if (mp.front()==goal){
            mn=visitied[mp.front()];
            while(!mp.empty()){
                if (mn==visitied[mp.front()]){
                    cnt++;
                }
                mp.pop();
            }
            return {mn,cnt};
        }
        if (mp.front()>0&&!visitied[mp.front()-1]){
            mp.push(mp.front()-1);
            visitied[mp.front()-1]=visitied[mp.front()]+1;
        }
        if (mp.front()<100000&&!visitied[mp.front()+1]){
            mp.push(mp.front()-1);
            visitied[mp.front()+1]=visitied[mp.front()]+1;
        }
        if (mp.front()*2<=100000&&!visitied[mp.front()*2]){
            mp.push(mp.front()*2);
            visitied[mp.front()*2]=visitied[mp.front()]+1;
        }
        mp.pop();
    }
}

int main()
{
    cin >> n >> k;
    pair<int,int> ret = find(n,k);
    cout << ret.first << ret.second;
}