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

<<<<<<< HEAD
int main()
{
    string str;
    vector<string> answer_v;

    while(1){
        stack<char> stk;
        int flag=0;
=======
vector<string> answer_v;

int main()
{
    string str;
    while(true){
        stack<char> stk;
>>>>>>> e9449467462260dbff67b2fe6c00e70c4ce6f863
        getline(cin,str);

        if (str=="."){
            break;
        }

        for (char i:str){
<<<<<<< HEAD
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
=======
            if (i==')') {
                if (stk.size()&&stk.top()=='('){
                    stk.pop();
                }
>>>>>>> e9449467462260dbff67b2fe6c00e70c4ce6f863
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
<<<<<<< HEAD
        if (stk.size()) flag=1;

        if (flag) answer_v.push_back("no");
=======
        if (stk.size()) answer_v.push_back("no");
>>>>>>> e9449467462260dbff67b2fe6c00e70c4ce6f863
        else answer_v.push_back("yes");
    }
    for (string i:answer_v) cout << i << "\n";
}