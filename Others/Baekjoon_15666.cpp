#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v,per_v;
vector<vector<int>> arr_v;

void choose(int sz,int choice){
    if (sz==M){
        int flag=0;
        if (arr_v.size()){
            for (auto &i:arr_v){
                if (i==per_v){
                    flag=1;
                    break;
                }
            }
        }
        if (!flag){
             for (int &i:per_v){
                printf("%d ",i);
            }
            arr_v.push_back(per_v);
            printf("\n");
        }
        return;
    }
    for (int i=choice;i<N;i++){
        per_v.push_back(v[i]);
        choose(sz+1,i);
        per_v.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    choose(0,0);
}