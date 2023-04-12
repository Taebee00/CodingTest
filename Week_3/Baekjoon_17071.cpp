#include <bits/stdc++.h>
using namespace std;

int visitied[500001];
int subin_loc[500001];
queue<int> q;

void find(int start,int goal){
    if (start==goal){
        cout << '0';
        return;
    }
    visitied[start]=1;
    subin_loc[start]=goal;
    q.push(start);
    while(!q.empty()){
        for (auto &i:{q.front()-1,q.front()+1,q.front()*2}){
            if (i>=0&&i<=500001){
                visitied[i]=visitied[q.front()]+1;
                subin_loc[i]=visitied[q.front()]+subin_loc[q.front()];
                if (subin_loc[i]>500000){
                    cout << "-1";
                    return;
                }
                cout << subin_loc[q.front()] << " ";
                if (i==subin_loc[i]){
                    cout << visitied[i]-1;
                    return;
                }
                q.push(i);
                cout << i << " ";
            }
        }
        q.pop();
        cout << "\n";
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    find(n,k);
}