#include <bits/stdc++.h>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};
vector<int> v;

void makePermutation(int n, int r, int depth){
    if (depth == r){
        for (int i = 0; i < 3 ; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    for (int i = depth ; i < n ; i++){
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
}

int main()
{
    for (int i = 0; i < 5; i++){
        v.push_back(a[i]);
    }
    makePermutation(5, 3, 0);
}