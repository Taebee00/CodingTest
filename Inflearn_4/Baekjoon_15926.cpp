#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, mx=0; char str[200001];
    stack<pair<char,int>> stk;
    int arr[200001]={0,};
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> str[i];
    }
    for (int i=0;i<n;i++){
        if (str[i]=='('){
            stk.push({'(',i});
        }
        else{
            if (!stk.empty()&&stk.top().first=='('){
                arr[stk.top().second]=1;
                arr[i]=1;
                stk.pop();
            }
        }    
    }
    for (int i=0;i<n;i++){
        int cnt=0;
        while(arr[i]==1){
            i++;
            cnt++;
        }
        if (cnt>mx){
            mx=cnt;
        }
    }
    cout << mx;
}