#include <bits/stdc++.h>

using namespace std;

int n,k,arr[101],dp[10001],DAT[10001]={0,};
set<int> st;

int main()
{  
    cin >> n >> k;

    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        st.insert(temp);
    }

    dp[0]=1;
    for (int i:st){
        for (int j=0;j<=k;j++){
            if (j-i<0) continue;
            dp[j]=dp[j]+dp[j-i];
        }
    }
    cout << dp[k];
}