#include <bits/stdc++.h>

using namespace std;

int N,M,ret=INT_MAX;
vector<int> v,choose_v;

void choose(int sz){
    //cout << sz;
    if (sz==6){
        int sum=choose_v[0];
        for (int i=1;i<6;i++){
            sum=sum*10+choose_v[i];
        }
        int cnt=0;
        int temp_sum=sum;
        do{
            temp_sum/=10;
            cnt++;
        }while(temp_sum!=0);
        if (abs(sum-N)+cnt<ret){
            ret=abs(sum-N)+cnt;
        }
        return;
    }
    for (int i=0;i<v.size();i++){
        choose_v.push_back(v[i]);
        choose(sz+1);
        choose_v.pop_back();
    }
}

int main()
{
    for (int i=0;i<=9;i++){
        v.push_back(i);
    }
    cin >> N >> M;
    for (int i=0;i<M;i++){
        int temp;
        cin >> temp;
        v.erase(find(v.begin(),v.end(),temp));
    }
    choose(0);
    if (abs(100-N)<ret){
        ret=abs(100-N);
    }
    cout << ret;
}