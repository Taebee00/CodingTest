#include <bits/stdc++.h>
using namespace std;

int main(){
    string PS; 
    while(true){
        getline(cin,PS);
        if (PS.length()==1&&PS[0]=='.') break;
        stack<char> stk;
        for (auto&j:PS){
            if (j=='['||j==']'||j=='('||j==')'){
                if (stk.size()&&stk.top()=='('&&j==')'){
                    stk.pop();
                }
                else if (stk.size()&&stk.top()=='['&&j==']'){
                    stk.pop();
                }
                else stk.push(j);
            }
        }
        if (stk.size()){
            cout << "no" << "\n";
        }
        else cout << "yes" << "\n";
    }
}