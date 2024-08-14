#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, mx=INT_MIN, sum=0;
    vector<int> v;

    cin >> N;

    for (int i=0;i<N;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i:v){
        sum+=i;
        mx=max(mx,sum);
        if (sum<0) sum=0;
    }

    cout << mx;
}