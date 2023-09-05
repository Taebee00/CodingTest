#include <bits/stdc++.h>

using namespace std;

int N;
map<char,pair<int,int>> mp;

void pre(char node){
    if (node=='.'){
        return;
    }
    printf("%c",node);
    pre(mp[node].first);
    pre(mp[node].second);
}

void in(char node){
    if (node=='.'){
        return;
    }
    in(mp[node].first);
    printf("%c",node);
    in(mp[node].second);
}

void post(char node){
    if (node=='.'){
        return;
    }
    post(mp[node].first);
    post(mp[node].second);
    printf("%c",node);
}

int main()
{
    
    cin >> N;
    
    for (int i=0;i<N;i++){
        char root, left, right;
        cin >> root >> left >> right;
        mp[root]={left,right};
    }
    pre('A');
    printf("\n");
    in('A');
    printf("\n");
    post('A');
}