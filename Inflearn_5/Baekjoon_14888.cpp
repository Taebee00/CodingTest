#include <bits/stdc++.h>

using namespace std;

int N,num[11],mn=INT_MAX,mx=INT_MIN;
vector<int> v;

int cal(){
    int ret=num[0];
    for (int i=1;i<N;i++){
        if (v[i-1]==0){
            ret+=num[i];
        }
        else if (v[i-1]==1){
            ret-=num[i];
        }
        else if (v[i-1]==2){
            ret*=num[i];
        }
        else{
            ret/=num[i];
        }
    }
    return ret;
}

void permutate(int sz,int depth){
    if (depth==sz){
        // for (auto&i:v){
        //     printf("%d ",i);
        // }
        // printf("\n");
        mx=max(mx,cal());
        mn=min(mn,cal());
        return;
    }
    for (int i=depth;i<sz;i++){
        swap(v[depth],v[i]);
        permutate(sz,depth+1);
        swap(v[depth],v[i]);
    }
}

int main(){
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> num[i];
    }
    for (int i=0;i<4;i++){
        int temp;
        cin >> temp;
        for (int j=0;j<temp;j++){
            v.push_back(i);
        }
    }
    permutate(v.size(),0);
    cout << mx << "\n" << mn;
}