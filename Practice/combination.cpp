#include <bits/stdc++.h>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};
vector<int> v;

void combination(int n, int r, int depth){
    if (v.size() == r){
        for (auto i : v){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = depth + 1 ; i < n ; i++){
        v.push_back(a[i]);
        combination(n, r, i);
        v.pop_back();
    }
}

int main()
{
    combination(5 ,3 ,-1);
}