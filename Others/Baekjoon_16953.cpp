#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A,B,cnt=0;
    cin >> A >> B;

    while(B!=A&&B!=0){
        //cout << B;
        if (!(B%2)){
            B=B/2;
        }
        else{
            B=B/10;
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