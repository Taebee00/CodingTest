#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    if (a.size()==b.size()){
        return a < b;
    }
    return a.size() < b.size();
}

int main(){
    int num;
    string str;
    vector<string> v;
    cin >> num;
    for (int i=0;i<num;i++){
        string sth="";
        cin >> str;
        for (int j=0;j<str.length();j++){
            if (str[j]>='0'&&str[j]<='9'){
                sth+=str[j];
            }
            if (sth.size()&&(j==str.length()-1||(str[j]>='a'&&str[j]<='z'))){
                while (sth.size()>1&&sth[0]=='0'){
                    sth.erase(0,1);
                }
                v.push_back(sth);
                sth="";
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    for (auto&i:v){
        cout << i << "\n";
    }
}
