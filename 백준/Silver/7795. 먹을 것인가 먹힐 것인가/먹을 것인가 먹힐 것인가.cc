#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    
    cin >> TC;

    for (int i=0;i<TC;i++){
        vector<int> A, B;
        int N, M, temp, answer=0;
        cin >> N >> M;
        for (int j=0;j<N;j++){
            cin >> temp;
            A.push_back(temp);
        }
        for (int j=0;j<M;j++){
            cin >> temp;
            B.push_back(temp);
        }
        sort(B.begin(),B.end());
        for (int j:A){
            //cout << j << "-------\n";
            answer+=lower_bound(B.begin(),B.end(),j)-B.begin();
        }
        cout << answer << "\n";
    }
}