#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long A,B,cnt=0;
    cin >> A >> B;

    while(B!=A&&B!=0){
        //cout << B;
        if (!(B%2)){
            B=B/2;
        }
        else if(B%10==1){
            B=B/10;
        }
        else{
            break;
        }
        cnt++;
    }
    if (A==B){
        cout << cnt+1;
    }
    else{
        cout << "-1";
    }
}