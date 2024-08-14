#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;

    cin >> tc;

    for (int i=0;i<tc;i++){
        int N, arr[8][8];
        vector<int> v[8];
        cin >> N;
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                cin >> arr[j][k];
            }
        }
        for (int j=0;j<N;j++){
            for (int k=N-1;k>=0;k--){
                v[j].push_back(arr[k][j]);
            }
        }
        for (int j=N-1;j>=0;j--){
            for (int k=N-1;k>=0;k--){
                v[N-1-j].push_back(arr[j][k]);
            }
        }
        for (int j=N-1;j>=0;j--){
            for (int k=0;k<N;k++){
                v[N-1-j].push_back(arr[k][j]);
            }
        }
        printf("#%d\n",i+1);
        for (int j=0;j<N;j++){
            for (int k=0;k<3*N;k++){
                cout << v[j][k];
                if ((k+1)%N==0) cout << " ";
            }
            cout << "\n";
        }
    }
}