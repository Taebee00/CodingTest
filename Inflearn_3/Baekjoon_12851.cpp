#include <bits/stdc++.h>
using namespace std;

int n,k, visitied[100001]={0,}, way[100001]={0,};
queue<int> mp;

pair<int,int> find(int loc, int goal){
    visitied[loc]=1;
    way[loc]=1;
    mp.push(loc);
    int flag,mn=100000,cnt=0;
    while(!mp.empty()){
        if (mp.front()==goal){
            return {mn,way[goal]};
        }
        if (mp.front()>0){
            if (!visitied[mp.front()-1]){
                mp.push(mp.front()-1);
                visitied[mp.front()-1]=visitied[mp.front()]+1;
                way[mp.front()-1]=way[mp.front()];
            }
            else if (visitied[mp.front()-1]==visitied[mp.front()]+1){
                way[mp.front()-1]+=way[mp.front()];
            }
        }
        if (mp.front()<100000){
            if (!visitied[mp.front()+1]){
                mp.push(mp.front()+1);
                visitied[mp.front()+1]=visitied[mp.front()]+1;
                way[mp.front()+1]=way[mp.front()];
            }
            else if (visitied[mp.front()+1]==visitied[mp.front()]+1){
                way[mp.front()+1]+=way[mp.front()];
            }
        }
        if (mp.front()*2<=100000){
            if (!visitied[mp.front()*2]){
                mp.push(mp.front()*2);
                visitied[mp.front()*2]=visitied[mp.front()]+1;
                way[mp.front()*2]=way[mp.front()];
            }
            else if (visitied[mp.front()*2]==visitied[mp.front()]+1){
                way[mp.front()*2]+=way[mp.front()];
            }
        }
        mp.pop();
    }
}

int main()
{
    cin >> n >> k;
    pair<int,int> ret = find(n,k);
    cout << ret.first-1 << " " << ret.second;
}