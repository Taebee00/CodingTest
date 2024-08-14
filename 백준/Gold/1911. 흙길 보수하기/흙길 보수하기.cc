// #include <bits/stdc++.h>

// using namespace std;

// int N,L,first,last;
// vector<pair<int,int>> v;

// int main(){
    
//     cin >> N >> L;
//     for (int i=0;i<N;i++){
//         int start;
//         int end;
//         cin >> start >> end;
//         v.push_back({start,end});
//     }
//     sort(v.begin(),v.end());
//     int cnt=0, temp=v[0].first;
//     for (auto&i:v){
//         if (temp<i.first){
//             temp=i.first;
//         }
//         while(temp<i.second){
//             temp+=L;
//             cnt++;
//         }
//     }
//     cout << cnt;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, L;
    vector<pair<int,int>> v;

    cin >> N >> L;

    for (int i=0;i<N;i++){
        int start, end;
        cin >> start >> end;
        v.push_back({start,end});
    }

    sort(v.begin(),v.end());

    int idx=-1, cnt=0;
    for (auto i:v){
        if (idx>=i.second) continue;
        if (idx<=i.first){
            int temp=i.first;
            while(temp<i.second){
                temp+=L;
                cnt++;
            }
            idx=temp;
        }
        if (idx>i.first){
            int temp=idx;
            while(temp<i.second){
                temp+=L;
                cnt++;
            }
            idx=temp;
        }
    }
    cout << cnt;
}