#include <bits/stdc++.h>

using namespace std;

int N,M,cnt=0;
vector<int> A(N);
vector<int> B(M);

void find(int num){
    int temp=int(lower_bound(B.begin(),B.end(),num)-B.begin());
    if (temp<M&&B[temp]==num){
        cnt++;
    }
}

int main()
{
    cin >> N >> M;
    
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for (int i=0;i<M;i++){
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
    sort(B.begin(),B.end());
    for (int i=0;i<A.size();i++){
        find(A[i]);
    }
    cout << N+M-2*cnt;

}