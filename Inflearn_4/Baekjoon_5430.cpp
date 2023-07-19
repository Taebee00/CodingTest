#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int l; 
        string str, arr;
        cin >> str >> l >> arr;
        int idx=arr.length()-2;
        deque<int> v;
        while(idx>=0){
            int num=0,zeros=0,flag=0;
            while(arr[idx]!=','&&idx>0){
                num+=(arr[idx]-'0')*(int)pow(10,zeros);
                zeros++;
                idx--;
                flag=1;
            }
            if (flag){
                v.push_back(num);
            }
            else{
                idx--;
            }
        }
        int flag=0;
        int r_flag=0;
        for (auto&j:str){
            if (j=='R'){
                r_flag=r_flag==1?0:1;
            }
            if (j=='D'){
                if (v.empty()){
                    flag=1;
                    break;
                }
                else if (r_flag==0){
                    v.pop_back();
                }
                else{
                    v.pop_front();
                }
            }
        }
        if (flag){
            cout << "error" << "\n";
        }
        else{
            cout << '[';
            if (r_flag==0&&!v.empty()){
                for (int j=v.size()-1;j>0;j--){
                    cout << v[j] << ',';
                }
                cout << v[0];
            }
            else if ((r_flag==1&&!v.empty())){
                for (int j=0;j<v.size()-1;j++){
                    cout << v[j] << ',';
                }
                cout << v[v.size()-1];
            }
            cout << "]\n";
        }
    }
}