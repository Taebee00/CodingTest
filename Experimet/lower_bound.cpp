#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main () {
for(int i = 1; i <= 5; i++){
v.push_back(i);
v.push_back(i);
}
for(int i = 5; i >= 1; i--){
v.push_back(i);
v.push_back(i);
}
//sort(v.begin(), v.end());
auto it=unique(v.begin(), v.end());
for(int i : v) cout << i << " ";

cout << '\n';
v.erase(unique(it, v.end()));
for(int i : v) cout << i << " ";
return 0;
}
