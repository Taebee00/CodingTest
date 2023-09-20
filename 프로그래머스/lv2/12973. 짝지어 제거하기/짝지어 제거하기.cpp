#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    for (char i:s){
        if (!stk.size()||stk.top()!=i){
            stk.push(i);
        }
        else if (stk.top()==i){
            stk.pop();
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    return answer=stk.empty();
}