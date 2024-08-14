#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    vector<string> str_v;
    getline(cin,str);
    int idx=0;
    for (int i=0;i<str.size();i++){
        if (str[i]==' '){
            str_v.push_back(str.substr(idx,i-idx));
            idx=i+1;
        }
    }
    str_v.push_back(str.substr(idx,str.size()-idx));
    
    if (str_v[0]=="encrypt"){
        vector<int> sum_v;
        for (int i=0;i<str_v[1].size();i++){
            sum_v.push_back((str_v[1][i]+str_v[3][i]-'a'-'a')%26);
        }
        int dir=stoi(str_v[2]);
        if (dir>0){
            rotate(sum_v.begin(),sum_v.begin()+dir,sum_v.end());
        }
        else rotate(sum_v.begin(),sum_v.end()-dir,sum_v.end());
        for (int i:sum_v){
            cout << char(i+'a');
        }
    }
    else{
        vector<int> answer_str;
        int dir=stoi(str_v[2]);
        if (dir>0){
            rotate(str_v[3].begin(),str_v[3].end()-dir,str_v[3].end());
        }
        else{
            rotate(str_v[3].begin(),str_v[3].begin()+dir,str_v[3].end());
        }
        for (int i=0;i<str_v[1].size();i++){
            answer_str.push_back((str_v[3][i]+26-str_v[1][i])%26);
        }
        for (int i:answer_str){
            cout << char(i+'a');
        }
    }   
}