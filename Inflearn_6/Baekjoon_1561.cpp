#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    if (a.second>b.second){
        return true;
    }
    else if (a.second==b.second){
        return a.first < b.first;
    }
    else{
        return false;
    }
}

int main()
{
    int N,M;
    vector<int> v;
    cin >> N >> M;
    for (int i=0;i<M;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    long long low=1, high=INT_MAX,tm=0;
    while(low<=high){
        long long mid=(low+high)/2;
        long long cnt=0;
        for (int &i:v){
            cnt+=mid/i+1;
        }
        if (cnt>=N){
            high=mid-1;
            tm=mid;
        }
        else{
            low=mid+1;
        }
    }
    int mn=tm-(tm%v[0]);
    int cnt=0;
    for (int& i:v){
        cnt+=tm/i;
        if (tm-(tm%i)<mn){
            mn=tm-(tm%i);
        }
    }
    cout << tm << " " << cnt << " " << mn << "\n";
    for (int i=mn;i<=tm;i++){
        for (int j=0;j<M;j++){
            if (i%v[j]==0){
                cout << i << " " << j+1 << "\n";
                cnt++;
            }
            
            if (cnt==N){
                cout << j+1;
                return 0;
            }
        }
    }
}