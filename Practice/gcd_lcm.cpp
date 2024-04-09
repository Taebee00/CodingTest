#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (a==0){
        return b;
    }
    gcd(b%a, a);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main()
{
    printf("최대공약수는 %d\n",gcd (66,121));
    printf("최소공배수는 %d", lcm(66, 121));
}