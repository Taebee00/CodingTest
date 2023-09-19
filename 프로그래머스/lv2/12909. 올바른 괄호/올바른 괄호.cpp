#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    bool answer = true;
    for (auto &i:s){
        if (stk.empty()||i=='('||stk.top()==i){
            stk.push(i);
        }
        else{
            stk.pop();
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return stk.empty();
}