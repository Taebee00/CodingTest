#include <bits/stdc++.h>

using namespace std;

string str, answer_str, mn="9999999999", mx="0";
vector<int> v;
int visitied[9];

void dfs(int sz){
    if (sz==v.size()){
        if (answer_str<mn) mn=answer_str;
        if (answer_str>mx) mx=answer_str;
        return;
    }
    for (int i=0;i<v.size();i++){
        if (!visitied[i]){
            string temp_str=to_string(v[i]);
            answer_str+=temp_str;
            visitied[i]=1;
            dfs(sz+1);
            answer_str.erase(answer_str.size()-temp_str.size(),temp_str.size());
            visitied[i]=0;
        }
    }
}

int main()
{
    getline(cin,str);
    int idx=0;
    for (int i=0;i<str.size();i++){
        if (str[i]==' '){
            int temp=stoi(str.substr(idx,i-idx));
            v.push_back(temp);
            idx=i+1;
        }
    }
    v.push_back(stoi(str.substr(idx,str.size()-idx)));

    int cnt=0;
    for (int i:v){
        if (i>99&&i<1000){
            cnt++;
        }
    }
    if (cnt){
        if (v.size()>6&&v.size()<=9){
            cout << "-1";
            return 0;
        }
    } 

    dfs(0);
    
    cout << stoi(mx)+stoi(mn);
}