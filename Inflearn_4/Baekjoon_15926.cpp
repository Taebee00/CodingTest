#include <bits/stdc++.h>

using namespace std;

int n, mx=0;
stack<char> char_stk;
stack<int> idx_stk;
string str;

int main()
{
    cin >> n;
    
    cin >> str;

    idx_stk.push(-1);

    for (int i=0;i<str.size();i++){
        if (!char_stk.size()||str[i]=='('){
            char_stk.push(str[i]);
            idx_stk.push(i);
        }
        else if (str[i]==')'){
            if (char_stk.top()=='('){
                char_stk.pop();
                idx_stk.pop();
            }
            else{
                char_stk.push(str[i]);
                idx_stk.push(i);
            }
        }
    }
    idx_stk.push(str.size());
    while(idx_stk.size()>1){
        int a=idx_stk.top();
        idx_stk.pop();
        int b=idx_stk.top();
        mx=max(a-b-1,mx);
    }
    if (char_stk.size()==str.size()) cout << "0";
    else cout << mx;
}