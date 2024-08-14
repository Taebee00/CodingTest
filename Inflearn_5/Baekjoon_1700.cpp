// // #include <bits/stdc++.h>

// // using namespace std;

// // int N, K, arr[100], visitied[100]={0,},cnt=0;
// // map<int,vector<int>> mp;
// // vector<int> v;

// // int main()
// // {
// //     cin >> N >> K;
// //     for (int i=0;i<K;i++){
// //         cin >> arr[i];
// //         mp[arr[i]].push_back(i);
// //     }
// //     for (int i=0;i<K;i++){
// //         if (v.size()!=N){
// //             if (!visitied[arr[i]]){
// //                 v.push_back(arr[i]);
// //                 visitied[arr[i]]=1;
// //             }
// //         }
// //         else{
// //             if (!visitied[arr[i]]){
// //                 int mx=0,mxidx;
// //                 for (int k=0;k<v.size();k++){
// //                     if (mp[v[k]].size()&&mp[v[k]][0]>mx){
// //                         mx=mp[v[k]][0];
// //                         mxidx=k;
// //                     }
// //                     else if (!mp[v[k]].size()){
// //                         mx=INT_MAX;
// //                         mxidx=k;
// //                     }
                    
// //                 }
// //                 visitied[v[mxidx]]=0;
// //                 v.erase(v.begin()+mxidx);
// //                 v.push_back(arr[i]);
// //                 visitied[arr[i]]=1;
// //                 cnt++;
// //             }
// //         }
// //         mp[arr[i]].erase(mp[arr[i]].begin());
// //     }
// //     cout << cnt;
// // }
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int N, K, answer=0, multitab[101]={0,};
//     vector<int> v, multitab_v;
//     vector<int> is, isnot;
//     cin >> N >> K;

//     for (int i=0;i<K;i++){
//         int num;
//         cin >> num;
//         v.push_back(num);
//     }

//     for (int i:v){
//         if (multitab_v.size()<=N&&!multitab[i]){
//             multitab_v.push_back(i);
//             multitab[i]=1;
//             continue;
//         }
//         if (multitab[i]&&find(is.begin(),is.end(),i)==is.end()){
//             is.push_back(i);
//         }
//         else if (!multitab[i]&&find(isnot.begin(),isnot.end(),i)==isnot.end()){
//             isnot.push_back(i);
//         }
//         if (is.size()+isnot.size()==N){
//             for (int j:multitab_v) multitab[j]=0;
//             multitab_v.clear();
//             for (int j:is){
//                 multitab[j]=1;
//                 multitab_v.push_back(j);
//             }
//             for (int j:isnot){
//                 multitab[j]=1;
//                 multitab_v.push_back(j);
//                 answer++;
//             }
//             is.clear(); isnot.clear(); 
//         }
//     }
//     answer+=isnot.size();
//     cout << answer;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K, answer=0;
    vector<int> v;
    vector<int> multitap_v;
    
    cin >> N >> K;

    for (int i=0;i<K;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i=0;i<v.size();i++){
        if (find(multitap_v.begin(),multitap_v.end(),v[i])!=multitap_v.end()) continue;
        if (multitap_v.size()<N){
            multitap_v.push_back(v[i]);
            continue;
        }
        answer++;
        int mx=i;
        int mx_num;
        for (int j:multitap_v){
            int idx=i;
            while(idx<v.size()&&v[idx]!=j){
                idx++;
            }
            if (idx>=mx){
                mx=idx;
                mx_num=j;
            }
        }
        auto idx=find(multitap_v.begin(),multitap_v.end(),mx_num);
        multitap_v.erase(idx);
        multitap_v.insert(idx,v[i]);
    }
    cout << answer;
}
