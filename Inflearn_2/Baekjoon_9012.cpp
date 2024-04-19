#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    string str;
    vector<string> answer_v;
    cin >> T;

    for (int i=0;i<T;i++){
        cin >> str;
        stack<char> stk;

        for (char j:str){
            if (j==')'&&stk.size()&&stk.top()=='('){
                stk.pop();
            }
            else{
                stk.push(j);
            }
        }

        if (stk.size()) answer_v.push_back("NO");
        else answer_v.push_back("YES");
    }
    for (string i:answer_v) cout << i << "\n";
}