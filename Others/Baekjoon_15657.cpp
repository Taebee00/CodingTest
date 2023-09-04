#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> v,choice_v;

void choose(int lim,int sz,int choice){
    if (sz==lim){
        for (int i:choice_v){
            printf("%d ",i);
        }
        printf("\n");
        return;
    }
    for (int i=choice;i<N;i++){
        choice_v.push_back(v[i]);
        choose(lim,sz+1,i);
        choice_v.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    choose(M,0,0);
}