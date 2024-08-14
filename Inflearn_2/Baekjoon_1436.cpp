#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, cnt=0;

    cin >> N;

    for (int i=666;;i++){
        int six=0;
        int num=i;
        while(num!=0){
            if (num%10==6){
                six++;
            }
            else{
                six=0;
            }
            if (six==3){
                cnt++;
            }
            if (cnt==N){
                cout << i;
                return 0;
            }
            num/=10;
        }
    }
}