#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, arr[20][20], answer=INT_MAX;
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<(1<<N);i++){
        int cnt=0;
        vector<int> a_v, b_v;
        for (int j=0;j<N;j++){
            if (i&(1<<j)) a_v.push_back(j);
            else b_v.push_back(j);
        }
        if (a_v.size()==N/2){
            int a_sum=0, b_sum=0;
            for (int j=0;j<N/2;j++){
                for (int k=0;k<N/2;k++){
                    a_sum+=arr[a_v[j]][a_v[k]];
                }
            }
            for (int j=0;j<N/2;j++){
                for (int k=0;k<N/2;k++){
                    b_sum+=arr[b_v[j]][b_v[k]];
                }
            }
            answer=min(answer,abs(a_sum-b_sum));
        }
    }
    cout << answer;
}