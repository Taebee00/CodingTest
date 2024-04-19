#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    vector<string> answer_v;

    while(1){
        stack<char> stk;
        int flag=0;
        getline(cin,str);

        if (str=="."){
            break;
        }

        for (char i:str){
            if (i=='('||i=='['){
                stk.push(i);
            }
            else if (i==')'){
                if (stk.size()&&stk.top()=='('){
                    stk.pop();
                }
                else{
                    flag=1;
                    break;
                }
            }
            else if (i==']'){
                if (stk.size()&&stk.top()=='['){
                    stk.pop();
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        if (stk.size()) flag=1;

        if (flag) answer_v.push_back("no");
        else answer_v.push_back("yes");
    }
    for (string i:answer_v) cout << i << "\n";
}