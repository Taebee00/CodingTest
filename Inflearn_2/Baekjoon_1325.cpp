// #include <bits/stdc++.h>
// using namespace std;

// int com_1, com_2, com_num, trust_num, ret=0, mx=0, visitied[10001]={0,};
// vector<int> v[10001]; vector<int> max_v;

// void init(){
//     for (int i=0;i<=com_num;i++){
//         visitied[i]=0;
//     }
//     ret=0;
// }

// void dfs(int i){
//     ret++;
//     visitied[i]=1;
//     if (v[i].size()){
//         for (auto&j:v[i]){
//             if (!visitied[j]){
//                 dfs(j);
//             }
//         }
//     }
// }

// int main(){
//     cin >> com_num >> trust_num;
//     for (int i=0;i<trust_num;i++){
//         cin >> com_1 >> com_2;
//         v[com_2].push_back(com_1);
//     }
//     for (int i=0;i<=com_num;i++){
//         dfs(i);
//         if (ret>mx){
//             mx=ret;
//             max_v.clear();
//             max_v.push_back(i);
//         }
//         else if (ret==mx){
//             max_v.push_back(i);
//         }
//         init();
//     }
//     sort(max_v.begin(),max_v.end());
//     for (auto&i:max_v){
//         cout << i << " ";
//     }
// }
#include <bits/stdc++.h>

using namespace std;

int N, M, visitied[10001]={0,};
vector<int> vec_arr[10001];
vector<pair<int,int>> answer_v;

int dfs(int num){
    visitied[num]=1;
    int sum=1;
    for (int i:vec_arr[num]){
        if (!visitied[i]) sum+=dfs(i); 
    }
    return sum;
}

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main()
{
    cin >> N >> M;

    for (int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        vec_arr[b].push_back(a);
    }

    for (int i=1;i<=N;i++){
        fill(&visitied[0],&visitied[0]+N+1,0);
        int val=dfs(i)-1;
        if (answer_v.size()){
            if (answer_v[0].second<val){
                answer_v.clear();
                answer_v.push_back({i,val});
            }
            else if (answer_v[0].second==val){
                answer_v.push_back({i,val});
            }
        }
        else{
            answer_v.push_back({i,val});
        }
    }

    sort(answer_v.begin(),answer_v.end(),cmp);

    for (auto i:answer_v) cout << i.first << " ";
}