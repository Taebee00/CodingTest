#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X;

    cin >> X;
    
    int num, cnt=0;
    for (int i=0;i<=6;i++){
        if (X&(1<<i)) cnt++;
    }

    cout << cnt;
}