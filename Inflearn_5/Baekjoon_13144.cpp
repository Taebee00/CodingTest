#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, cnt=0, arr[100001], visitied[100001]={0,};
    cin >> N;
    int last=1;
    for (int i=1;i<=N;i++){
        cin >> arr[i];
        if (!visitied[arr[i]]){
            
        }
        visitied[arr[i]]=i;

    }

    cout << cnt;
}