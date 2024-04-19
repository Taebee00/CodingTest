// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     string PS; 
//     while(true){
//         getline(cin,PS);
//         if (PS.length()==1&&PS[0]=='.') break;
//         stack<char> stk;
//         for (auto&j:PS){
//             if (j=='['||j==']'||j=='('||j==')'){
//                 if (stk.size()&&stk.top()=='('&&j==')'){
//                     stk.pop();
//                 }
//                 else if (stk.size()&&stk.top()=='['&&j==']'){
//                     stk.pop();
//                 }
//                 else stk.push(j);
//             }
//         }
//         if (stk.size()){
//             cout << "no" << "\n";
//         }
//         else cout << "yes" << "\n";
//     }
// }
#include <bits/stdc++.h>

using namespace std;

vector<string> answer_v;

int main()
{
    string str;
    while(true){
        stack<char> stk;
        getline(cin,str);

        if (str=="."){
            break;
        }

        for (char i:str){
            if (i==')') {
                if (stk.size()&&stk.top()=='('){
                    stk.pop();
                }
            }
            else if (i==']') {
                if (stk.size()&&stk.top()=='['){
                    stk.pop();
                }
            }
            else if (i=='('||i=='['||i==')'||i==']'){
                stk.push(i);
            }
            
        }
        if (stk.size()) answer_v.push_back("no");
        else answer_v.push_back("yes");
    }
    for (string i:answer_v) cout << i << "\n";
}