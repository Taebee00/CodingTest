#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;

void per(int sz,int choice){
    if (sz==M){
        for (int &i:v){
            printf("%d ",i);
        }
        printf("\n");
        return;
    }
    for (int i=choice;i<=N;i++){
        v.push_back(i);
        per(sz+1,i);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    per(0,1);
}