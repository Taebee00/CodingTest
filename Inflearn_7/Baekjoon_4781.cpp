#include <bits/stdc++.h>

using namespace std;

int n;
float m;

int main()
{
    while(1){
        cin >> n >> m;
        if (n==0&&m==0.00) break;
        int dp[10100]={0,};
        for (int i=0;i<n;i++){
            int kal;
            float price;
            cin >> kal >> price;
            price=static_cast<int>(price*100);
            dp[int(price)]=max(dp[int(price)],kal);
            for (int j=int(price);j<=int(m*100);j++){
                dp[j]=max(dp[j-int(price)]+kal,dp[j]);
            }
        }
        cout << dp[int(m*100)] << "\n";
    }
    
}