#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, x, rp, answer=0;
    vector<int> v;

    cin >> N;
    for (int i=0;i<N;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> x;
    sort(v.begin(),v.end());
    rp=N-1;
    for (int i=0;i<N;i++){
        while(v[i]+v[rp]>x&&rp>i){
            rp--;
        }
        if (v[i]+v[rp]==x&&i<rp) answer++;
    }
    cout << answer;
}