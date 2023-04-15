#include <bits/stdc++.h>
using namespace std;

int k;
string mx,mn="9999999999";
char cmp[10];
vector<char> v;

void dfs(int sz, vector<char> v){
    if (sz==k){
        string str="";
        for (int i=0;i<v.size();i++){
            str+=v[i];
        }
        if (str>mx){
            mx=str;
        }
        if (str<mn){
            mn=str;
        }
    }
    for (int i='0';i<='9';i++){
        if (!v.size()){
            v.push_back(i);
            dfs(sz+1,v);
            v.erase(v.end()-1);
        }   
        else if (v.size()&&find(v.begin(),v.end(),i)==v.end()){
            if (cmp[sz]=='>'&&(v[sz]>i)){
                v.push_back(i);
                dfs(sz+1,v);
                v.erase(v.end()-1);
            }
            else if (cmp[sz]=='<'&&(v[sz]<i)){
                v.push_back(i);
                dfs(sz+1,v);
                v.erase(v.end()-1);                
            }
        }
    }
}

int main(){
    cin >> k;
    for (int i=0;i<k;i++){
        cin >> cmp[i];
    }
    dfs(-1,v);
    for (auto i:{mx,mn}){
        if (i.length()<k+1){
            cout << "0"; 
        }
        cout << i << "\n";
    }
}