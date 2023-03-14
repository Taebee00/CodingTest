#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    string str[104];
    vector<long long> v;
    cin >> num;
    for (int i=0;i<num;i++){
        cin >> str[i];
        int first=-1, last=-1;
        for (int j=0;j<str[i].length();j++){
            if (first==-1&&str[i][j]>='0'&&str[i][j]<='9'){
                first=j;
            }
            if (first!=-1){
                if (str[i][j]>='a'&&str[i][j]<='z'){
                    last=j;
                }
                else if (j==str[i].length()-1){
                    last=j+1;
                }
            }
            if (first!=-1&&last!=-1){
                v.push_back(atoi((str[i].substr(first,last).c_str())));
                first=-1; last=-1;
            }
        }
    }
    sort(v.begin(),v.end());
    for (auto&i:v){
        cout << i << '\n';
    }
}