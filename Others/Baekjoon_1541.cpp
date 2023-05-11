#include <bits/stdc++.h>
using namespace std;

vector<int> num_v;
vector<char> cal_v;

int main(){
    string formula;
    int tempidx=0, flag=0;
    cin >> formula;
    for (int i=0;i<formula.length();i++){
        if (formula[i]=='+'||formula[i]=='-'){
            cal_v.push_back(formula[i]);
            string temp=formula.substr(tempidx,i);
            tempidx=i+1;
            num_v.push_back(stoi(temp));
        }
        else if (i==formula.length()-1){
            string temp=formula.substr(tempidx,i+1);
            num_v.push_back(stoi(temp));
        }
    }
    int sum=num_v[0];
    for (int i=0;i<cal_v.size();i++){
        if (cal_v[i]=='+'){
            if (flag==0){
                sum+=num_v[i+1];
            }
            else{
                sum-=num_v[i+1];
            }
        }
        if (cal_v[i]=='-'){
            flag=1;
            sum-=num_v[i+1];
        }
    }
    cout << sum;
}