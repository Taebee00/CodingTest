#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main()
{
    for (int i =1; i<=5 ;i++){
        v.push_back(i);
        v.push_back(i);
    }
    for (int i =1; i<=5 ;i++){
        cout << v[i] << " ";
    }
    cout << "\n";

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for (int i =1; i<=5 ;i++){
        cout << v[i] << " ";
    }
}