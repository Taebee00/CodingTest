#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int temp=min(a,b);
    b=max(a,b);
    a=temp;
    while(1){
        if (a%2==1&&a+1==b){
            break;
        }
        a=a%2==0?a/2:(a+1)/2;
        b=b%2==0?b/2:(b+1)/2;
        answer++; 
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;
    return answer;
}