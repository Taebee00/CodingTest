#include <bits/stdc++.h>
using namespace std;

int main(){
    int num; string PS; 
    cin >> num;
    for (int i=0;i<num;i++){
        stack<char> stk;
        cin >> PS;
        for (auto&j:PS){
            if (stk.size()&&j==')'&&stk.top()=='('){
                stk.pop();
            }
            else stk.push(j);
        }
        if (stk.size()){
            cout << "NO" << "\n";
        }
        else cout << "YES" << "\n";
    }
}