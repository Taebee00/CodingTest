#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    int sz=A.length()>B.length()?A.length():B.length();
    string small=A.length()<B.length()?A:B;
    string big=A.length()<B.length()?B:A;
    int diff=big.length()-small.length();
    deque<int> dq;
    int flag=0;
    for (int i=sz-1;i>=0;i--){
        int num;
        if (i>=diff){
            num=flag?big[i]-'0'+small[i-diff]-'0'+1:big[i]-'0'+small[i-diff]-'0';
        }
        else{
            num=flag?big[i]-'0'+1:big[i]-'0';
        }
        if (num>=10){
            dq.push_front(num-10);
            flag=1;
        }
        else{
            dq.push_front(num);
            flag=0;
        }
    }
    if (flag){
        dq.push_front(1);
    }
    for (auto&i:dq){
        cout << i;
    }
}