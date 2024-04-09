#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    if (a.length()==b.length()){
        return a<b;
    }
    return a.length() < b.length();
}

int main()
{
    int N;
    string str;
    vector<string> num_v;

    cin >> N;
    
    for (int i=0;i<N;i++){
        cin >> str;
        string num="";

        for (int j=0;j<str.length();j++){
            if (str[j]>='0'&&str[j]<='9'){
                if (num=="0"){
                    num=str[j]; 
                }
                else{
                    num+=str[j];
                }
                if (j==str.length()-1||(str[j+1]>='a'&&str[j+1]<='z')){
                    num_v.push_back(num);
                    num="";
                }
            }
        }
    }

    sort(num_v.begin(),num_v.end(),cmp);

    for (string i:num_v) cout << i << "\n";
}