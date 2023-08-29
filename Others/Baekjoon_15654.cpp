#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> choice_v,v;
int visitied[8]={0,};

void per(int sz,int choice){
    // printf("%d %d\n",sz,choice);
    // for (int &i:choice_v){
    //     printf("%d ",i);
    // }
    // printf("\n");
    if (sz==M){
        for (int &i:choice_v){
            printf("%d ",i);
        }
        printf("\n");
        return;
    }
    for (int i=0;i<N;i++){
        if (!visitied[i]){
            choice_v.push_back(v[i]);
            visitied[i]=1;
            per(sz+1,i);
            choice_v.pop_back();
            visitied[i]=0;
        }
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
    per(0,-1);
}