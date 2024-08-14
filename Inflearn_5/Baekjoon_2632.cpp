#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sz, A, B, temp;
    int A_arr[2000], B_arr[2000], Asum_arr[2000]={0,}, Bsum_arr[2000]={0,};
    
    cin >> sz >> A >> B;
    for (int i=1;i<=A;i++){
        cin >> A_arr[i];
        Asum_arr[i]=Asum_arr[i-1]+A_arr[i];
    }
    for (int i=1;i<=B;i++){
        cin >> B_arr[i];
        Bsum_arr[i]=Bsum_arr[i-1]+B_arr[i];
    }

}