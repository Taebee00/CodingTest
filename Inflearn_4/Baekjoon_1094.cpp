#include <bits/stdc++.h>

using namespace std;

int main()
{
    int goalL, initL=64;
    vector<int> v;
    cin >> goalL;
    v.push_back(64);
    if (goalL==64){
        cout << 1;
        return 0;
    }
    while(1){
        int half=v.back()/2;
        v.pop_back();
        v.push_back(half);
        v.push_back(half);
        int sum=0;
        for (auto i=v.begin();i!=v.end()-1;i++){
            sum+=*i;
        }
        if (sum==goalL){
            cout << v.size()-1;
            break;
        }
        if (sum>goalL){
            v.pop_back();
        }
    }
}