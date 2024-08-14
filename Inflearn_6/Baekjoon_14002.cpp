// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int N,ret=1,lastidx=0;
//     cin >> N;
//     vector<int> v;
//     int cnt[1001];
//     int way[1001];
//     fill(cnt,cnt+1001,1);
//     fill(way,way+1001,-1);
//     for (int i=0;i<N;i++){
//         int temp;
//         cin >> temp;
//         v.push_back(temp);
//     }
//     for (int i=1;i<N;i++){
//         int mx=1;
//         for (int j=0;j<i;j++){
//             if (v[j]<v[i]&&cnt[j]>=mx){
//                 mx=cnt[j];
//                 cnt[i]=mx+1;
//                 way[i]=j;
//             }
//         }
//         if (ret<cnt[i]){
//             ret=cnt[i];
//             lastidx=i;
//         }
//     }
//     printf("%d\n",ret);
//     int idx=lastidx;
//     vector<int> ret_v;
//     while(idx!=-1){
//         ret_v.push_back(v[idx]);
//         idx=way[idx];
//     }
//     for (int i=ret-1;i>=0;i--){
//         printf("%d ",ret_v[i]);
//     }
// }

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, mx=1, path[1001], mxidx=0;
    vector<pair<int,int>> v;
    vector<int> answer_v;
    cin >> N;
    fill(path,path+1001,-1);
    for (int i=0;i<N;i++){
        int num, cnt=1;
        cin >> num;
        for (int j=0;j<i;j++){
            if (v[j].first<num){
                if (v[j].second+1>cnt){
                    cnt=v[j].second+1;
                    path[i]=j;
                }
                if (cnt>mx){
                    mx=cnt;
                    mxidx=i;
                }
            }
        }
        v.push_back({num,cnt});
    }
    cout << mx << "\n";
    for (int i=mxidx;i!=-1;i=path[i]){
        answer_v.push_back(v[i].first);
    }
    for (auto i=answer_v.rbegin();i<answer_v.rend();i++){
        cout << *i << " ";
    }
}   