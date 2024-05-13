#include <bits/stdc++.h>

using namespace std;

int N, mx=INT_MIN, mn=INT_MAX, cal_arr[4]={0,};
vector<int> num_v;
vector<int> cal_v;

int cal(int num,int idx){
    if (cal_v[idx-1]==0) return num+num_v[idx];
    else if (cal_v[idx-1]==1) return num-num_v[idx];
    else if (cal_v[idx-1]==2) return num*num_v[idx];
    else if (cal_v[idx-1]==3) return num/num_v[idx];
}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        num_v.push_back(temp);
    }
    for (int i=0;i<4;i++){
        int temp;
        cin >> temp;
        for (int j=0;j<temp;j++){
            cal_v.push_back(i);
        }
    }
    do{
        int temp_ret=num_v[0];
        for (int i=0;i<cal_v.size();i++){
            temp_ret=cal(temp_ret,i+1);
        }
        mx=max(temp_ret,mx);
        mn=min(temp_ret,mn);
    }while(next_permutation(cal_v.begin(),cal_v.end()));

    cout << mx << "\n" << mn;
}