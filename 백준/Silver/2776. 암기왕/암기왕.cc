#include <bits/stdc++.h>

using namespace std;

bool check(int num, vector<int> &v){
    if (*lower_bound(v.begin(),v.end(),num)==num) return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC, N, M;
    cin >> TC;
    for (int i=0;i<TC;i++){
        map<int,int> mp;
        cin >> N;
        vector<int> A,B;
        for (int j=0;j<N;j++){
            int num;
            cin >> num;
            A.push_back(num);
        }
        cin >> M;
        for (int j=0;j<M;j++){
            int num;
            cin >> num;
            B.push_back(num);
        }
        sort(A.begin(),A.end());
        for (int j:B){
            if (mp.find(j)==mp.end()){
                if (check(j, A)){
                    cout << "1 ";
                    mp[j]=1;
                }
                else cout << "0 ";
            }
            else cout << "1 ";
        }
    }
}